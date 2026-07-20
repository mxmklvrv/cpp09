#pragma once

#include <deque>
#include <vector>
#include <iostream>

class PmergeMe
{
private:
	std::vector<int> _vec;
	std::deque<int> _deq;
public:
	PmergeMe() = default;
	PmergeMe(const PmergeMe& other) = delete;
	PmergeMe& operator=(const PmergeMe& other) = delete;
	~PmergeMe() = default;

	void parseInput(int ac, char **av);
	void printVec();
	void printDeq();
	void sortVec();
	void sortDeq();


	std::vector<int> fordVec(std::vector<int>& vec);
	std::deque<int> fordDeq(std::deque<int>& deq);
	
	std::vector<int> getOrder(size_t n);
};

