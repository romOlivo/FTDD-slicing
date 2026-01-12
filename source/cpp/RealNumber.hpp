#ifndef CTDDREALNUMBER_HPP
#define CTDDREALNUMBER_HPP

#include "Definitions.hpp"

class alignas(2) RealNumber {

public:
    /*
        Construction/Destruction related functions
    */
    // Construction
    RealNumber() {
        setVal(0);
    }

    RealNumber(double newValue) {
        setVal(newValue);
    }

    inline double getValue() {
        return value;
    }

    void setVal(double newValue) {
        value = std::abs(newValue);
    }

    void setValUnsafe(double newValue) {
        value = newValue;
    }

    static RealNumber* setValue(RealNumber* rn, double value) {
        rn->setVal(value);
        if (value < 0) {
            rn = setNegativePointer(rn);
        }
        return rn;
    }

    static double getValue(RealNumber* rn) {
        assert(rn != nullptr);
        if (isRealNumberNegative(rn)) {
            rn = getNegativePointer(rn);
            return -rn->getValue();
        }
        return rn->getValue();
    }

    static bool isRealNumberNegative(RealNumber* rn) {
        return (reinterpret_cast<uintptr_t>(rn) & 1) != 0;
    }

    static RealNumber* setNegativePointer(RealNumber* rn) {
        return reinterpret_cast<RealNumber*>(
             reinterpret_cast<uintptr_t>(rn) | 1
         );
    }

    static RealNumber* getNegativePointer(RealNumber* rn) {
        return reinterpret_cast<RealNumber*>(
             reinterpret_cast<uintptr_t>(rn) & ~uintptr_t(1)
         );
    }

    RealNumber* next;

private:
    double value;

};

#endif
