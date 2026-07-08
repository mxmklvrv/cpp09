#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <deque>


void test_1(){
	try
	{
		std::cout << "\tVECTOR" << std::endl;
		std::vector<int> technique = {1, 2, 3, 4, 5};
		std::cout << "technique = {1, 2, 3, 4, 5}" << std::endl;
		std::cout << "Searching for 2 and " << *easyFind(technique, 2) << " found." << std::endl;
		std::cout << "Searching for 5 and " << *easyFind(technique, 5) << " found." << std::endl;
		std::cout << "Searching for 69 and " << *easyFind(technique, 69) << " found." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void test_2(){
	try
	{
		std::cout << "\tLIST" << std::endl;
		std::list<int> sinicyn = {1, 2, 3, 4, 5};
		std::cout << "sinicyn = {1, 2, 3, 4, 5}" << std::endl;
		std::cout << "Searching for 2 and " << *easyFind(sinicyn, 2) << " found." << std::endl;
		std::cout << "Searching for 5 and " << *easyFind(sinicyn, 5) << " found." << std::endl;
		std::cout << "Searching for 69 and " << *easyFind(sinicyn, 69) << " found." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void test_3(){
	try
	{
		std::cout << "\tDEQUE" << std::endl;
		std::deque<int> kalmar = {1, 2, 3, 4, 5};
		std::cout << "kalmar = {1, 2, 3, 4, 5}" << std::endl;
		std::cout << "Searching for 2 and " << *easyFind(kalmar, 2) << " found." << std::endl;
		std::cout << "Searching for 5 and " << *easyFind(kalmar, 5) << " found." << std::endl;
		std::cout << "Searching for 69 and " << *easyFind(kalmar, 69) << " found." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
void test_4(){
	try
	{
		std::cout << "\tEMPTY KUNTEYNIR" << std::endl;
		std::deque<int> blev;
		std::cout << "std::deque<int> blev;" << std::endl;
		std::cout << "Searching for 69 and " << *easyFind(blev, 69) << " found." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
int main(){
	test_1();
	test_2();
	test_3();
	test_4();
}