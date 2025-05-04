#include "Span.hpp"

Span::Span(unsigned int N): _N(N){}

Span::~Span(){

}

Span::addNumber(int num){
    if (spans.size() >= _N){
        throw std::out_of_range("out of range");
    }
    spans.push_back(num);
}

Span::shortestSpan(){
    std::vector<int>::iterator min = std::min_element(spans.begin(), spans.end());
    std::cout<<*min<<std::endl;
}

Span::longestSpan(){
    std::vector<int>::iterator max = std::max_element(spans.begin(), spans.end());
    std::cout<<*max<<std::endl;
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _elements(other._elements) {}

