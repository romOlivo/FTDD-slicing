#ifndef CTDDREALNUMBERUNIQUETABLE_HPP
#define CTDDREALNUMBERUNIQUETABLE_HPP

#include "RealNumber.hpp"
#include "MemoryPool.hpp"
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

    inline double canonize(double value) noexcept {
        if (value == 0.0) return 0.0;  // avoid -0.0
        return std::round(value / TOLERANCE) * TOLERANCE;
    }

    RealNumber* find_or_add(double value) {
        if (value < -1) {
            RealNumber* realNumber = create_new_real_number(value);
            realNumber = RealNumber::setNegativePointer(realNumber);
            return realNumber;
        }
        if (value > 1) {
            return create_new_real_number(value);
        }

        bool isNegative = value < 0;
        double abs_value = std::abs(value);
        double canon_value = canonize(abs_value);

        std::size_t hashVal = hash(canon_value);

        RealNumber* prev = nullptr;
        RealNumber* current = table[hashVal];

        while (current != nullptr && current->getValue() < canon_value) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr && current->getValue() == canon_value) {
            return isNegative ? RealNumber::setNegativePointer(current) : current;
        }

        RealNumber* rn = pool.get();
        rn->setVal(canon_value);

        if (prev == nullptr) {
            rn->next = table[hashVal];
            table[hashVal] = rn;
        } else {
            rn->next = prev->next;
            prev->next = rn;
        }

        n_nodes++;
        return isNegative ? RealNumber::setNegativePointer(rn) : rn;

    }

    long getTotalNodes() {
        return n_nodes;
    }

    long getNBuckets() {
        return table.size();
    }


    // Gets a string with more info about the performance and usage of the Unique Table
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
        RealNumber* rn = pool.get();
        rn->setVal(value);
        rn->next = nullptr;
        return rn;
    }

    // Definition of the hashing function for real numbers
    inline std::size_t hash(double value) noexcept {
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

    inline constexpr bool approxEqual(double v1, double v2) {
        double diff = v1 - v2;
        return diff < TOLERANCE && diff > -TOLERANCE;
    }

    // Release memory of the tables
    void releaseTables() {
        for (auto& bucket: table) { // a bucket in the table
            // Release bucket
            RealNumber* current = bucket;
            while (current) {
                RealNumber* temp = current;
                current = current->next;
                pool.release(temp);
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
    MemoryPool<RealNumber> pool;

};

// Declare the global complex table
extern RealNumberUniqueTable real_number_unique_table;

#endif