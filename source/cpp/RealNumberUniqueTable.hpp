#ifndef CTDDREALNUMBERUNIQUETABLE_HPP
#define CTDDREALNUMBERUNIQUETABLE_HPP

#include "RealNumber.hpp"
#include <cstdint>
#include <cstring>

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
        if (value < -1) {
            RealNumber* realNumber = create_new_real_number(value);
            realNumber = RealNumber::setNegativePointer(realNumber);
            return realNumber;
        }
        if (value > 1) {
            return create_new_real_number(value);
        }
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

    long getNBuckets() {
        long n_buckets = 0;
        for (auto& bucket: table) {
            n_buckets++;
        }
        return n_buckets;
    }


    // @romOlivo: Gets a string with more info about the performance and usage of the Unique Table
    std::string get_performance_metrics() {
        int max_length = 0;
        int n_buckets = 0;
        int n_nodes = 0;
        float mean_nodes = 0;
        int n_buckets_used = 0;
        float mean_used_nodes = 0;
        for (auto& bucket: table) {
            int partial_length = 0;
            n_buckets++;
            auto* current = bucket;
            while (current) {
                current = current->next;
                partial_length++;
                n_nodes++;
            }
            if (partial_length > max_length) {
                max_length = partial_length;
            }
            if (partial_length > 0) {
                n_buckets_used++;
            }
            mean_nodes = mean_nodes + partial_length;
        }
        mean_used_nodes = mean_nodes / n_buckets_used;
        mean_nodes = mean_nodes / n_buckets;
        std::ostringstream oss;
        oss << "Max length buckets: " << max_length << " / Mean nodes x bucket: " << mean_nodes
            << " / Mean nodes x used bucket: " << mean_used_nodes << "\n";
        return oss.str();
    }

    static void Init_Real_Number_Unique_Table(std::size_t Nbucket) noexcept;

private:

    // Creates or reuses a object with the given real value
    RealNumber* create_new_real_number(double value) {
        RealNumber* rn = new RealNumber();
        rn->setVal(value);
        return rn;
    }

    // Definition of the hashing function for real numbers
    std::size_t hash(double value) {
        if (value == 0.0) value = 0.0;

        std::uint64_t bits;
        std::memcpy(&bits, &value, sizeof(bits));

        // splitmix64
        bits += 0x9e3779b97f4a7c15ULL;
        bits = (bits ^ (bits >> 30)) * 0xbf58476d1ce4e5b9ULL;
        bits = (bits ^ (bits >> 27)) * 0x94d049bb133111ebULL;
        bits ^= (bits >> 31);

        return static_cast<std::size_t>(bits) & MASK;
    }

    // Search for a given complex value if there is an object in the table that represents it.
    RealNumber* searchTable(const std::size_t& hashVal, double value) {
        double abs_value = std::abs(value);
        RealNumber* find_realNumber = nullptr;
        RealNumber* realNumber = table[hashVal];
        while (realNumber != nullptr) {
            if (realNumber != nullptr && approxEqual(realNumber->getValue(), abs_value)) {
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

    bool approxEqual(double v1, double v2) {
        return v1 + TOLERANCE > v2 && v1 - TOLERANCE < v2;
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