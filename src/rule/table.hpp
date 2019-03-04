#ifndef MAHJCALC_RULE_TABLE_HPP
#define MAHJCALC_RULE_TABLE_HPP

#include <array>

#include "rule/hand.hpp"
#include "rule/tile.hpp"

namespace mahjcalc {

template< typename Rule >
constexpr size_t num_rinshan_tiles() { return Rule::num_players == 4 ? 4 : 8; }

template< typename Rule >
struct TileTracker {
    static constexpr size_t num_tiles = num_tiles< Rule >();
    static constexpr size_t num_rinshan_tiles = num_rinshan_tiles< Rule >();
    static constexpr size_t num_dora_indicators = Rule::num_dora_indicators;
    static constexpr size_t num_hand_tiles = Hand::hand_size;
    static constexpr size_t num_hand_tiles_init = Hand::hand_size - 1;

    static constexpr size_t max_kan_allowed = Rule::max_kan_allowed;

    static constexpr size_t dead_wall_size = 2 * num_dora_indicators + num_rinshan_tiles;

    static_assert(
        2 * num_dora_indicators + num_rinshan_tiles + Rule::num_players * num_hand_tiles_init < num_tiles,
        "Not enough tiles for the game."
    );
    static_assert(
        max_kan_allowed <= num_rinshan_tiles,
        "Max kan number cannot exceed number of rinshan tiles."
    );
    static_assert(
        max_kan_allowed <= num_dora_indicators - 1,
        "Max kan number cannot exceed number of closed doras."
    );

    std::array< size_t, num_tiles > idx_tiles;

    size_t idx_next_tile; // Next tile to draw
    size_t idx_haitei_tile; // Last tile to draw
    size_t num_remaining_rinshan_tiles;
    size_t num_open_dora_indicators;

    void reset() {
        idx_next_tile = Rule::num_players * num_hand_tiles_init;
        idx_haitei_tile = num_tiles - num_rinshan_tiles - 2 * num_dora_indicators - 1;
        num_remaining_rinshan_tiles = num_rinshan_tiles;
        num_open_dora_indicators = 1;
    }
};

} // namespace mahjcalc

#endif
