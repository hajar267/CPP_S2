#ifndef SPAN_HPP
#define SPANE_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int _N;
    std::vector<int> spans;

public:
    Span(unsigned int N);
    Span();
    ~Span();
    Span(const Span& other);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    template <typename iter>
    void AddToSpan(iter begin, iter end) {
    unsigned int count = std::distance(begin, end);
    if (spans.size() + count > _N) {
        throw std::out_of_range("out of range");
    }
    spans.insert(spans.end(), begin, end);
    }
};

#endif
