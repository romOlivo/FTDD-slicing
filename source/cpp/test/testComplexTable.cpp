#include <catch2/catch_test_macros.hpp>

#include "../Complex.hpp"
#include "../Definitions.hpp"
#include "../cTddComplexTable.hpp"

TEST_CASE("ComplexTable - Find_Or_Add 1", "[ct_FoA-1]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(0.1, 0.1);
    Complex* c = complex_table.Find_Or_Add(value);
    REQUIRE(value == Complex::getValue(c));
}

TEST_CASE("ComplexTable - Find_Or_Add 2 same", "[ct_FoA-2s]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(0.1, 0.1);
    Complex* c = complex_table.Find_Or_Add(value);
    Complex* c2 = complex_table.Find_Or_Add(value);
    REQUIRE(value == Complex::getValue(c));
    REQUIRE(c == c2);
}

TEST_CASE("ComplexTable - Find_Or_Add 2 unique", "[ct_FoA-2u]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(0.1, 0.1);
    std::complex<dataType> value2(-0.1, -0.1);
    Complex* c = complex_table.Find_Or_Add(value);
    Complex* c2 = complex_table.Find_Or_Add(value2);
    REQUIRE(value == Complex::getValue(c));
    REQUIRE(value2 == Complex::getValue(c2));
    REQUIRE(c != c2);
}

TEST_CASE("ComplexTable - getTotalNodes init 0 inserted 2 total", "[ct_gTNi]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    REQUIRE(2 == complex_table.getTotalNodes());
}

TEST_CASE("ComplexTable - getTotalNodes init default 0", "[ct_gTNid0]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(0);
    complex_table.Find_Or_Add(value);
    REQUIRE(2 == complex_table.getTotalNodes());
}

TEST_CASE("ComplexTable - getTotalNodes init default 1", "[ct_gTNid1]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(1);
    complex_table.Find_Or_Add(value);
    REQUIRE(2 == complex_table.getTotalNodes());
}

TEST_CASE("ComplexTable - getTotalNodes normal 1 inserted 3 total", "[ct_gTNn 1/3]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(0.1, 0.1);
    complex_table.Find_Or_Add(value);
    REQUIRE(3 == complex_table.getTotalNodes());
}

TEST_CASE("ComplexTable - getTotalNodes normal 2 inserted 4 total", "[ct_gTNn 2/4]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(0.1, 0.1);
    complex_table.Find_Or_Add(value);
    complex_table.Find_Or_Add(-value);
    REQUIRE(4 == complex_table.getTotalNodes());
}

TEST_CASE("ComplexTable - getTotalNodes normal 2 inserted 3 total", "[ct_gTNn 2/3]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(0.1, 0.1);
    complex_table.Find_Or_Add(value);
    complex_table.Find_Or_Add(value);
    REQUIRE(3 == complex_table.getTotalNodes());
}

TEST_CASE("ComplexTable - getTotalNodes normal 3 inserted 4 total", "[ct_gTNn 3/4]") {
    ComplexTable::Init_Complex_Unique_Table(1);
    std::complex<dataType> value(0.1, 0.1);
    complex_table.Find_Or_Add(value);
    complex_table.Find_Or_Add(-value);
    complex_table.Find_Or_Add(value);
    REQUIRE(4 == complex_table.getTotalNodes());
}

TEST_CASE("ComplexTable - getTotalBuckets empty 1", "[ct_gTBe 1]") {
    long n_buckets = 1;
    ComplexTable::Init_Complex_Unique_Table(n_buckets);
    REQUIRE(n_buckets == complex_table.getNBuckets());
}

TEST_CASE("ComplexTable - getTotalBuckets empty 10", "[ct_gTBe 10]") {
    long n_buckets = 10;
    ComplexTable::Init_Complex_Unique_Table(n_buckets);
    REQUIRE(n_buckets == complex_table.getNBuckets());
}
