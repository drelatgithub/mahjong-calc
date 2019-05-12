#ifndef Mahjcalc_Rule_Table_Hpp
#define Mahjcalc_Rule_Table_Hpp

#include <array>

#include "rule/hand.hpp"
#include "rule/orientation.hpp"
#include "rule/player.hpp"
#include "rule/tile.hpp"

namespace mahjcalc {

template< typename Rule >
constexpr size_t num_rinshan_tiles() { return Rule::num_players == 4 ? 4 : 8; }

template< typename Rule >
struct Haiyama {
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

    struct TileState {
        enum class Type { Wall, Hand, Discard, Dead };
        Type type;
    };

    std::array< size_t, num_tiles > idx_tiles;
    std::array< TileState, num_tiles > state_tiles;

    size_t idx_next_tile; // Next tile to draw
    size_t idx_haitei_tile; // Last tile to draw
    size_t num_remaining_rinshan_tiles;
    size_t num_open_dora_indicators;

    void reset() {
        idx_next_tile = Rule::num_players * num_hand_tiles_init;
        idx_haitei_tile = num_tiles - num_rinshan_tiles - 2 * num_dora_indicators - 1;
        num_remaining_rinshan_tiles = num_rinshan_tiles;
        num_open_dora_indicators = 1;

        for(size_t i = 0; i < idx_next_tile; ++i) state_tiles[i] = TileState::Type::Hand;
        for(size_t i = idx_next_tile; i <= idx_haitei_tile; ++i) state_tiles[i] = TileState::Type::Wall;
        for(size_t i = idx_haitei_tile + 1; i < num_tiles; ++i) state_tiles[i] = TileState::Type::Dead;
    }
};

//-----------------------------------------------------------------------------
// The table contains all the information and status of a game.
//
// The players and observers interact with the table via functions provided.
//
// Table is a state machine.
//
// TODO: make Table thread-safe for async observations/operations.
//-----------------------------------------------------------------------------
template< typename Rule >
class Table {
public:
    static constexpr mc_uif8 num_players = Rule::num_players;
    static constexpr size_t num_tiles = num_tiles< Rule >();

private:

    // Table mode and records
    //-------------------------------------------------------------------------
    bool record_mode_;
    // Some_struct record_;

    // Current round table information
    //-------------------------------------------------------------------------
    // RoundCount counter_;
    Haiyama< Rule > haiyama;

    mc_uif8 oya_slot;

    // Current round player information
    //-------------------------------------------------------------------------
    Hand hands_   [num_players];
    bool need_op_ [num_players];

public:

    //-------------------------------------------------------------------------
    // The feed function takes a player operation and returns whether the
    // operation is valid.
    //
    // Note: an operation does not need to take effect for being valid. For
    // example, a player is allowed to declare Pon on a discard, so Pon is a
    // valid operation. But meanwhile, another player might declare a valid Ron
    // on this tile, then the Ron takes precedence and the Pon does not take
    // effect.
    //-------------------------------------------------------------------------
    bool feed(mc_uif8 player, Operation op) {

        // Return if this player cannot make operation
        if(!need_op_[player]) return false;

        switch(op.type) {
        case Operation::Type::Discard:
            // Update player hands with discard
            // and poll discard related events
        case Operation::Type::RiichiDiscard:
            // Update discarding player state as riichi
            // and update player hands with discard
            // and poll discard related events
        case Operation::Type::Tsumo:
            // Update game state as ending
            // Update winning player
            // Do aftergame stuff
        case Operation::Type::Ron:
            // Update game state as ending
            // Update winning/losing player
            // after game
        case Operation::Type::Chi:
            // If in poll... wait for the poll
            // If not in poll...
            //   update naki and update hand
        case Operation::Type::Pon:
            // If in poll... update poll result
            // else update naki and hand
        case Operation::Type::Kan:
            // If in poll... update poll result
            // else update naki and hand
        case Operation::Type::KyuushuuKyuuhai:
            // ???
        case Operation::Type::Cancel:
            // ???
        }
    }
};

} // namespace mahjcalc

#endif
