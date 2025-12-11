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

TEST_CASE("RealNumberUniqueTable - getValue different", "[rnUT_gVd]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    RealNumber* rn = real_number_unique_table.find_or_add(number);
    double number2 = 0.5;
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

TEST_CASE("RealNumberUniqueTable - getTotalNodes normal 2 inserted 1 total =", "[rnUT_gTNn 1/2 =]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number);
    REQUIRE(1 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes normal 2 inserted 1 total +-", "[rnUT_gTNn 1/2 +-]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    real_number_unique_table.find_or_add(number);
    number = -1.0;
    real_number_unique_table.find_or_add(number);
    REQUIRE(1 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes normal 4 inserted 1 total =+-", "[rnUT_gTNn 1/4 =+-]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number);
    number = -1.0;
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number);
    REQUIRE(1 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes normal 2 inserted 2 total", "[rnUT_gTNn 2/2]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    double number2 = 0.5;
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number2);
    REQUIRE(2 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes normal 8 inserted 2 total =+-", "[rnUT_gTNn 2/8 =+-]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    double number2 = 0.5;
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number2);
    real_number_unique_table.find_or_add(number2);
    real_number_unique_table.find_or_add(number);
    number = -1.0;
    number2 = -0.5;
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number2);
    real_number_unique_table.find_or_add(number2);
    real_number_unique_table.find_or_add(number);
    REQUIRE(2 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalBuckets empty 1", "[ct_gTBe 1]") {
    long n_buckets = 1;
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(n_buckets);
    REQUIRE(n_buckets == real_number_unique_table.getNBuckets());
}

TEST_CASE("RealNumberUniqueTable - getTotalBuckets empty 10", "[ct_gTBe 10]") {
    long n_buckets = 10;
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(n_buckets);
    REQUIRE(n_buckets == real_number_unique_table.getNBuckets());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes tolerance 2 inserted 1 total +", "[rnUT_gTNt 2/1+]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    double number2 = 1.0 + (TOLERANCE / 2);
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number2);
    REQUIRE(1 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes tolerance 2 inserted 1 total -", "[rnUT_gTNt 2/1-]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    double number2 = 1.0 - (TOLERANCE / 2);
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number2);
    REQUIRE(1 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes tolerance 3 inserted 1 total", "[rnUT_gTNt 3/1]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 1.0;
    double number2 = 1.0 + (TOLERANCE / 2);
    double number3 = 1.0 - (TOLERANCE / 2);
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number2);
    real_number_unique_table.find_or_add(number3);
    REQUIRE(1 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes not normalize +", "[rnUT_gTNnn+ 1/0]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 2.0;
    real_number_unique_table.find_or_add(number);
    REQUIRE(0 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes not normalize -", "[rnUT_gTNnn+ 1/0]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = -2.0;
    real_number_unique_table.find_or_add(number);
    REQUIRE(0 == real_number_unique_table.getTotalNodes());
}

TEST_CASE("RealNumberUniqueTable - getTotalNodes not normalize +-", "[rnUT_gTNnn+ 2/0]") {
    RealNumberUniqueTable::Init_Real_Number_Unique_Table(1);
    double number = 2.0;
    double number2 = -2.0;
    real_number_unique_table.find_or_add(number);
    real_number_unique_table.find_or_add(number2);
    REQUIRE(0 == real_number_unique_table.getTotalNodes());
}
