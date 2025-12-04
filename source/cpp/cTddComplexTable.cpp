#ifndef CTDDCOMPLEXTABLE_CPP
#define CTDDCOMPLEXTABLE_CPP

#include "Definitions.hpp"
#include "cTddComplexTable.hpp"

void ComplexTable::Init_Complex_Unique_Table(std::size_t Nbucket) noexcept {
    complex_table = ComplexTable(Nbucket);
    complex_table.clear();
}

// Declare the global real number table
ComplexTable complex_table;

#endif