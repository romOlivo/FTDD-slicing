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
    }

    // Clear everything
    void clear() {

    }

    Complex* Find_Or_Add(std::complex<dataType> value) {
        Complex* complex = new Complex(value);
        return complex;
    }


private:
    // Parameters of the table
    std::size_t NBUCKET;
    std::vector<Complex> table{std::vector<Complex>(0)};
    std::size_t MASK;

};

// Declare the global unique table here
ComplexTable complex_table;

#endif
