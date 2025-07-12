#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

class PmergeMe{
    private:
        std::vector<int> vec;
        std::deque<int> deq;

    public:
        PmergeMe();
        ~PmergeMe();
        void Parse(char **av, int ac);
        void Print(void);
        void SortVec(std::vector<int>& nums);
        void SortDeq(void);
        void TimeVec(void);
        void TimeDec(void);
        void InsertVec(void);
        void Jacobs(size_t size);
        void InsertDec(void);
};

#endif
