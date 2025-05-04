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
    addNumber(int num);
    shortestSpan();
    longestSpan();
};

#endif
