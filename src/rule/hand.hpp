#ifndef MAHJCALC_RULE_HAND_HPP
#define MAHJCALC_RULE_HAND_HPP

#include <optional>

#include "common.hpp"
#include "rule/orientation.hpp"
#include "rule/piece.hpp"

namespace mahjcalc {

enum class NakiType {
    None, Chii, Pon, Daiminkan, Kakan, Ankan // Nukidora is not considered here
};

struct Hand {
    static constexpr size_t HAND_SIZE = 14;
    static constexpr size_t MAX_NAKI_GROUPS = 4;

    Piece       pieces[HAND_SIZE];
    NakiType    nakis[MAX_NAKI_GROUPS];

    std::optional<Orientation> naki_orientations[MAX_NAKI_GROUPS];
    std::optional<Orientation> tile_source;
    // The pieces[HAND_SIZE - 1] is always the new draw or discard
    // Naki (open calls) should always be arranged to the right,
    //    but Kans are still stored as 3 pieces
    // Example 1:
    //     ------------------------------------  ----------------  ----------------  ------
    //     | 1p | 2p | 3p | 4p | 3p | 5p | 3p |  | 7s | 8s | 9s |  | W  | W  | W  |  | 3p |
    //     ------------------------------------  ----------------  ----------------  ------
    //     ^ need not be ordered                 ^ chii            ^ kakan           ^ discard
    //          -------------------------------  ----------------  ----------------
    //          | None         | None         |  | Chii         |  | Kakan        |  << Naki Type
    //          -------------------------------  ----------------  ----------------
    //          |              |              |  | Left         |  | Opposing     |  << Naki orientation
    //          -------------------------------  ----------------  ----------------
};

} // namespace mahjcalc

#endif
