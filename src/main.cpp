#include <array>
#include <iostream>
#include <iterator>

#include "rule/hand.hpp"
#include "rule/ruleset/majsoul.hpp"
#include "rule/complete-hand.hpp"
#include "shuffle.hpp"

int main() {

    using namespace mahjcalc;
	using namespace std;
	using R = ruleset::RuleSetMajsoulDefaultConfig;

	std::array< size_t, num_tiles<R>() > arr;
	static constexpr auto full_hand_size = Hand::hand_size;
	static constexpr auto iter_per_shuffle = num_tiles<R>() / full_hand_size;
	const size_t max_iter = 200000000;
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
		if (i % 100000 == 0) cout << "iter " << i << endl;
		if (is_complete_hand<R>(h)) {
			for (auto& t : h.tiles) cout << name(tile<R>(t).type) << ' ';
			cout << endl;
			++num_tenhou;
		}
	}
	cout << "Tenhou: " << num_tenhou << "/" << max_iter << endl;

	system("pause");
    return 0;
}
