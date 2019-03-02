#ifndef MAHJCALC_RULE_TILE_HPP
#define MAHJCALC_RULE_TILE_HPP

#include "common.hpp"
#include "rule/ruleset.hpp"
#include "rule/tile-type.hpp"

namespace mahjcalc {

struct Tile { TileType type; size_t id; };
struct TileId {
    size_t index;
    TileId& operator=(size_t new_index) { index = new_index; return *this; }
    explicit operator size_t() const { return index; }
};

constexpr mc_ushort num_tiles_per_type = 4;

template< ruleset::RuleSet::TopCategory, mc_ushort num_players > struct TileSet;
template<> struct TileSet<ruleset::RuleSet::TopCategory::Riichi, 4> {
    static constexpr size_t num_tile_types = 34;
    static constexpr size_t num_tiles = num_tile_types * num_tiles_per_type;
    static constexpr Tile value[] {
        {TileType::M1, 0}, {TileType::M1, 1}, {TileType::M1, 2}, {TileType::M1, 3},
        {TileType::M2, 0}, {TileType::M2, 1}, {TileType::M2, 2}, {TileType::M2, 3},
        {TileType::M3, 0}, {TileType::M3, 1}, {TileType::M3, 2}, {TileType::M3, 3},
        {TileType::M4, 0}, {TileType::M4, 1}, {TileType::M4, 2}, {TileType::M4, 3},
        {TileType::M5, 0}, {TileType::M5, 1}, {TileType::M5, 2}, {TileType::M5, 3},
        {TileType::M6, 0}, {TileType::M6, 1}, {TileType::M6, 2}, {TileType::M6, 3},
        {TileType::M7, 0}, {TileType::M7, 1}, {TileType::M7, 2}, {TileType::M7, 3},
        {TileType::M8, 0}, {TileType::M8, 1}, {TileType::M8, 2}, {TileType::M8, 3},
        {TileType::M9, 0}, {TileType::M9, 1}, {TileType::M9, 2}, {TileType::M9, 3},
        {TileType::P1, 0}, {TileType::P1, 1}, {TileType::P1, 2}, {TileType::P1, 3},
        {TileType::P2, 0}, {TileType::P2, 1}, {TileType::P2, 2}, {TileType::P2, 3},
        {TileType::P3, 0}, {TileType::P3, 1}, {TileType::P3, 2}, {TileType::P3, 3},
        {TileType::P4, 0}, {TileType::P4, 1}, {TileType::P4, 2}, {TileType::P4, 3},
        {TileType::P5, 0}, {TileType::P5, 1}, {TileType::P5, 2}, {TileType::P5, 3},
        {TileType::P6, 0}, {TileType::P6, 1}, {TileType::P6, 2}, {TileType::P6, 3},
        {TileType::P7, 0}, {TileType::P7, 1}, {TileType::P7, 2}, {TileType::P7, 3},
        {TileType::P8, 0}, {TileType::P8, 1}, {TileType::P8, 2}, {TileType::P8, 3},
        {TileType::P9, 0}, {TileType::P9, 1}, {TileType::P9, 2}, {TileType::P9, 3},
        {TileType::S1, 0}, {TileType::S1, 1}, {TileType::S1, 2}, {TileType::S1, 3},
        {TileType::S2, 0}, {TileType::S2, 1}, {TileType::S2, 2}, {TileType::S2, 3},
        {TileType::S3, 0}, {TileType::S3, 1}, {TileType::S3, 2}, {TileType::S3, 3},
        {TileType::S4, 0}, {TileType::S4, 1}, {TileType::S4, 2}, {TileType::S4, 3},
        {TileType::S5, 0}, {TileType::S5, 1}, {TileType::S5, 2}, {TileType::S5, 3},
        {TileType::S6, 0}, {TileType::S6, 1}, {TileType::S6, 2}, {TileType::S6, 3},
        {TileType::S7, 0}, {TileType::S7, 1}, {TileType::S7, 2}, {TileType::S7, 3},
        {TileType::S8, 0}, {TileType::S8, 1}, {TileType::S8, 2}, {TileType::S8, 3},
        {TileType::S9, 0}, {TileType::S9, 1}, {TileType::S9, 2}, {TileType::S9, 3},
        {TileType::E, 0}, {TileType::E, 1}, {TileType::E, 2}, {TileType::E, 3},
        {TileType::S, 0}, {TileType::S, 1}, {TileType::S, 2}, {TileType::S, 3},
        {TileType::W, 0}, {TileType::W, 1}, {TileType::W, 2}, {TileType::W, 3},
        {TileType::N, 0}, {TileType::N, 1}, {TileType::N, 2}, {TileType::N, 3},
        {TileType::Haku,  0}, {TileType::Haku,  1}, {TileType::Haku,  2}, {TileType::Haku,  3},
        {TileType::Hatsu, 0}, {TileType::Hatsu, 1}, {TileType::Hatsu, 2}, {TileType::Hatsu, 3},
        {TileType::Chun,  0}, {TileType::Chun,  1}, {TileType::Chun,  2}, {TileType::Chun,  3}
    };
    static_assert(sizeof(value) / sizeof(Tile) == num_tiles);
};
template<> struct TileSet<ruleset::RuleSet::TopCategory::Riichi, 3> {
    static constexpr size_t num_tile_types = 27;
    static constexpr size_t num_tiles = num_tile_types * num_tiles_per_type;
    static constexpr Tile value[] {
        {TileType::M1, 0}, {TileType::M1, 1}, {TileType::M1, 2}, {TileType::M1, 3},
        {TileType::M9, 0}, {TileType::M9, 1}, {TileType::M9, 2}, {TileType::M9, 3},
        {TileType::P1, 0}, {TileType::P1, 1}, {TileType::P1, 2}, {TileType::P1, 3},
        {TileType::P2, 0}, {TileType::P2, 1}, {TileType::P2, 2}, {TileType::P2, 3},
        {TileType::P3, 0}, {TileType::P3, 1}, {TileType::P3, 2}, {TileType::P3, 3},
        {TileType::P4, 0}, {TileType::P4, 1}, {TileType::P4, 2}, {TileType::P4, 3},
        {TileType::P5, 0}, {TileType::P5, 1}, {TileType::P5, 2}, {TileType::P5, 3},
        {TileType::P6, 0}, {TileType::P6, 1}, {TileType::P6, 2}, {TileType::P6, 3},
        {TileType::P7, 0}, {TileType::P7, 1}, {TileType::P7, 2}, {TileType::P7, 3},
        {TileType::P8, 0}, {TileType::P8, 1}, {TileType::P8, 2}, {TileType::P8, 3},
        {TileType::P9, 0}, {TileType::P9, 1}, {TileType::P9, 2}, {TileType::P9, 3},
        {TileType::S1, 0}, {TileType::S1, 1}, {TileType::S1, 2}, {TileType::S1, 3},
        {TileType::S2, 0}, {TileType::S2, 1}, {TileType::S2, 2}, {TileType::S2, 3},
        {TileType::S3, 0}, {TileType::S3, 1}, {TileType::S3, 2}, {TileType::S3, 3},
        {TileType::S4, 0}, {TileType::S4, 1}, {TileType::S4, 2}, {TileType::S4, 3},
        {TileType::S5, 0}, {TileType::S5, 1}, {TileType::S5, 2}, {TileType::S5, 3},
        {TileType::S6, 0}, {TileType::S6, 1}, {TileType::S6, 2}, {TileType::S6, 3},
        {TileType::S7, 0}, {TileType::S7, 1}, {TileType::S7, 2}, {TileType::S7, 3},
        {TileType::S8, 0}, {TileType::S8, 1}, {TileType::S8, 2}, {TileType::S8, 3},
        {TileType::S9, 0}, {TileType::S9, 1}, {TileType::S9, 2}, {TileType::S9, 3},
        {TileType::E, 0}, {TileType::E, 1}, {TileType::E, 2}, {TileType::E, 3},
        {TileType::S, 0}, {TileType::S, 1}, {TileType::S, 2}, {TileType::S, 3},
        {TileType::W, 0}, {TileType::W, 1}, {TileType::W, 2}, {TileType::W, 3},
        {TileType::N, 0}, {TileType::N, 1}, {TileType::N, 2}, {TileType::N, 3},
        {TileType::Haku,  0}, {TileType::Haku,  1}, {TileType::Haku,  2}, {TileType::Haku,  3},
        {TileType::Hatsu, 0}, {TileType::Hatsu, 1}, {TileType::Hatsu, 2}, {TileType::Hatsu, 3},
        {TileType::Chun,  0}, {TileType::Chun,  1}, {TileType::Chun,  2}, {TileType::Chun,  3}
    };
    static_assert(sizeof(value) / sizeof(Tile) == num_tiles);
};

template< typename Rule >
constexpr size_t num_tiles() { return TileSet<Rule::top_category, Rule::num_players>::num_tiles; }
template< typename Rule >
constexpr Tile tile(TileId i) { return TileSet<Rule::top_category, Rule::num_players>::value[i.index]; }

} // namespace mahjcalc

#endif
