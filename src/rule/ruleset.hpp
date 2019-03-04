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

    // Detailed game settings
    static constexpr bool enable_yaku_chitoitsu = true;
    static constexpr bool enable_yaku_kokushi_musou = true;
    static constexpr size_t max_kan_allowed = 4;
    static constexpr size_t num_dora_indicators = 0;
};

} // namespace ruleset
} // namespace mahjcalc

#endif
