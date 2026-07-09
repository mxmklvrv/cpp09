#include "BitcoinExchange.hpp"

#include <exception>
#include <fstream>
#include <chrono>
#include <sstream>

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

bool BitcoinExchange::confirmDate(std::string& date){
	std::istringstream is(date);

	int year, month, day;
	char dash_1, dash_2, extra;

	if(!(is >> year >> dash_1 >> month >> dash_2 >> day))
		return false;
	if(is >> extra)
		return false;
	if(dash_1 != '-' || dash_2 != '-')
		return false;
	if(month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	std::chrono::year_month_day ymd{
		std::chrono::year{year},
		std::chrono::month{static_cast<unsigned>(month)},
		std::chrono::day{static_cast<unsigned>day}
	};

	return ymd.ok();
}
