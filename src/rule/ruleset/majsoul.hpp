#ifndef MAHJCALC_RULE_RULESET_MAJSOUL_HPP
#define MAHJCALC_RULE_RULESET_MAJSOUL_HPP

#include "rule/ruleset/riichi.hpp"

namespace mahjcalc {
namespace ruleset {

struct DefaultConfigMajsoul {
    constexpr static mc_uif8 num_players = 4;
    constexpr static mc_uif8 num_red_doras = 3;
    constexpr static bool kuitan = true;
    constexpr static bool tsumoson = true;
};

namespace internal {

template< typename ConfigMajsoul >
struct ConfigRiichiFromMajsoul {
    static constexpr mc_uif8 num_players = ConfigMajsoul::num_players;
};

} // namespace internal

template< typename ConfigMajsoul >
struct RuleSetMajsoul : RuleSetRiichi< internal::ConfigRiichiFromMajsoul<ConfigMajsoul> > {};

using RuleSetMajsoulDefaultConfig = RuleSetMajsoul< DefaultConfigMajsoul >;

} // namespace ruleset
} // namespace mahjcalc

#endif
