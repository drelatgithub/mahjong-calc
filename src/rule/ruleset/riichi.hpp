#ifndef MAHJCALC_RULE_RULESET_RIICHI_HPP
#define MAHJCALC_RULE_RULESET_RIICHI_HPP

#include "rule/ruleset.hpp"

namespace mahjcalc {
namespace ruleset {

struct DefaultConfigRiichi {
    static constexpr size_t num_players = 4;
};

template< typename ConfigRiichi >
struct RuleSetRiichi : RuleSet {
    static constexpr size_t num_players = ConfigRiichi::num_players;
    static constexpr size_t num_dora_indicators = 5;
};

using RuleSetRiichiDefaultConfig = RuleSetRiichi< DefaultConfigRiichi >;

} // namespace ruleset
} // namespace mahjcalc

#endif
