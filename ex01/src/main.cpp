#include "Span.hpp"
#include <iostream>
#include <vector>


void test_1(){

std::cout << "\tSubject test" << std::endl;

Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}

void test_2(){
	try
	{
	std::cout << "\tExtra number to already full span" << std::endl;
	Span sp(4);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);
	std::cout << "Trying to add 5th nummber to the full span of 4 and " <<std::endl;
	sp.addNumber(5);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void test_3(){
	try
	{
	std::cout << "\tEmpty span test" << std::endl;
	Span sp(4);
	std::cout << "Trying to find shortest span " <<std::endl;
	sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
	std::cout << "\tOne nummber in span " << std::endl;
	Span sp2(4);
	std::cout << "Trying to find longest span " <<std::endl;
	sp2.addNumber(5);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
void test_4(){
	try
	{
	std::cout << "\tEmpty span test" << std::endl;
	Span sp(4);
	std::cout << "Trying to find shortest span " <<std::endl;
	sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
	std::cout << "\tOne nummber in span " << std::endl;
	Span sp2(4);
	std::cout << "Trying to find longest span " <<std::endl;
	sp2.addNumber(5);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void test_5(){
	try
	{
	std::cout << "\tXXL Span test (69k nums)" << std::endl;
	Span sp(69000);
	std::vector<int> nums;
	for(auto i = 0; i < 69000; ++i)
		nums.push_back(rand());
	sp.addRange(nums.begin(), nums.end());
	std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span is " << sp.longestSpan() << std::endl;

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
	test_5();
}
