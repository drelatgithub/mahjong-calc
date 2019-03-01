#ifndef MAHJCALC_RULE_RULESET_HPP
#define MAHJCALC_RULE_RULESET_HPP

#include "common.hpp"

namespace mahjcalc {
namespace ruleset {

struct RuleSet {
    // Game setup
    static constexpr mc_ushort num_players = 4;
    enum class TopCategory {
        Riichi, Custom
    };
    static constexpr TopCategory top_category = TopCategory::Riichi;
};

} // namespace ruleset
} // namespace mahjcalc

#endif
