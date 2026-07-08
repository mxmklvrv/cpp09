#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stdexcept>
#include <limits>

class Span
{
	private:
		unsigned int _len;
		std::vector<int> _cont;
	public:
		Span() = delete;
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;

	template<typename Iterator>
		void addRange(Iterator first, Iterator last){
			if(_cont.size() + std::distance(first, last) > _len)
				throw std::runtime_error("Already full");
			_cont.insert(_cont.end(), first, last);
		}

};


