#include "BitcoinExchange.hpp"

#include <exception>
#include <fstream>

BitcoinExchange::BitcoinExchange(){
	loadData();
}

void BitcoinExchange::loadData(){
	std::ifstream database("data/data.csv");
	if(!database.is_open())
		throw std::runtime_error("Error: Cannot open database");
	
}