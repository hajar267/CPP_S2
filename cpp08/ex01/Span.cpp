#include "Span.hpp"

Span::Span(unsigned int N): _N(N){}

Span::~Span(){}
Span::Span(){}

void Span::addNumber(int num){
    if (spans.size() >= _N){
        throw std::out_of_range("out of range");
    }
    spans.push_back(num);
}

int Span::shortestSpan(){
    if (spans.size() <= 1){
        throw std::out_of_range("it should be at least 2 numbers");
    }
    std::vector<int> tmp = spans;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator it=tmp.begin();
    int min = *(it+1) - *it;
    for (; it != tmp.end() - 1; ++it){
        int current = *(it+1) - *it;
        if (current < min){
            min = current;
        }
    }
    return (min);
}

int Span::longestSpan(){
    if (spans.size() <= 1){
        throw std::out_of_range("it should be at least 2 numbers");
    }
    std::vector<int>::iterator max = std::max_element(spans.begin(), spans.end());
    std::vector<int>::iterator min = std::min_element(spans.begin(), spans.end());
    return (*max - *min);
}

Span::Span(const Span& other) : _N(other._N), spans(other.spans) {}

