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
        n_nodes = 0;
    }

    // Clear everything
    void clear() {
        releaseTables();
    }

    // Looks for the given real number. If not found, creates a new one
    RealNumber* find_or_add(double value) {
        std::size_t hashVal = hash(value);
        RealNumber* realNumber = searchTable(hashVal, value);
        if (realNumber == nullptr) {
            realNumber = create_new_real_number(value);
            realNumber->next = table[hashVal];
            table[hashVal] = realNumber;
            if (value < 0) {
                realNumber = RealNumber::setNegativePointer(realNumber);
            }
            n_nodes++;
        }
        return realNumber;

    }

    long getTotalNodes() {
        return n_nodes;
    }

    static void Init_Real_Number_Unique_Table(std::size_t Nbucket) noexcept;

private:

    // Creates or reuses a object with the given real value
    RealNumber* create_new_real_number(double value) {
        RealNumber* rn = new RealNumber();
        rn->setVal(value);;
        return rn;
    }

    // Definition of the hashing function for real numbers
    std::size_t hash(double value) {
        return static_cast<std::size_t>(std::hash<double>{}(value) & MASK);
    }

    // Search for a given complex value if there is an object in the table that represents it.
    RealNumber* searchTable(const std::size_t& hashVal, double value) {
        double abs_value = std::abs(value);
        RealNumber* find_realNumber = nullptr;
        RealNumber* realNumber = table[hashVal];
        while (realNumber != nullptr) {
            if (realNumber != nullptr && realNumber->getValue() == abs_value) {
                find_realNumber = realNumber;
                if (value < 0) {
                    find_realNumber = RealNumber::setNegativePointer(find_realNumber);
                }
                break;
            }
            realNumber = realNumber->next;
        }
        return find_realNumber;
    }

    // Release memory of the tables
    void releaseTables() {
        for (auto& bucket: table) { // a bucket in the table
            // Release bucket
            RealNumber* current = bucket;
            while (current) {
                RealNumber* temp = current;
                current = current->next;
                delete temp;
            }
            bucket = nullptr;
        }
        n_nodes = 0;
    }

    // Parameters of the table
    std::size_t NBUCKET;
    std::vector<RealNumber*> table{std::vector<RealNumber*>(1)};
    std::size_t MASK;
    long n_nodes = 0;

};

// Declare the global complex table
extern RealNumberUniqueTable real_number_unique_table;

#endif