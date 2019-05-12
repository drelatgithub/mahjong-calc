#ifndef MAHJCALC_RULE_TILE_TYPE_HPP
#define MAHJCALC_RULE_TILE_TYPE_HPP

#include <cstdint>
#include <type_traits>

#include "common.hpp"

namespace mahjcalc {

constexpr size_t num_tile_types_total = 35; // Including Undefined

// Red Doras are not considered here
enum class TileType {
    M1, M2, M3, M4, M5, M6, M7, M8, M9,
    P1, P2, P3, P4, P5, P6, P7, P8, P9,
    S1, S2, S3, S4, S5, S6, S7, S8, S9,
    E, S, W, N,
    Hk, Ht, Cn, // As in Haku, Hatsu, Chun
    Undefined
};
constexpr auto underlying(TileType p) { return static_cast<std::underlying_type_t<TileType>>(p); }
constexpr const char* tile_type_name[] {
    "1m", "2m", "3m", "4m", "5m", "6m", "7m", "8m", "9m",
    "1p", "2p", "3p", "4p", "5p", "6p", "7p", "8p", "9p",
    "1s", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s",
    "E ", "S ", "W ", "N ",
    "Hk", "Ht", "Cn",
    "Undefined"
};
constexpr auto name(TileType t) { return tile_type_name[underlying(t)]; }

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
constexpr TileTypeCat category(size_t tile_type_index) { return category_of_tile_type[tile_type_index]; }
constexpr TileTypeCat category(TileType p) { return category(underlying(p)); }

constexpr mc_uif8 number_of_tile_type[] {
    /* Man */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Pin */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Sou */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Kaze */ 0, 0, 0, 0,
    /* Sangen */ 0, 0, 0,
    /* Undefined */ 0
};
constexpr mc_uif8 number(TileType p) { return number_of_tile_type[underlying(p)]; }

template< mc_uif8 num_players > struct CanStartShuntsu;
template<> struct CanStartShuntsu<4> {
    static constexpr bool value[] {
        // Man, Pin, Sou
        true, true, true, true, true, true, true, false, false,
        true, true, true, true, true, true, true, false, false,
        true, true, true, true, true, true, true, false, false,
        // Kaze
        false, false, false, false,
        // Sangen
        false, false, false,
        // Undefined
        false
    };
};
template<> struct CanStartShuntsu<3> {
    static constexpr bool value[] {
        // Man, Pin, Sou
        false, false, false, false, false, false, false, false, false,
        true, true, true, true, true, true, true, false, false,
        true, true, true, true, true, true, true, false, false,
        // Kaze
        false, false, false, false,
        // Sangen
        false, false, false,
        // Undefined
        false
    };
};
template< typename Rule >
constexpr bool can_start_shuntsu(size_t tile_type_index) {
    return CanStartShuntsu<Rule::num_players>::value[tile_type_index];
}
template< typename Rule >
constexpr bool can_start_shuntsu(TileType t) {
    return can_start_shuntsu<Rule>(underlying(t));
}

template< mc_uif8 num_players > struct DoraTileType;
template<> struct DoraTileType<4> {
    static constexpr TileType value[] {
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
        TileType::Ht, TileType::Cn, TileType::Hk,
        // Undefined
        TileType::Undefined
    };
};
template<> struct DoraTileType<3> {
    static constexpr TileType value[] {
        // Man
        TileType::M9,        TileType::Undefined, TileType::Undefined,
        TileType::Undefined, TileType::Undefined, TileType::Undefined,
        TileType::Undefined, TileType::Undefined, TileType::M1,
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
        TileType::Ht, TileType::Cn, TileType::Hk,
        // Undefined
        TileType::Undefined
    };
};
template< typename Rule >
constexpr TileType get_dora_from_indicator(TileType p) {
    return DoraTileType<Rule::num_players>::value[underlying(p)];
}

} // namespace mahjcalc

#endif
