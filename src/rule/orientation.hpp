#ifndef MAHJCALC_RULE_ORIENTATION_HPP
#define MAHJCALC_RULE_ORIENTATION_HPP

#include "rule/tile-type.hpp"

namespace mahjcalc {

enum class Kaze { E, S, W, N };
constexpr TileType YAKU_KAZE[] {
    TileType::E, TileType::S, TileType::W, TileType::N
};
constexpr TileType get_yaku_kaze(Kaze k) {
    return YAKU_KAZE[static_cast<std::underlying_type_t<Kaze>>(k)];
}

enum class Orientation { S, R, O, L }; // As in self, right, opposing, left
constexpr Kaze KAZE_ORIENTATION[][4] {
    /* E */ Kaze::E, Kaze::S, Kaze::W, Kaze::N,
    /* S */ Kaze::S, Kaze::W, Kaze::N, Kaze::E,
    /* W */ Kaze::W, Kaze::N, Kaze::E, Kaze::S,
    /* N */ Kaze::N, Kaze::E, Kaze::S, Kaze::W
};
constexpr Kaze kaze_orientation(Kaze k, Orientation o) {
    return KAZE_ORIENTATION
        [static_cast<std::underlying_type_t<Kaze>>(k)]
        [static_cast<std::underlying_type_t<Orientation>>(o)];
}

} // namespace mahjcalc

#endif
