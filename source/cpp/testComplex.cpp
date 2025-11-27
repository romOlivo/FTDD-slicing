#include <catch2/catch_test_macros.hpp>

#include "RealNumberUniqueTable.cpp"
#include "Definitions.hpp"
#include "Complex.hpp"

TEST_CASE("Complex - getValue different ++", "[cpx_gVd++]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    std::complex<dataType> value(1, 2);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue different +-", "[cpx_gVd+-]") {
    std::complex<dataType> value(1, -2);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue different -+", "[cpx_gVd-+]") {
    std::complex<dataType> value(-1, 2);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue different --", "[cpx_gVd--]") {
    std::complex<dataType> value(-1, -2);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue equal ++", "[cpx_gVe++]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    std::complex<dataType> value(1, 1);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue equal +-", "[cpx_gVe+-]") {
    std::complex<dataType> value(1, -1);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue equal -+", "[cpx_gVe-+]") {
    std::complex<dataType> value(-1, 1);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue equal --", "[cpx_gVe--]") {
    std::complex<dataType> value(-1, -1);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue 2 equal ++++", "[cpx_2gVe++++]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    std::complex<dataType> value(1, 2);
    std::complex<dataType> value2(1, 2);
    Complex c = Complex(value);
    Complex c2 = Complex(value2);
    REQUIRE(value == c.getValue());
    REQUIRE(value2 == c2.getValue());
}

TEST_CASE("Complex - getValue 2 equal +--+", "[cpx_2gVe+--+]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    std::complex<dataType> value(1, -2);
    std::complex<dataType> value2(-1, 2);
    Complex c = Complex(value);
    Complex c2 = Complex(value2);
    REQUIRE(value == c.getValue());
    REQUIRE(value2 == c2.getValue());
}

TEST_CASE("Complex - getValue 2 equal -++-", "[cpx_2gVe-++-]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    std::complex<dataType> value(-1, 2);
    std::complex<dataType> value2(1, -2);
    Complex c = Complex(value);
    Complex c2 = Complex(value2);
    REQUIRE(value == c.getValue());
    REQUIRE(value2 == c2.getValue());
}

TEST_CASE("Complex - getValue 2 equal --++", "[cpx_2gVe--++]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    std::complex<dataType> value(-1, -2);
    std::complex<dataType> value2(1, 2);
    Complex c = Complex(value);
    Complex c2 = Complex(value2);
    REQUIRE(value == c.getValue());
    REQUIRE(value2 == c2.getValue());
}
