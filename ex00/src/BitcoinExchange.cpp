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
	std::ifstream inputFile(file);
	if(!inputFile.is_open())
		throw std::runtime_error("Error: Cannot open input file");
	std::string str;
	if(!std::getline(inputFile, str))
		throw std::runtime_error("Error: Input file is empty");
	if(str != "date | value")
		throw std::runtime_error("Error: Wrong input file format");
	while (std::getline(inputFile, str))
		parseStr(str);
}

void BitcoinExchange::parseStr(std::string& str){
	size_t separator = str.find('|');
	if(separator == std::string::npos){
		std::cerr << "NO separator between date and value found";
		return ;
	}
	std::string date = str.substr(0, separator);
	std::string value = str.substr(separator + 1);
	std::erase(date, ' ');
	std::erase(value, ' ');

	if(confirmDate(date) && confirmValue(value)){
		auto rate = findRate(date);
		if(rate < 0)
			return ;
		auto result = std::stof(value) * rate;
		std::cout << date << " => " << result << std::endl;
	}

}