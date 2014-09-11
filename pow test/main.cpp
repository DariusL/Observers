#include <iostream>
#include "Observers.h"

using Comparator = Observers<int, bool, int>;
using WithVoid = Observers < int, void, float > ;
int main()
{
	auto a = Comparator::Register(5, [](int a){return a > 8; });
	auto b = Comparator::Register(5, [](int a){return a > 10; });
	auto c = Comparator::Register(5, [](int a){return a > 12; });
	auto d = Comparator::Register(5, [](int a){return a > 14; });
	auto e = Comparator::Register(5, [](int a){return a > 16; });

	auto count = Comparator::Notify<int>(5, 13, 0, [](int &acc, bool val){if (val)acc++; });

	auto a1 = WithVoid::Register(5, [](float a){});
	WithVoid::Notify(5, 1.0f);

	std::cout << count << " passed" << std::endl;

	system("pause");
	return 0;
}