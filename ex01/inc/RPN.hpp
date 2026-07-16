#pragma once

#include <stack>
#include <string>

class RPN
{
private:
	std::stack<int> _data;
public:
	RPN() = default;
	RPN(const RPN& other) = delete;
	RPN& operator=(const RPN& other) = delete;
	~RPN() = default;

	void decider(std::string& input);
	void handleOperator(char token);

};