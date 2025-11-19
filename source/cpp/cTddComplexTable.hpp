#ifndef CTDDCOMPLEXTABLE_HPP
#define CTDDCOMPLEXTABLE_HPP

#include "Complex.hpp"

class ComplexTable {

public:
    /*
        Construction/Destruction related functions
    */
    // Construction
    ComplexTable() {}
    ComplexTable(std::size_t Nbucket) {
        NBUCKET = Nbucket;
        MASK = NBUCKET - 1;
        table.resize(NBUCKET);
        Add_Basic_Numbers(value_one);
        Add_Basic_Numbers(value_zero);
    }

    // Clear everything
    void clear() {

    }

    Complex* Find_Or_Add(std::complex<dataType> value) {
        if (value == value_one->value) {
            return value_one;
        }
        std::size_t hashVal = hash(value);
        Complex* complex = searchTable(hashVal, value);
        if (complex == nullptr) {
            complex = create_new_node(value);
            complex->next = table[hashVal];
            table[hashVal] = complex;
        }
        return complex;
    }

    Complex* create_new_node(std::complex<dataType> value) {
        return new Complex(value);
    }


private:

    std::size_t hash(std::complex<dataType> value) {
        hashType hash = fnv_offset_basis;

        // hash the real part
        hash = hash ^ static_cast<hashType>(value.real());
        hash = hash * fnv_prime;

        // hash the imaginary part
        hash = hash ^ static_cast<hashType>(value.imag());
        hash = hash * fnv_prime;

        return static_cast<std::size_t>(hash & MASK);
    }

    Complex* searchTable(const std::size_t& hashVal, std::complex<dataType> value) {
        Complex* find_complex = nullptr;
        Complex* complex = table[hashVal];
        while (complex != nullptr) {
            if (complex != nullptr && complex->value == value) {
                find_complex = complex;
                break;
            }
            complex = complex->next;
        }
        return find_complex;
    }

    void Add_Basic_Numbers(Complex* number) {
        std::size_t hashVal = hash(number->value);
        number->next = table[hashVal];
        table[hashVal] = number;
    }

    // Parameters of the table
    std::size_t NBUCKET;
    std::vector<Complex*> table{std::vector<Complex*>(0)};
    std::size_t MASK;

};

// Declare the global complex table
ComplexTable complex_table;

#endif
