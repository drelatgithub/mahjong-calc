#ifndef Mahjcalc_Rule_Player_Hpp
#define Mahjcalc_Rule_Player_Hpp

#include "common.hpp"
#include "rule/hand.hpp"

namespace mahjcalc {

struct PlayerOperation {
    enum class Type {
        Discard, RiichiDiscard,
        Tsumo, Ron,
        Chii, Pon, Kan,
        KyuushuuKyuuhai,
        Cancel
    };

    mc_uif8 player_id;
    Type type;
    size_t code;
};

struct PlayerStatus {
    bool can_discard;
    bool can_riichi;
    bool can_tsumo;
    bool can_ron;
    bool can_chii;
    bool can_pon;
    bool can_kan;
    bool can_kyuushuukyuuhai;
};

} // namespace mahjcalc

#endif
