#include <catch2/catch_test_macros.hpp>

#include "../RealNumberUniqueTable.hpp"
#include "../Definitions.hpp"
#include "../RealNumber.hpp"

TEST_CASE("RealNumberUniqueTable - getValue equal +", "[rnUT_gVe+]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    RealNumber* rn = real_number_unique_table.find_or_add(number);
    REQUIRE(number == RealNumber::getValue(rn));
}

TEST_CASE("RealNumberUniqueTable - getValue equal -", "[rnUT_gVe-]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    RealNumber* rn = real_number_unique_table.find_or_add(number);
    REQUIRE(number == RealNumber::getValue(rn));
}

TEST_CASE("RealNumberUniqueTable - getValue equal +-", "[rnUT_gVe+-]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    RealNumber* rn = real_number_unique_table.find_or_add(number);
    double number2 = -1.0;
    RealNumber* rn2 = real_number_unique_table.find_or_add(number2);
    REQUIRE(number == RealNumber::getValue(rn));
    REQUIRE(number2 == RealNumber::getValue(rn2));
}

TEST_CASE("RealNumberUniqueTable - getValue equal -+", "[rnUT_gVe-+]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = -1.0;
    RealNumber* rn = real_number_unique_table.find_or_add(number);
    double number2 = +1.0;
    RealNumber* rn2 = real_number_unique_table.find_or_add(number2);
    REQUIRE(number == RealNumber::getValue(rn));
    REQUIRE(number2 == RealNumber::getValue(rn2));
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes normal 1 inserted 1 total", "[rnUT_gTNn 1/1]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    real_number_unique_table.find_or_add(number);
    REQUIRE(1 == real_number_unique_table.getTotalNodes());
}
