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
        setValue(new_value);
    }

    void setValue(std::complex<dataType> new_value) {
        value_real = real_number_unique_table.find_or_add(new_value.real());
        value_imaginary = real_number_unique_table.find_or_add(new_value.imag());
    }

    Complex* operator/(Complex b) {
        return new Complex(getValue() / b.getValue());
    }
/*
    inline bool operator==(const Complex& other) noexcept {
        return value_real == other.getRealValue() && value_imaginary == other.getImaginaryValue();
    }
*/
    std::complex<dataType> getValue() {
        return std::complex<dataType>(RealNumber::getValue(value_real), RealNumber::getValue(value_imaginary));
    }

    std::complex<dataType> getOriginalValue() {
        return getValue();
    }

    inline void setFullRealValue(RealNumber* new_value_real, RealNumber* new_value_imaginary) noexcept {
        value_real = new_value_real;
        value_imaginary = new_value_imaginary;
    }

    RealNumber* getRealValue() const noexcept {
        return value_real;
    }

    void setImaginaryValue(RealNumber* new_value_imaginary) {
        value_imaginary = new_value_imaginary;
    }

    RealNumber* getImaginaryValue() const noexcept {
        return value_imaginary;
    }

    void setRealValue(RealNumber* new_value_real) {
        value_real = new_value_real;
    }

    static std::complex<dataType> getValue(Complex* c) {
        return c->getValue();
    }

    Complex* next;

private:
    RealNumber* value_real;
    RealNumber* value_imaginary;
};

// Declare some common complex numbers
extern Complex* value_zero;
extern Complex* value_one;

#endif