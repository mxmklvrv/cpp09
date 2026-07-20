#include "PmergeMe.hpp"
#include <chrono>
#include <exception>


int main(int ac, char** av)
{
    try
    {
        PmergeMe sorter;

        sorter.parseInput(ac, av);

        std::cout << "Before: ";
        sorter.printVec();

        auto start = std::chrono::high_resolution_clock::now();
        sorter.sortVec();
        auto end = std::chrono::high_resolution_clock::now();

        double vecTime =
            std::chrono::duration<double, std::micro>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        sorter.sortDeq();
        end = std::chrono::high_resolution_clock::now();

        double deqTime =
            std::chrono::duration<double, std::micro>(end - start).count();

        std::cout << "After: ";
        sorter.printVec();

        std::cout
            << "Time to process a range of "
            << ac - 1
            << " elements with std::vector : "
            << vecTime
            << " us"
            << std::endl;

        std::cout
            << "Time to process a range of "
            << ac - 1
            << " elements with std::deque : "
            << deqTime
            << " us"
            << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}