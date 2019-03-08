#ifndef MAHJCALC_RULE_PLAYER_HPP
#define MAHJCALC_RULE_PLAYER_HPP

#include "common.hpp"
#include "rule/hand.hpp"

namespace mahjcalc {

struct Operation {
    enum class Type {
        Discard, RiichiDiscard,
        Tsumo, Ron,
        Chii, Pon, Kan,
        KyuushuuKyuuhai,
        Cancel
    };
    Type type;
    size_t code;
};

struct Player {
    Hand hand;
};

} // namespace mahjcalc

#endif
