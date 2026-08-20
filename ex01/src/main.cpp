#include "RPN.hpp"
#include <iostream>

int main (int ac, char **av){
    if(ac != 2){
        std::cerr << "Error, usage: ./RPN <your input>" << std::endl;
        return 1;
    }
    try{
        RPN rpn;
        std::string input = av[1];
        rpn.decider(input);
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
