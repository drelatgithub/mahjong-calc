#ifndef Mahjcalc_Rule_RuleSet_Riichi_Hpp
#define Mahjcalc_Rule_RuleSet_Riichi_Hpp

#include "rule/rule-set.hpp"

namespace mahjcalc {
namespace ruleset {

namespace internal {

class RiichiRoundCounter {
public:
    static constexpr mc_uif8 max_num_winds = 4;
    static constexpr mc_uif8 num_rounds_per_wind = 4;

private:
    mc_uif8 wind_order_ = 0; // 0-3: ESWN
    mc_uif8 wind_round_ = 0; // 0-3: Round 1-4
    mc_uif8 honba_ = 0;

public:
    RiichiRoundCounter() = default;
    RiichiRoundCounter(const RiichiRoundCounter&) = default;
    RiichiRoundCounter& operator=(const RiichiRoundCounter&) = default;

    void inc(bool inc_honba) {
        if(inc_honba) ++honba_;
        else {
            if(wind_round_ + 1 >= num_rounds_per_wind) {
                ++wind_order_;
                wind_round_ = 0;
            } else {
                ++wind_round_;
            }
            honba_ = 0;
        }
    }

};

} // namespace internal

struct DefaultConfigRiichi {
    static constexpr size_t num_players = 4;

    static constexpr size_t player_starting_score = 25000;
    static constexpr size_t player_target_score = 30000;
};

template< typename ConfigRiichi >
struct RuleSetRiichi : RuleSet {
    static constexpr size_t num_players = ConfigRiichi::num_players;

    using RoundCounter = internal::RiichiRoundCounter;
    static constexpr size_t player_starting_score = ConfigRiichi::player_starting_score;
    static constexpr size_t player_target_score = ConfigRiichi::player_target_score;

    static constexpr size_t num_dora_indicators = 5;
};

using RuleSetRiichiDefaultConfig = RuleSetRiichi< DefaultConfigRiichi >;

} // namespace ruleset
} // namespace mahjcalc

#endif
