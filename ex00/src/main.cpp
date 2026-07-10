#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Fatal. Usage: ./btc <input_file>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange bitcoin;
		std::string file = av[1];
		bitcoin.processInputFile(file);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
	

}