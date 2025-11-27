#ifndef CTDDCOMPLEX_HPP
#define CTDDCOMPLEX_HPP

#include "RealNumberUniqueTable.hpp"
#include "RealNumber.hpp"

class Complex {

public:
    /*
        Construction/Destruction related functions
    */
    // Construction
    Complex() {}
    Complex(std::complex<dataType> new_value) {
        value_real = real_number_unique_table.find_or_add(new_value.real());
        value_imaginary = real_number_unique_table.find_or_add(new_value.imag());
    }

    Complex* operator/(Complex b) {
        return new Complex(getValue() / b.getValue());
    }

    std::complex<dataType> getValue() {
        return std::complex<dataType>(RealNumber::getValue(value_real), RealNumber::getValue(value_imaginary));
    }

    std::complex<dataType> getOriginalValue() {
        return getValue();
    }

    Complex* next;

private:
    RealNumber* value_real;
    RealNumber* value_imaginary;
};

// Declare some common complex numbers
Complex* value_zero = new Complex(0);
Complex* value_one = new Complex(1);

#endif