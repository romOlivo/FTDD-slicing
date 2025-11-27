#ifndef CTDDREALNUMBERUNIQUETABLE_CPP
#define CTDDREALNUMBERUNIQUETABLE_CPP

#include "RealNumberUniqueTable.hpp"

static void Init_Real_Number_Unique_Table(std::size_t Nbucket) {
    real_number_unique_table = RealNumberUniqueTable(Nbucket);
    real_number_unique_table.clear();
}

#endif