#include <catch2/catch_test_macros.hpp>

#include "Definitions.hpp"
#include "Complex.hpp"

TEST_CASE("Complex - getValue ++", "[cpx_gV++]") {
    std::complex<dataType> value(1, 2);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue +-", "[cpx_gV+-]") {
    std::complex<dataType> value(1, -2);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue -+", "[cpx_gV-+]") {
    std::complex<dataType> value(-1, 2);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}

TEST_CASE("Complex - getValue --", "[cpx_gV--]") {
    std::complex<dataType> value(-1, -2);
    Complex c = Complex(value);
    REQUIRE(value == c.getValue());
}