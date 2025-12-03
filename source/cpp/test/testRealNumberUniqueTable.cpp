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
