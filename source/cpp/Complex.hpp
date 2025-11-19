#ifndef CTDDCOMPLEX_HPP
#define CTDDCOMPLEX_HPP

class Complex {

public:
    /*
        Construction/Destruction related functions
    */
    // Construction
    Complex() {}
    Complex(std::complex<dataType> new_value) {
        value = new_value;
    }

    Complex* operator/(Complex b) {
        return new Complex(value / b.value);
    }

    std::complex<dataType> value;
    Complex* next;

};

// Declare some common complex numbers
Complex* value_zero = new Complex(0);
Complex* value_one = new Complex(1);

#endif