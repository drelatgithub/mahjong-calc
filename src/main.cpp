#include <iostream>

#include "experiment/tenhou.hpp"
#include "rule/ruleset/majsoul.hpp"

int main() {

    using namespace mahjcalc;
	using namespace std;
	using R = ruleset::RuleSetMajsoulDefaultConfig;

	experiment::tenhou_probability<R>(200'000'000);

	system("pause");
    return 0;
}
