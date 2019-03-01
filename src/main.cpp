#include <iostream>

#include "rule/hand.hpp"
#include "rule/ruleset/majsoul.hpp"
#include "rule/winning-hand.hpp"

int main() {

    using namespace mahjcalc;
	using namespace std;

	Hand hand1{
		{0, 5, 8, 13, 16, 20, 24, 28, 32, 112, 109, 110, 108, 113},
		{NakiType::None, NakiType::None, NakiType::None, NakiType::Pon}
	};
	Hand hand2{
		{112, 5, 8, 13, 16, 20, 0, 28, 32, 24, 109, 110, 108, 113},
		{NakiType::None, NakiType::None, NakiType::Chii, NakiType::Pon}
	};
	Hand kokushi{
		{112, 124, 128, 132, 104, 108, 0, 36, 32, 72, 68, 110, 116, 120},
		{NakiType::None, NakiType::None, NakiType::None, NakiType::None}
	};
	Hand chitoi{
		{0,1,2,3,4,5,6,7,8,9,10,11,100,101},
		{}
	};

	cout << is_winning_hand<ruleset::RuleSetMajsoulDefaultConfig>(hand1) << endl;
	cout << is_winning_hand<ruleset::RuleSetMajsoulDefaultConfig>(hand2) << endl;
	cout << is_winning_hand<ruleset::RuleSetMajsoulDefaultConfig>(kokushi) << endl;
	cout << is_winning_hand<ruleset::RuleSetMajsoulDefaultConfig>(chitoi) << endl;

	system("pause");
    return 0;
}
