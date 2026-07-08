#include "Span.hpp"


// alloc anough memory at the very start
// to prevent reallocs and other bs.
Span::Span(unsigned int N) :_len(N){
	_cont.reserve(_len);
}

Span::Span(const Span& other) : _len(other._len), _cont(other._cont) {}

Span& Span::operator=(const Span& other){
	if(this != &other){
		_len = other._len;
		_cont = other._cont;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n){
	if(_cont.size() >= _len)
		throw std::runtime_error("Already full");
	_cont.push_back(n);
}

int Span::longestSpan() const{
	if(_cont.size() < 2)
		throw std::runtime_error("Cannot find longest span");
	int minVal = *std::min_element(_cont.begin(), _cont.end());
	int maxVal = *std::max_element(_cont.begin(), _cont.end());

	return maxVal - minVal;
}

int Span::shortestSpan() const{
	if(_cont.size() < 2)
		throw std::runtime_error("Cannot find shortest span");
	std::vector<int> temp(_cont);
	std::sort(temp.begin(), temp.end());

	int shortest = std::numeric_limits<int>::max();
	for(size_t i = 1; i < temp.size(); ++i)
		shortest = std::min(shortest, temp[i] - temp[i - 1]);
	return shortest;

}

