#ifndef Mahjcalc_Rule_Table_Hpp
#define Mahjcalc_Rule_Table_Hpp

#include <algorithm> // copy
#include <array>
#include <vector>

#include "rule/hand.hpp"
#include "rule/orientation.hpp"
#include "rule/player.hpp"
#include "rule/tile.hpp"
#include "shuffle.hpp"

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

    std::array< size_t, num_tiles > tile_indices;
    std::array< TileState, num_tiles > tile_states;

    size_t idx_next_tile; // Next tile to draw
    size_t idx_haitei_tile; // Last tile to draw
    size_t num_remaining_rinshan_tiles;
    size_t num_open_dora_indicators;

    void reset() {
        idx_next_tile = Rule::num_players * num_hand_tiles_init;
        idx_haitei_tile = num_tiles - num_rinshan_tiles - 2 * num_dora_indicators - 1;
        num_remaining_rinshan_tiles = num_rinshan_tiles;
        num_open_dora_indicators = 1;

        for(size_t i = 0; i < idx_next_tile; ++i) tile_states[i] = TileState::Type::Hand;
        for(size_t i = idx_next_tile; i <= idx_haitei_tile; ++i) tile_states[i] = TileState::Type::Wall;
        for(size_t i = idx_haitei_tile + 1; i < num_tiles; ++i) tile_states[i] = TileState::Type::Dead;
    }
};

template< typename Rule >
struct RoundRecord {
    static constexpr size_t num_tiles = num_tiles< Rule >();

    typename Rule::RoundCounter counter;
    std::array< size_t, num_tiles > tile_indices;

    std::vector< PlayerOperation > ops;

    // Redundant information for easy access and cross checking
    // SomeType PlayerEndStatus;
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

    enum class Mode { Normal, Replay };

private:

    // Table mode and records
    //-------------------------------------------------------------------------
    Mode mode_;
    std::vector< RoundRecord< Rule > > records_;

    // Current round table information
    //-------------------------------------------------------------------------
    typename Rule::RoundCounter counter_;
    Haiyama< Rule > haiyama_;

    mc_uif8 oya_slot;

    // Current round player information
    //-------------------------------------------------------------------------
    Hand         hands_         [num_players];
    bool         need_op_       [num_players];
    PlayerStatus player_status_ [num_players];
    size_t       player_score_  [num_players];

public:
    void new_round() {
        // The round counter should already be updated here

        // Reset haiyama and reshuffle the tiles
        haiyama_.reset();
        re_shuffle(haiyama_.tile_indices);

        // Begin a new page on record
        records_.emplace_back();
        records_.back().tile_indices = haiyama_.tile_indices;
        // records_.round_counter = round_counter_;

    } // new_round()
    void init_round() {
        if(mode_ == Mode::Normal) {
            for(auto& score : player_score_) score = Rule::player_starting_score;

            // Init round counter

            new_round();
        }
    }

    //-------------------------------------------------------------------------
    // The feed function takes a player operation and returns whether the
    // operation is valid.
    //
    // Note: an operation does not need to take effect for being valid. For
    // example, if a player is allowed to declare Pon on a discard, Pon is a
    // valid operation. But meanwhile, another player might declare a valid Ron
    // on this tile, then the Ron takes precedence and the Pon does not take
    // effect.
    //-------------------------------------------------------------------------
    bool feed(PlayerOperation op) {

        // Return if this player cannot make operation
        if(!need_op_[op.player_id]) return false;

        switch(op.type) {
        case PlayerOperation::Type::Discard:
            // Update player hands with discard
            // and poll discard related events
        case PlayerOperation::Type::RiichiDiscard:
            // Update discarding player state as riichi
            // and update player hands with discard
            // and poll discard related events
        case PlayerOperation::Type::Tsumo:
            // Update game state as ending
            // Update winning player
            // Do aftergame stuff
        case PlayerOperation::Type::Ron:
            // Update game state as ending
            // Update winning/losing player
            // after game
        case PlayerOperation::Type::Chi:
            // If in poll... wait for the poll
            // If not in poll...
            //   update naki and update hand
        case PlayerOperation::Type::Pon:
            // If in poll... update poll result
            // else update naki and hand
        case PlayerOperation::Type::Kan:
            // If in poll... update poll result
            // else update naki and hand
        case PlayerOperation::Type::KyuushuuKyuuhai:
            // ???
        case PlayerOperation::Type::Cancel:
            // ???
        }
    }
};

} // namespace mahjcalc

#endif
