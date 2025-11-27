#ifndef CTDDREALNUMBERUNIQUETABLE_HPP
#define CTDDREALNUMBERUNIQUETABLE_HPP

#include "RealNumber.hpp"

class RealNumberUniqueTable {

public:
    // Construction
    RealNumberUniqueTable() {}
    RealNumberUniqueTable(std::size_t Nbucket) {
        NBUCKET = Nbucket;
        MASK = NBUCKET - 1;
        table.resize(NBUCKET);
    }

    // Clear everything
    void clear() {
        // releaseTables();
    }

    // Looks for the given real number. If not found, creates a new one
    RealNumber* find_or_add(double value) {
        return new RealNumber(value);
    }

    static void Init_Real_Number_Unique_Table(std::size_t Nbucket) noexcept;

private:

    // Parameters of the table
    std::size_t NBUCKET;
    std::vector<RealNumber*> table{std::vector<RealNumber*>(0)};
    std::size_t MASK;

};

// Declare the global complex table
RealNumberUniqueTable real_number_unique_table;

#endif