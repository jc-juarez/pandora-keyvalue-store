// *************************************
// Pandora Key-Value Store
// Constants
// 'numerics.h'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef NUMERICS_H
#define NUMERICS_H

#include <string>

namespace pandora {

    class Numerics {

        // Static class
        private:
            Numerics() = delete;

        // Numeric Constants
        public:
            // Indexes
            static inline constexpr int ElementContainerDatafileSizeIndex {0};
            static inline constexpr int ElementContainerDatafileRoundRobinIndexIndex {1};
            static inline constexpr int ShardDatafileSizeIndex {0};
            static inline constexpr int ShardDatafilePathIndex {1};
            // Sizes and capacities
            static inline constexpr size_t ElementContainerNameMaxBytesSize {100}; // 0.1 kB
            static inline constexpr size_t ElementKeyMaxBytesSize {100}; // 0.1kB
            static inline constexpr size_t ElementValueMaxBytesSize {4000}; // 4kB
            static inline constexpr size_t ElementContainerMaxElementsSize {100000};
            static inline constexpr size_t ShardMaxElementsSize {1000};
            // General numerics
            static inline constexpr int NumberShards {100};
            static inline constexpr int NumberApolloSearchThreads {10};
            static inline constexpr int ElementContainerDatafileSize {3};
            static inline constexpr int ShardDatafileSize {2};
            static inline constexpr int NotFoundInt {-1};
            static inline constexpr double MillisecondsDivision {1000000};
            static inline constexpr int RandomSize9LowerLimit {100000000};
            static inline constexpr int RandomSize9UpperLimit {999999999};

    };

} // namespace pandora

#endif