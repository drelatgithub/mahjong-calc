#ifndef MAHJCALC_RULE_COMPLETE_HAND_HPP
#define MAHJCALC_RULE_COMPLETE_HAND_HPP

#include<iostream>

#include "common.hpp"
#include "rule/hand.hpp"

namespace mahjcalc {

// The hand completeness does not require yakus.
template< typename Rule >
bool is_complete_hand(const Hand& h) {
    constexpr auto num_tile_types = TileSet<Rule::top_category, Rule::num_players>::num_tile_types;
    mc_ushort hand_layout_non_naki[num_tile_types] {};

    size_t num_nakis = 0;
    for(size_t i = 0; i < Hand::max_naki_groups; ++i)
        if(h.nakis[i] != NakiType::None) ++num_nakis;
    const size_t num_remaining_tiles = Hand::hand_size - 1 - 3 * num_nakis; // Not including the last

    for(size_t i = 0; i < num_remaining_tiles; ++i)
        ++hand_layout_non_naki[underlying(tile<Rule>(h.tiles[i]).type)];
    ++hand_layout_non_naki[underlying(tile<Rule>(h.tiles[Hand::hand_size - 1]).type)];

    if constexpr (Rule::enable_yaku_kokushi_musou) {
        if(
            num_nakis == 0 &&
            hand_layout_non_naki[underlying(TileType::M1)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::M9)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::P1)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::P9)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::S1)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::S9)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::E)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::S)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::W)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::N)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::Haku)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::Hatsu)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::Chun)] >= 1
        ) return true;
    }

    if constexpr (Rule::enable_yaku_chitoitsu) {
        if(num_nakis == 0) {
            bool is_chitoitsu = true;
            for(size_t i = 0; i < num_tile_types; ++i) {
                if(hand_layout_non_naki[i] != 0 && hand_layout_non_naki[i] != 2) {
                    is_chitoitsu = false;
                    break;
                }
            }
            if(is_chitoitsu) return true;
        }
    }

    // TODO

    using namespace std;
    cout<<"num_nakis = "<<num_nakis<<endl;
    cout<<"num_remaining_tiles = "<<num_remaining_tiles<<endl;
    for(auto a:hand_layout_non_naki) cout <<(int)a<<' ';
    cout<<endl;

    return false; // TODO
}

} // namespace mahjcalc

#endif
