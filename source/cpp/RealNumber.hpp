#ifndef CTDDREALNUMBER_HPP
#define CTDDREALNUMBER_HPP

#include "Definitions.hpp"

class RealNumber {

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

    inline double getValue() const noexcept {
        return value;
    }

    inline void setVal(double newValue) noexcept {
        value = (newValue < 0) ? -newValue : newValue;
    }

    inline void setValUnsafe(double newValue) noexcept {
        value = newValue;
    }

    static inline RealNumber* setValue(RealNumber* rn, double newValue) noexcept {
        const bool neg = newValue < 0.0;
        rn->value = neg ? -newValue : newValue;
        if (neg) {
            rn = reinterpret_cast<RealNumber*>(
                reinterpret_cast<uintptr_t>(rn) | 1ULL
            );
        }
        return rn;
    }

    static inline double getValue(const RealNumber* rn) noexcept {
        uintptr_t addr = reinterpret_cast<uintptr_t>(rn);
        const bool neg = addr & 1ULL;
        rn = reinterpret_cast<const RealNumber*>(addr & ~1ULL);
        const double val = rn->value;
        return neg ? -val : val;
    }

    static inline bool isRealNumberNegative(RealNumber* rn) noexcept {
        return reinterpret_cast<uintptr_t>(rn) & 1ULL;
    }

    static inline RealNumber* setNegativePointer(RealNumber* rn) noexcept {
        return reinterpret_cast<RealNumber*>(reinterpret_cast<uintptr_t>(rn) | 1ULL);
    }

    static inline RealNumber* getNegativePointer(RealNumber* rn) noexcept {
        return reinterpret_cast<RealNumber*>(reinterpret_cast<uintptr_t>(rn) & ~1ULL);
    }

    RealNumber* next;

private:
    double value;

};

#endif
