#ifndef CTDDCOMPLEXTABLE_HPP
#define CTDDCOMPLEXTABLE_HPP

#include "Complex.hpp"
#include "Definitions.hpp"

class ComplexTable {

public:
    // Construction
    ComplexTable() {}
    ComplexTable(std::size_t Nbucket) {
        NBUCKET = Nbucket;
        MASK = NBUCKET - 1;
        table.resize(NBUCKET);
        n_nodes = 0;
        add_all_basic_numbers();
    }

    // Clear everything
    void clear() {
        releaseTables();
    }

    // Finds in the complex table the object with the value searched. If not found, then adds a new one.
    Complex* Find_Or_Add(std::complex<dataType> value) {
        if (value == value_one->getOriginalValue()) {
            return value_one;
        }
        std::size_t hashVal = hash(value);
        Complex* complex = searchTable(hashVal, value);
        if (complex == nullptr) {
            complex = create_new_node(value);
            complex->next = table[hashVal];
            table[hashVal] = complex;
            n_nodes++;
        }
        return complex;
    }

    // Creates a new object that represents the complex number given.
    Complex* create_new_node(std::complex<dataType> value) {
        return new Complex(value);
    }

    long getTotalNodes() {
        return n_nodes;
    }

    static void Init_Complex_Unique_Table(std::size_t Nbucket) noexcept;


private:

    // Definition of the hashing function for complex numbers
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

    // Search for a given complex value if there is an object in the table that represents it.
    Complex* searchTable(const std::size_t& hashVal, std::complex<dataType> value) {
        Complex* find_complex = nullptr;
        Complex* complex = table[hashVal];
        while (complex != nullptr) {
            if (complex != nullptr && complex->getValue() == value) {
                find_complex = complex;
                break;
            }
            complex = complex->next;
        }
        return find_complex;
    }

    // Add an already created object representing a complex
    void Add_Basic_Numbers(Complex* number) {
        std::size_t hashVal = hash(number->getOriginalValue());
        number->next = table[hashVal];
        table[hashVal] = number;
        n_nodes++;
    }

    void add_all_basic_numbers() {
        Add_Basic_Numbers(value_one);
        Add_Basic_Numbers(value_zero);
    }

    // Release memory of the tables
    void releaseTables() {
        for (auto& bucket: table) { // a bucket in the table
            // Release bucket
            Complex* current = bucket;
            while (current) {
                Complex* temp = current;
                current = current->next;
                if (!(temp->getOriginalValue() == value_one->getOriginalValue() ||
                      temp->getOriginalValue() == value_zero->getOriginalValue())) {
                    delete temp;
                }
            }
            bucket = nullptr;
        }
        n_nodes = 0;
        if (NBUCKET > 0) {
            add_all_basic_numbers();
        }
    }

    // Parameters of the table
    std::size_t NBUCKET;
    std::vector<Complex*> table{std::vector<Complex*>(0)};
    std::size_t MASK;
    long n_nodes = 0;

};

// Declare the global complex table
extern ComplexTable complex_table;

#endif
