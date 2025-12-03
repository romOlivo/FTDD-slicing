#ifndef CTDDREALNUMBERUNIQUETABLE_CPP
#define CTDDREALNUMBERUNIQUETABLE_CPP

#include "RealNumberUniqueTable.hpp"

void RealNumberUniqueTable::Init_Real_Number_Unique_Table(std::size_t Nbucket) noexcept {
    real_number_unique_table = RealNumberUniqueTable(Nbucket);
    real_number_unique_table.clear();
}

// Declare the global complex table
RealNumberUniqueTable real_number_unique_table;

#endif