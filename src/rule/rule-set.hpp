#ifndef Mahjcalc_Rule_RuleSet_Hpp
#define Mahjcalc_Rule_RuleSet_Hpp

//-----------------------------------------------------------------------------
// This file defines all the static configurations of the game.
//
// Specific rules should inherit the RuleSet struct and override the settings
// different from the default value.
//-----------------------------------------------------------------------------

#include "common.hpp"

namespace mahjcalc {
namespace ruleset {

namespace internal {

class DefaultRoundCounter {
private:
    int cnt_ = 0;
public:

    DefaultRoundCounter() = default;
    DefaultRoundCounter(const DefaultRoundCounter&) = default;
    DefaultRoundCounter& operator=(const DefaultRoundCounter&) = default;

    void inc() { ++cnt_; }
};

} // namespace internal

struct RuleSet {
    // Game setup
    static constexpr mc_uif8 num_players = 4;
    enum class TopCategory {
        Riichi, Custom
    };
    static constexpr TopCategory top_category = TopCategory::Riichi;

    using RoundCounter = internal::DefaultRoundCounter;
    static constexpr size_t player_starting_score = 25000;
    static constexpr size_t player_target_score = 30000;

    // Detailed game settings
    static constexpr bool enable_yaku_chitoitsu = true;
    static constexpr bool enable_yaku_kokushi_musou = true;
    static constexpr size_t max_kan_allowed = 4;
    static constexpr size_t num_dora_indicators = 0;
};

} // namespace ruleset
} // namespace mahjcalc

#endif
