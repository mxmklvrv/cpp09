#include  "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

void RPN::calculate(std::string& input){
	std::istringstream stream(input);
	std::string token;
	while(stream >> token){
		if(token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
			handleOperator(token[0]);
		else if (token.length() == 1 && std::isdigit(token[0]))
			_data.push(token[0] - '0');
		else
			throw std::runtime_error("Error: invalid token - " + token);
	}
	if(_data.size() != 1)
		throw std::runtime_error("Error: bad input")
	std::cout << "result: " << _data.top() << std::endl;
}