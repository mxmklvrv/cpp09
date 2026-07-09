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
	std::string str;
	if(!std::getline(database, str))
		throw std::runtime_error("Error: Database empty");
	if(str != "date,exchange_rate")
		throw std::runtime_error("Error: Wrong database format");

	while(std::getline(database, str)){
		auto comma = str.find(',');
		std::string key = str.substr(0, comma);
		std::string value = str.substr(comma + 1);
		_data[key] = std::stof(value);
	}

}

void BitcoinExchange::processInputFile(std::string& file){
	
}