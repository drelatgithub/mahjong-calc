#ifndef MAHJCALC_RULE_PIECE_HPP
#define MAHJCALC_RULE_PIECE_HPP

#include "common.hpp"
#include "rule/piece-type.hpp"

namespace mahjcalc {

constexpr size_t RIICHI_PIECE_PER_TYPE = 4;
constexpr size_t RIICHI_NUM_PIECE_TYPE = 34;
constexpr size_t RIICHI_NUM_PIECE = RIICHI_NUM_PIECE_TYPE * RIICHI_PIECE_PER_TYPE;

struct Piece { PieceType type; size_t id; };

constexpr Piece RIICHI_PIECES[] {
    {PieceType::M1, 0}, {PieceType::M1, 1}, {PieceType::M1, 2}, {PieceType::M1, 3},
    {PieceType::M2, 0}, {PieceType::M2, 1}, {PieceType::M2, 2}, {PieceType::M2, 3},
    {PieceType::M3, 0}, {PieceType::M3, 1}, {PieceType::M3, 2}, {PieceType::M3, 3},
    {PieceType::M4, 0}, {PieceType::M4, 1}, {PieceType::M4, 2}, {PieceType::M4, 3},
    {PieceType::M5, 0}, {PieceType::M5, 1}, {PieceType::M5, 2}, {PieceType::M5, 3},
    {PieceType::M6, 0}, {PieceType::M6, 1}, {PieceType::M6, 2}, {PieceType::M6, 3},
    {PieceType::M7, 0}, {PieceType::M7, 1}, {PieceType::M7, 2}, {PieceType::M7, 3},
    {PieceType::M8, 0}, {PieceType::M8, 1}, {PieceType::M8, 2}, {PieceType::M8, 3},
    {PieceType::M9, 0}, {PieceType::M9, 1}, {PieceType::M9, 2}, {PieceType::M9, 3},
    {PieceType::P1, 0}, {PieceType::P1, 1}, {PieceType::P1, 2}, {PieceType::P1, 3},
    {PieceType::P2, 0}, {PieceType::P2, 1}, {PieceType::P2, 2}, {PieceType::P2, 3},
    {PieceType::P3, 0}, {PieceType::P3, 1}, {PieceType::P3, 2}, {PieceType::P3, 3},
    {PieceType::P4, 0}, {PieceType::P4, 1}, {PieceType::P4, 2}, {PieceType::P4, 3},
    {PieceType::P5, 0}, {PieceType::P5, 1}, {PieceType::P5, 2}, {PieceType::P5, 3},
    {PieceType::P6, 0}, {PieceType::P6, 1}, {PieceType::P6, 2}, {PieceType::P6, 3},
    {PieceType::P7, 0}, {PieceType::P7, 1}, {PieceType::P7, 2}, {PieceType::P7, 3},
    {PieceType::P8, 0}, {PieceType::P8, 1}, {PieceType::P8, 2}, {PieceType::P8, 3},
    {PieceType::P9, 0}, {PieceType::P9, 1}, {PieceType::P9, 2}, {PieceType::P9, 3},
    {PieceType::S1, 0}, {PieceType::S1, 1}, {PieceType::S1, 2}, {PieceType::S1, 3},
    {PieceType::S2, 0}, {PieceType::S2, 1}, {PieceType::S2, 2}, {PieceType::S2, 3},
    {PieceType::S3, 0}, {PieceType::S3, 1}, {PieceType::S3, 2}, {PieceType::S3, 3},
    {PieceType::S4, 0}, {PieceType::S4, 1}, {PieceType::S4, 2}, {PieceType::S4, 3},
    {PieceType::S5, 0}, {PieceType::S5, 1}, {PieceType::S5, 2}, {PieceType::S5, 3},
    {PieceType::S6, 0}, {PieceType::S6, 1}, {PieceType::S6, 2}, {PieceType::S6, 3},
    {PieceType::S7, 0}, {PieceType::S7, 1}, {PieceType::S7, 2}, {PieceType::S7, 3},
    {PieceType::S8, 0}, {PieceType::S8, 1}, {PieceType::S8, 2}, {PieceType::S8, 3},
    {PieceType::S9, 0}, {PieceType::S9, 1}, {PieceType::S9, 2}, {PieceType::S9, 3},
    {PieceType::E, 0}, {PieceType::E, 1}, {PieceType::E, 2}, {PieceType::E, 3},
    {PieceType::S, 0}, {PieceType::S, 1}, {PieceType::S, 2}, {PieceType::S, 3},
    {PieceType::W, 0}, {PieceType::W, 1}, {PieceType::W, 2}, {PieceType::W, 3},
    {PieceType::N, 0}, {PieceType::N, 1}, {PieceType::N, 2}, {PieceType::N, 3},
    {PieceType::Haku, 0}, {PieceType::Haku, 1}, {PieceType::Haku, 2}, {PieceType::Haku, 3},
    {PieceType::Hatsu, 0}, {PieceType::Hatsu, 1}, {PieceType::Hatsu, 2}, {PieceType::Hatsu, 3},
    {PieceType::Chun, 0}, {PieceType::Chun, 1}, {PieceType::Chun, 2}, {PieceType::Chun, 3}
};
static_assert(sizeof(RIICHI_PIECES) / sizeof(Piece) == RIICHI_NUM_PIECE);

constexpr Piece riichi_piece(size_t index) { return RIICHI_PIECES[index]; }

} // namespace mahjcalc

#endif
