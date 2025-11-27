#ifndef CTDDREALNUMBER_HPP
#define CTDDREALNUMBER_HPP

class RealNumber {

public:
    /*
        Construction/Destruction related functions
    */
    // Construction
    RealNumber(double newValue) {
        value = newValue;
    }

    double getValue() {
        return value;
    }

    static double getValue(RealNumber* rn) {
        assert(rn != nullptr);
        return rn->getValue();
    }

private:
    double value;

};

#endif
