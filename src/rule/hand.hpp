#ifndef MAHJCALC_RULE_HAND_HPP
#define MAHJCALC_RULE_HAND_HPP

#include "common.hpp"
#include "rule/piece.hpp"

namespace mahjcalc {

struct Hand {
    static constexpr size_t HAND_SIZE = 14;

    Piece pieces[HAND_SIZE];
};

} // namespace mahjcalc

#endif
