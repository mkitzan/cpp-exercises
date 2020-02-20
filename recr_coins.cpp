#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using coins_iterator = std::vector<size_t>::const_iterator;

size_t recr_min_coins(coins_iterator coin, coins_iterator end, size_t target)
{
	if (coin == end || *coin == 1)
	{
		return target;
	}

	auto val{ *coin };
	auto min{ std::numeric_limits<size_t>::max() };
	int num{ static_cast<int>(target / val) };
	++coin;

	while (num >= 0)
	{
		min = std::min(min, recr_min_coins(coin, end, target - (val * num)) + num);
		--num;
	}

	return min;
}

size_t min_coins(std::vector<size_t> const& coins, size_t target)
{
	return recr_min_coins(coins.begin(), coins.end(), target);
}

int main()
{
	std::vector<size_t> coins{ 25, 10, 5, 1 };

	std::cout << min_coins(coins, 31) << '\n';

	return 0;
}
