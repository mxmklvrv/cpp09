#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
auto easyFind(T& kunteynir, int n)
{
	auto it = std::find(kunteynir.begin(), kunteynir.end(), n);
	if(it == kunteynir.end())
		throw std::runtime_error("nowhere to be found");
	return it;
}
