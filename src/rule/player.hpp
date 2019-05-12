#ifndef Mahjcalc_Rule_Player_Hpp
#define Mahjcalc_Rule_Player_Hpp

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

} // namespace mahjcalc

#endif
