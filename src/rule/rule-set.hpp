#ifndef Mahjcalc_Rule_RuleSet_Hpp
#define Mahjcalc_Rule_RuleSet_Hpp

#include "common.hpp"

namespace mahjcalc {
namespace ruleset {

struct RuleSet {
    // Game setup
    static constexpr mc_uif8 num_players = 4;
    enum class TopCategory {
        Riichi, Custom
    };
    static constexpr TopCategory top_category = TopCategory::Riichi;

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
