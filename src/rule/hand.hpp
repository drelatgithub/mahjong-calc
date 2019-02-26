#ifndef MAHJCALC_RULE_HAND_HPP
#define MAHJCALC_RULE_HAND_HPP

#include <optional>

#include "common.hpp"
#include "rule/orientation.hpp"
#include "rule/tile.hpp"

namespace mahjcalc {

enum class NakiType {
    None, Chii, Pon, Daiminkan, Kakan, Ankan // Nukidora is not considered here
};

struct Hand {
    static constexpr size_t HAND_SIZE = 14;
    static constexpr size_t MAX_NAKI_GROUPS = 4;

    size_t      tiles[HAND_SIZE];
    NakiType    nakis[MAX_NAKI_GROUPS];

    Orientation tile_source;

    // Meta data
    std::optional<Orientation> naki_orientations[MAX_NAKI_GROUPS];
    std::optional<Orientation> bakaze;
    std::optional<Orientation> jikaze;

    // The tiles[HAND_SIZE - 1] is always the new draw or discard.
    // Naki (open calls) should always be arranged to the right,
    //    but Kans are still stored as 3 tiles.
    // For Kakan, the orientation is the orientation of the previous Pon.
    // Example 1:
    //     ------------------------------------  ----------------  ----------------  ------
    //     | 1p | 2p | 3p | 4p | 3p | 5p | 3p |  | 7s | 8s | 9s |  | Hk | Hk | Hk |  | 3p |
    //     ------------------------------------  ----------------  ----------------  ------
    //     ^ need not be ordered                 ^ chii            ^ kakan           ^ discard
    //          -------------------------------  ----------------  ----------------
    //          | None         | None         |  | Chii         |  | Kakan        |  << Naki Type
    //          -------------------------------  ----------------  ----------------
    //          |              |              |  | Left         |  | Opposing     |  << Naki orientation
    //          -------------------------------  ----------------  ----------------
    // Example 2:
    //     ------------------------------------------------------------------  ------
    //     | 1s | 1p | 9s | 1m | 9m | 9p | E  | S  | W  | N  | Hk | Ht | Ch |  | 1s |
    //     ------------------------------------------------------------------  ------
    //     ^ need not be ordered                                               ^ draw
    //          -------------------------------------------------------------
    //          | None         | None         | None         | None         |  << Naki Type
    //          -------------------------------------------------------------
    //          |              |              |              |              |  << Naki orientation
    //          -------------------------------------------------------------
};

} // namespace mahjcalc

#endif
