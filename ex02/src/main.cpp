#include "MutantStack.hpp"
#include <list>



void test_1(){

std::cout << "\t Subject test" << std::endl;
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << "Doing mstack.top() " << mstack.top() << std::endl;
std::cout << "Printing size of mstack before pop " << mstack.size() << std::endl;
std::cout << "Doing  mstack.pop()"<< std::endl;
mstack.pop();
std::cout << "Printing size of mstack " << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
std::cout << "Looping over the mstack" << std::endl;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
}

void test_2(){

std::cout << "\t Subject test, but with list" << std::endl;
std::list<int> mstack;
mstack.push_back(5);
mstack.push_back(17);
std::cout << "Doing mstack.back() " << mstack.back() << std::endl;
std::cout << "Printing size of mstack before pop " << mstack.size() << std::endl;
std::cout << "Doing  mstack.pop_back()"<< std::endl;
mstack.pop_back();
std::cout << "Printing size of mstack " << mstack.size() << std::endl;
mstack.push_back(3);
mstack.push_back(5);
mstack.push_back(737);
mstack.push_back(0);
std::list<int>::iterator it = mstack.begin();
std::list<int>::iterator ite = mstack.end();
++it;
--it;
std::cout << "Looping over the mstack" << std::endl;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
}



int main(){


	test_1();
	test_2();
	return 0;
}