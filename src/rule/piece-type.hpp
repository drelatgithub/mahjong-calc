#ifndef MAHJCALC_RULE_PIECE_TYPE_HPP
#define MAHJCALC_RULE_PIECE_TYPE_HPP

#include <cstdint>
#include <type_traits>

#include "common.hpp"

namespace mahjcalc {

constexpr size_t NUM_PIECE_TYPE = 35; // Including Undefined

// Red Doras are not considered here
enum class PieceType {
    M1, M2, M3, M4, M5, M6, M7, M8, M9,
    P1, P2, P3, P4, P5, P6, P7, P8, P9,
    S1, S2, S3, S4, S5, S6, S7, S8, S9,
    E, S, W, N,
    Haku, Hatsu, Chun,
    Undefined
};
using PieceTypeUnderlying = std::underlying_type<PieceType>;
constexpr PieceTypeUnderlying underlying(PieceType p) { return static_cast<PieceTypeUnderlying>(p); }

enum class PieceTypeCat {
    Man, Pin, Sou, Kazehai, Sangenpai, Undefined
};
constexpr PieceTypeCat CATEGORY_OF_PIECE_TYPE[] {
    // Man
    PieceTypeCat::Man, PieceTypeCat::Man, PieceTypeCat::Man,
    PieceTypeCat::Man, PieceTypeCat::Man, PieceTypeCat::Man,
    PieceTypeCat::Man, PieceTypeCat::Man, PieceTypeCat::Man,
    // Pin
    PieceTypeCat::Pin, PieceTypeCat::Pin, PieceTypeCat::Pin,
    PieceTypeCat::Pin, PieceTypeCat::Pin, PieceTypeCat::Pin,
    PieceTypeCat::Pin, PieceTypeCat::Pin, PieceTypeCat::Pin,
    // Sou
    PieceTypeCat::Sou, PieceTypeCat::Sou, PieceTypeCat::Sou,
    PieceTypeCat::Sou, PieceTypeCat::Sou, PieceTypeCat::Sou,
    PieceTypeCat::Sou, PieceTypeCat::Sou, PieceTypeCat::Sou,
    // Kaze
    PieceTypeCat::Kazehai, PieceTypeCat::Kazehai, PieceTypeCat::Kazehai, PieceTypeCat::Kazehai,
    // Sangen
    PieceTypeCat::Sangenpai, PieceTypeCat::Sangenpai, PieceTypeCat::Sangenpai,
    // Undefined
    PieceTypeCat::Undefined
};
constexpr PieceTypeCat category(PieceType p) { return CATEGORY_OF_PIECE_TYPE[underlying(p)]; }

using PieceTypeNum = std::uint_fast8_t;
constexpr PieceTypeNum NUMBER_OF_PIECE_TYPE[] {
    /* Man */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Pin */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Sou */ 1, 2, 3, 4, 5, 6, 7, 8, 9,
    /* Kaze */ 0, 0, 0, 0,
    /* Sangen */ 0, 0, 0,
    /* Undefined */ 0
};
constexpr PieceTypeNum number(PieceType p) { return NUMBER_OF_PIECE_TYPE[underlying(p)]; }

constexpr PieceType DORA_OF_PIECE_TYPE[] {
    // Man
    PieceType::M2, PieceType::M3, PieceType::M4,
    PieceType::M5, PieceType::M6, PieceType::M7,
    PieceType::M8, PieceType::M9, PieceType::M1,
    // Pin
    PieceType::P2, PieceType::P3, PieceType::P4,
    PieceType::P5, PieceType::P6, PieceType::P7,
    PieceType::P8, PieceType::P9, PieceType::P1,
    // Sou
    PieceType::S2, PieceType::S3, PieceType::S4,
    PieceType::S5, PieceType::S6, PieceType::S7,
    PieceType::S8, PieceType::S9, PieceType::S1,
    // Kaze
    PieceType::S, PieceType::W, PieceType::N, PieceType::E,
    // Sangen
    PieceType::Hatsu, PieceType::Chun, PieceType::Haku,
    // Undefined
    PieceType::Undefined
};
constexpr PieceType get_dora_from_indicator(PieceType p) { return DORA_OF_PIECE_TYPE[underlying(p)]; }

} // namespace mahjcalc

#endif
