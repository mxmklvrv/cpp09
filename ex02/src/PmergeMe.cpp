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


std::vector<int> PmergeMe::fordVec(std::vector<int>& vec){
	// base case, with one num only, nothing to do here.
	if (vec.size() <= 1)
		return vec;
	// checks if input is odd. if so, svaing the last num to make pairs.
	bool hasOdd = (vec.size() % 2 != 0);
	int odd = 0;
	if(hasOdd)
		odd = vec.back();
	// creating a pairs
	std::vector<std::pair<int, int>> pairs;
	pairs.reserve(vec.size() / 2);

	for (size_t i = 0; i + 1 < vec.size(); i+= 2)
	{
		int first = vec[i];
		int second = vec[i + 1];
		if(first < second)
			std::swap(first, second);
		pairs.emplace_back(first, second);
	}

	// extracting winners
	std::vector<int> winners;
	winners.reserve(pairs.size());
	for(auto& pair : pairs)
		winners.push_back(pair.first);
}