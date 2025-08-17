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
        std::vector<size_t> jaco_seq;
        std::vector<int> main_vec;
        std::deque<int> deq;

    public:
        PmergeMe();
        ~PmergeMe();
        void Parse(char **av, int ac);
        void Print(void);
        void SortVec(std::vector<int>& nums);
        void Jacobs_helper(std::vector<size_t>& jaco, size_t size);
        void SortDeq(void);
        void TimeVec(void);
        void TimeDec(void);
        void InsertVec(std::vector<int>& pend, int odd);
        void Jacobs(size_t size);
        void InsertDec(void);
};

#endif
