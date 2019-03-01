#include <iostream>

#include "rule/hand.hpp"

int main() {

    using namespace mahjcalc;
	using namespace std;

    Hand hand {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
        {NakiType::None, NakiType::None, NakiType::None, NakiType::None}
    };

	cout << hand.tiles[3].index << endl;

    return 0;
}
