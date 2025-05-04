#include "Span.hpp"

int main()
{
    try{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
std::cout<<"====================="<<std::endl;

std::vector<int> numbers;
// numbers.push_back(5);
// numbers.push_back(2);
// numbers.push_back(25);
// numbers.push_back(15);
// numbers.push_back(10);
for(int i=0; i < 1000 ; i++){
    numbers.push_back(i);
}
Span span(1000);
span.AddToSpan(numbers.begin(), numbers.end());

std::cout << span.shortestSpan() << std::endl;
std::cout << span.longestSpan() << std::endl;

int arr[] = {10, 20, 30, 40, 50};
span.AddToSpan(arr, arr + 5);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught as expected: " << e.what() << std::endl;
    }

    return (0);
}
