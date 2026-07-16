#include "PmergeMe.hpp"
#include <algorithm>
#include <string>


// parser
// checks for basic mistakes and loads both vec and deq
void PmergeMe::parseInput(int ac, char **av){
	if(ac < 2)
		throw std::runtime_error("Error. Usage: PmergeMe 1 2 3 4 5");
	for (auto i = 1; i < ac; ++i)
	{
		size_t len;
		int num = std::stoi(av[i], &len);
		if(len != std::string(av[i]).length())
			throw std::runtime_error("Error: wrong input");
		if(num < 0)
			throw std::runtime_error("Error: negative numbers are not allowed");
		_vec.push_back(num);
		_deq.push_back(num);
	}
}

void PmergeMe::printVec(){
	for(auto& it : _vec)
		std::cout << it << " ";
	std::cout << std::endl;
}

void PmergeMe::printDeq(){
	for(auto& it : _deq)
		std::cout << it << " ";
	std::cout << std::endl;
}


