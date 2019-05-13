#ifndef Mahjcalc_Rule_RuleSet_Riichi_Hpp
#define Mahjcalc_Rule_RuleSet_Riichi_Hpp

#include "rule/rule-set.hpp"

namespace mahjcalc {
namespace ruleset {

struct DefaultConfigRiichi {
    static constexpr size_t num_players = 4;

    static constexpr size_t player_starting_score = 25000;
    static constexpr size_t player_target_score = 30000;
};

template< typename ConfigRiichi >
struct RuleSetRiichi : RuleSet {
    static constexpr size_t num_players = ConfigRiichi::num_players;

    static constexpr size_t player_starting_score = ConfigRiichi::player_starting_score;
    static constexpr size_t player_target_score = ConfigRiichi::player_target_score;

    static constexpr size_t num_dora_indicators = 5;
};

using RuleSetRiichiDefaultConfig = RuleSetRiichi< DefaultConfigRiichi >;

} // namespace ruleset
} // namespace mahjcalc

#endif
