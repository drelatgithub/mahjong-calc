#include "util/rdtsc.hpp"

#include "util/environment.h"

#ifdef COMPILER_MSVC
    #include <intrin.h>
    #pragma intrinsic(__rdtsc)
#endif

namespace mahjcalc {

std::uint_fast64_t rdtsc() {

#ifdef COMPILER_MSVC
    return __rdtsc();

#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((std::uint_fast64_t)hi << 32) | lo;

#else
    return 0;

#endif
}

} // namespace mahjcalc
