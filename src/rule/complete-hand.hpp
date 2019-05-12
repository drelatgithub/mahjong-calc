#ifndef Mahjcalc_Rule_CompleteHand_Hpp
#define Mahjcalc_Rule_CompleteHand_Hpp

#include<iostream>

#include "common.hpp"
#include "rule/hand.hpp"

namespace mahjcalc {

// The hand completeness does not require yakus.
template< typename Rule >
bool is_complete_hand(const Hand& h) {
    constexpr auto num_tile_types = TileSet<Rule::top_category, Rule::num_players>::num_tile_types;
    mc_uif8 hand_layout_non_naki[num_tile_types] {};

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
            hand_layout_non_naki[underlying(TileType::Hk)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::Ht)] >= 1 &&
            hand_layout_non_naki[underlying(TileType::Cn)] >= 1
        ) {
            // Debug
            std::cout<<"Kokushi musou"<<std::endl;
            return true;
        }
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
            if(is_chitoitsu) {
                // Debug
                std::cout<<"Chitoitsu"<<std::endl;
                return true;
            }
        }
    }

    // Search for mentsus and a pair
    // Try precedence: Koutsu -> Jantou -> Shuntsu
    static constexpr mc_uif8 try_none    = 0;
    static constexpr mc_uif8 try_koutsu  = 1;
    static constexpr mc_uif8 try_jantou  = 2;
    static constexpr mc_uif8 try_shuntsu = 3;

    static constexpr auto      max_num_mentsus = Hand::max_naki_groups;
    static constexpr mc_uif8 max_num_jantous = 1;
    static constexpr auto      max_num_groups  = max_num_mentsus + max_num_jantous;
    const            auto      num_mentsus     = num_remaining_tiles / 3;
    const            mc_uif8 num_jantous     = 1;
    const            auto      num_groups      = num_mentsus + num_jantous;

    size_t cur_num_mentsus = 0;
    size_t cur_num_jantous = 0;
    const auto cur_num_groups = [&] { return cur_num_mentsus + cur_num_jantous; };

    size_t    groups       [max_num_groups] {};
    mc_uif8 group_tries  [max_num_groups] {};
    bool      group_certain[max_num_groups] {};

    size_t type_index = 0;

    const auto is_shuntsu_available = [&] {
        return can_start_shuntsu<Rule>(type_index) && cur_num_mentsus < num_mentsus && (
            hand_layout_non_naki[type_index + 1] >= 1 &&
            hand_layout_non_naki[type_index + 2] >= 1
        );
    };
    const auto is_jantou_available = [&] {
        return cur_num_jantous < num_jantous;
    };
    const auto is_koutsu_available = [&] {
        return cur_num_mentsus < num_mentsus;
    };
    const auto is_certain_before = [&] {
        return cur_num_groups() == 0 || group_certain[cur_num_groups() - 1];
    };
    const auto make_before_certain = [&] {
        if(cur_num_groups()) group_certain[cur_num_groups() - 1] = true;
    };
    const auto is_complete = [&] {
        return cur_num_mentsus == num_mentsus && cur_num_jantous == num_jantous;
    };
    const auto apply_shuntsu = [&](bool certain) {
        --hand_layout_non_naki[type_index];
        --hand_layout_non_naki[type_index + 1];
        --hand_layout_non_naki[type_index + 2];
        groups[cur_num_groups()]        = type_index;
        group_tries[cur_num_groups()]   = try_shuntsu;
        group_certain[cur_num_groups()] = certain;
        ++cur_num_mentsus;
        // Reset further tries
        if(cur_num_groups() < num_groups) group_tries[cur_num_groups()] = try_none;
        if(hand_layout_non_naki[type_index] == 0) ++type_index;
    };
    const auto apply_koutsu = [&](bool certain) {
        hand_layout_non_naki[type_index] -= 3;
        groups[cur_num_groups()]        = type_index;
        group_tries[cur_num_groups()]   = try_koutsu;
        group_certain[cur_num_groups()] = certain;
        ++cur_num_mentsus;
        // Reset further tries
        if(cur_num_groups() < num_groups) group_tries[cur_num_groups()] = try_none;
        if(hand_layout_non_naki[type_index] == 0) ++type_index;
    };
    const auto apply_jantou = [&](bool certain) {
        hand_layout_non_naki[type_index] -= 2;
        groups[cur_num_groups()]        = type_index;
        group_tries[cur_num_groups()]   = try_jantou;
        group_certain[cur_num_groups()] = certain;
        ++cur_num_jantous;
        // Reset further tries
        if(cur_num_groups() < num_groups) group_tries[cur_num_groups()] = try_none;
        if(hand_layout_non_naki[type_index] == 0) ++type_index;
    };
    const auto revert = [&] {
        type_index = groups[cur_num_groups() - 1];
        switch(group_tries[cur_num_groups() - 1]) {
        case try_koutsu:
            hand_layout_non_naki[type_index] += 3;
            --cur_num_mentsus;
			break;
        case try_jantou:
            hand_layout_non_naki[type_index] += 2;
            --cur_num_jantous;
			break;
        case try_shuntsu:
            ++hand_layout_non_naki[type_index];
            ++hand_layout_non_naki[type_index + 1];
            ++hand_layout_non_naki[type_index + 2];
            --cur_num_mentsus;
            break;
        }
    };

    while(
        type_index < num_tile_types
        && (cur_num_mentsus < num_mentsus || cur_num_jantous < num_jantous)
    ) {
        if(
            type_index == underlying(TileType::P1) ||
            type_index == underlying(TileType::S1) ||
            category(type_index) == TileTypeCat::Kazehai ||
            category(type_index) == TileTypeCat::Sangenpai
        ) make_before_certain();

        switch(hand_layout_non_naki[type_index]) {
        case 0:
            // Everything before can be viewed as certain
            make_before_certain();
            ++type_index;
            break;
        case 1:
            // Must be Shuntsu or non-complete
            if(is_shuntsu_available() && group_tries[cur_num_groups()] < try_shuntsu) {
                // Try shuntsu
                apply_shuntsu(is_certain_before());
            } else {
                // Shuntsu not available
                if(is_certain_before()) return false;
                else revert();
            }
            break;
        case 2:
            // Can be Shuntsu, Jantou or non-complete
            if(is_jantou_available() && group_tries[cur_num_groups()] < try_jantou) {
                // Try jantou
                apply_jantou(false);
            } else if(is_shuntsu_available() && group_tries[cur_num_groups()] < try_shuntsu) {
                // Try shuntsu
                apply_shuntsu(is_certain_before());
            } else {
                // Neither shuntsu or jantou is avaiable
                if(is_certain_before()) return false;
                else revert();
            }
            break;
        case 3: case 4:
            // Can be any group or non-complete
            if(is_koutsu_available() && group_tries[cur_num_groups()] < try_koutsu) {
                // Try koutsu
                apply_koutsu(false);
            } else if(is_jantou_available() && group_tries[cur_num_groups()] < try_jantou) {
                // Try jantou
                apply_jantou(false);
            } else if(is_shuntsu_available() && group_tries[cur_num_groups()] < try_shuntsu) {
                // Try shuntsu
                apply_shuntsu(is_certain_before());
            } else {
                // No grouping is available
                if(is_certain_before()) return false;
                else revert();
            }
        }
    }

    // debug
    using namespace std;
    if(is_complete()) {
        for(size_t i = 0;i< cur_num_groups();++i) {
            switch(group_tries[i]){
            case try_koutsu:
                cout
                    << tile_type_name[groups[i]]<<' '
                    << tile_type_name[groups[i]]<<' '
                    << tile_type_name[groups[i]];
                break;
            case try_jantou:
                cout
                    << tile_type_name[groups[i]]<<' '
                    << tile_type_name[groups[i]];
                break;
            case try_shuntsu:
				cout
                    << tile_type_name[groups[i]]<<' '
                    << tile_type_name[groups[i]+1]<<' '
                    << tile_type_name[groups[i]+2];
                break;
            }
            cout << "     ";
        }
        cout<< endl;
    }

    return is_complete();
}

} // namespace mahjcalc

#endif
