#ifndef MAHJCALC_RULE_TILE_TYPE_HPP
#define MAHJCALC_RULE_TILE_TYPE_HPP

#include <cstdint>
#include <type_traits>

#include "common.hpp"

namespace mahjcalc {

constexpr size_t num_tile_types = 35; // Including Undefined

// Red Doras are not considered here
enum class TileType {
    M1, M2, M3, M4, M5, M6, M7, M8, M9,
    P1, P2, P3, P4, P5, P6, P7, P8, P9,
    S1, S2, S3, S4, S5, S6, S7, S8, S9,
    E, S, W, N,
    Haku, Hatsu, Chun,
    Undefined
};
constexpr auto underlying(TileType p) { return static_cast<std::underlying_type_t<TileType>>(p); }

enum class TileTypeCat {
    Man, Pin, Sou, Kazehai, Sangenpai, Undefined
};
constexpr TileTypeCat category_of_tile_type[] {
    // Man
    TileTypeCat::Man, TileTypeCat::Man, TileTypeCat::Man,
    TileTypeCat::Man, TileTypeCat::Man, TileTypeCat::Man,
    TileTypeCat::Man, TileTypeCat::Man, TileTypeCat::Man,
    // Pin
    TileTypeCat::Pin, TileTypeCat::Pin, TileTypeCat::Pin,
    TileTypeCat::Pin, TileTypeCat::Pin, TileTypeCat::Pin,
    TileTypeCat::Pin, TileTypeCat::Pin, TileTypeCat::Pin,
    // Sou
    TileTypeCat::Sou, TileTypeCat::Sou, TileTypeCat::Sou,
    TileTypeCat::Sou, TileTypeCat::Sou, TileTypeCat::Sou,
    TileTypeCat::Sou, TileTypeCat::Sou, TileTypeCat::Sou,
    // Kaze
    TileTypeCat::Kazehai, TileTypeCat::Kazehai, TileTypeCat::Kazehai, TileTypeCat::Kazehai,
    // Sangen
    TileTypeCat::Sangenpai, TileTypeCat::Sangenpai, TileTypeCat::Sangenpai,
    // Undefined
    TileTypeCat::Undefined
};
constexpr TileTypeCat category(TileType p) { return category_of_tile_type[underlying(p)]; }

using TileTypeNum = std::uint_fast8_t;
constexpr TileTypeNum number_of_tile_type[] {
    /* Man */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Pin */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Sou */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Kaze */ 0, 0, 0, 0,
    /* Sangen */ 0, 0, 0,
    /* Undefined */ 0
};
constexpr TileTypeNum number(TileType p) { return number_of_tile_type[underlying(p)]; }

constexpr TileType dora_of_tile_type[] {
    // Man
    TileType::M2, TileType::M3, TileType::M4,
    TileType::M5, TileType::M6, TileType::M7,
    TileType::M8, TileType::M9, TileType::M1,
    // Pin
    TileType::P2, TileType::P3, TileType::P4,
    TileType::P5, TileType::P6, TileType::P7,
    TileType::P8, TileType::P9, TileType::P1,
    // Sou
    TileType::S2, TileType::S3, TileType::S4,
    TileType::S5, TileType::S6, TileType::S7,
    TileType::S8, TileType::S9, TileType::S1,
    // Kaze
    TileType::S, TileType::W, TileType::N, TileType::E,
    // Sangen
    TileType::Hatsu, TileType::Chun, TileType::Haku,
    // Undefined
    TileType::Undefined
};
constexpr TileType get_dora_from_indicator(TileType p) { return dora_of_tile_type[underlying(p)]; }

} // namespace mahjcalc

#endif
