#ifndef MAHJCALC_EXPERIMENT_TENHOU_HPP
#define MAHJCALC_EXPERIMENT_TENHOU_HPP

#include <algorithm> // copy
#include <iostream>
#include <iterator> // begin

#include "rule/complete-hand.hpp"
#include "shuffle.hpp"

namespace mahjcalc {
namespace experiment {

template< typename Rule >
inline void tenhou_probability(const size_t max_iter, const size_t output_interval=500000) {
	static constexpr auto full_hand_size = Hand::hand_size;
	static constexpr auto iter_per_shuffle = num_tiles<Rule>() / full_hand_size;

	std::array< size_t, num_tiles<Rule>() > arr;

	size_t num_tenhou = 0;
	for(size_t i = 0; i < max_iter; ++i) {
		if(i % iter_per_shuffle == 0) {
			re_shuffle(arr);
		}

		Hand h{};
		std::copy(
			arr.begin() + (i % iter_per_shuffle) * full_hand_size,
			arr.begin() + (i % iter_per_shuffle + 1) * full_hand_size,
			std::begin(h.tiles)
		);

		if (is_complete_hand<Rule>(h)) {
			++num_tenhou;
		}
		if (i % output_interval == 0)
            std::cout << "Iteration " << i << ": tenhou " << num_tenhou << std::endl;
	}

	std::cout << "Tenhou statistics: " << num_tenhou << "/" << max_iter
        << " (prob " << (1.0 * num_tenhou) / max_iter << ")" << std::endl;
}

} // namespace experiment
} // namespace mahjcalc

#endif
