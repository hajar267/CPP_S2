#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <exception>

class PmergeMe{
    private:
        std::vector<int> vec;
        std::vector<size_t> jaco_seq;
        std::vector<int> main_vec;

        std::deque<int> deq;
        std::deque<int> jaco_deq;
        std::deque<int> main_deq;

    public:
        PmergeMe();
        ~PmergeMe();

        void ParseVec(char **av, int ac);
        void Print(void);
        void SortVec(std::vector<int>& nums);
        void Jacobs(size_t size);
        void Jacobs_helper(std::vector<size_t>& jaco, size_t size);
        void InsertVec(std::vector<int>& pend, int odd);
        void TimeVec(void);
    
        void ParseDeq(char **av, int ac);
        void PrintDeq(void);
        void SortDeq(std::deque<int>& nums);
        void JacobsDeq(size_t size);
        void Jacobs_helperDeq(std::deque<size_t>& jaco, size_t size);
        void InsertDec(std::deque<int>& pend, int odd);
        void TimeDec(void);
};

#endif
