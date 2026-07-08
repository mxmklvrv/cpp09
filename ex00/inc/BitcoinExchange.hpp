#pragma once

#include <map>
#include <iostream>

// map is used here because it naturally have key & value pair
// sorts keys(aka dates) automatically

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other) = delete;
	BitcoinExchange& operator=(const BitcoinExchange& other) = delete;
	~BitcoinExchange() = default;

	void loadData();
	
};

