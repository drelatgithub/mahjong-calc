#ifndef MAHJCALC_RULE_PIECE_HPP
#define MAHJCALC_RULE_PIECE_HPP

#include "common.hpp"
#include "src/piece-type.hpp"

namespace mahjcalc {

constexpr size_t RIICHI_PIECE_PER_TYPE = 4;
constexpr size_t RIICHI_NUM_PIECE_TYPE = 34;
constexpr size_t RIICHI_NUM_PIECE = RIICHI_NUM_PIECE_TYPE * RIICHI_PIECE_PER_TYPE;

struct Piece { PieceType type; size_t id; };

} // namespace mahjcalc

#endif
