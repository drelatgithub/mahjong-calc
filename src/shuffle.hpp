#ifndef MAHJCALC_SHUFFLE_HPP
#define MAHJCALC_SHUFFLE_HPP

#include <array>
#include <numeric>
#include <random>

#include "common.hpp"
#include "util/rdtsc.hpp"

namespace mahjcalc {

inline std::mt19937_64 rand_gen(rdtsc());

template< size_t total_size >
inline void re_shuffle(std::array<size_t, total_size>& arr) {
    // Reset
    std::iota(arr.begin(), arr.end(), 0);
    // Shuffle
    std::shuffle(arr.begin(), arr.end(), rand_gen);
}

} // namespace mahjcalc

#endif
