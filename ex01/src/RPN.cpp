#include  "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

// parser 
// checks if token is a num or sign
// pushes to the stack or goes to handle oper 
void RPN::decider(std::string& input){
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
		throw std::runtime_error("Error: bad input");
	std::cout << "result: " << _data.top() << std::endl;
}

// pops 2 nums 
// makes calc based on the sign 
// checks for errors
void RPN::handleOperator(char token){
    if(_data.size() < 2)
        throw std::runtime_error("Error: expression is incomplete.");
    int second = _data.top();
    _data.pop();
    int first = _data.top();
    _data.pop();
    long res = 0;

    switch(token){
        case '+':
            res = static_cast<long>(first) + static_cast<long>(second);
            break;
        case '-':
            res = static_cast<long>(first) - static_cast<long>(second);
            break;
        case '*':
            res = static_cast<long>(first) * static_cast<long>(second);
            break;
        case '/':
            if(second == 0)
                throw std::runtime_error("Error: division by 0");
            res = static_cast<long>(first) / static_cast<long>(second);
            break;
    }
    if(res > INT_MAX || res < INT_MIN)
        throw std::runtime_error("Error: overflow");
    _data.push(res);
}