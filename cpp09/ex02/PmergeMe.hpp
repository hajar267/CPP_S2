#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <exception>
#include <sys/time.h>

class PmergeMe{
    private:
        std::vector<int> vec;
        std::vector<size_t> jaco_seq;
        std::vector<int> main_vec;
        long long vec_time;

        std::deque<int> deq;
        std::deque<int> jaco_deq;
        std::deque<int> main_deq;
        long long deq_time;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void ParseVec(char **av, int ac);
        void Print(void);
        void SortVec(std::vector<int>& nums);
        void Jacobs(size_t size);
        void Jacobs_helper(std::vector<size_t>& jaco, size_t size);
        void InsertVec(std::vector<int>& pend, int odd);
        long long vec_geter(void);
        void TimeVec(void);

        void ParseDeq(char **av, int ac);
        void PrintDeq(void);
        void SortDeq(std::deque<int>& nums);
        void JacobsDeq(size_t size);
        void Jacobs_helperDeq(std::deque<size_t>& jaco, size_t size);
        void InsertDec(std::deque<int>& pend, int odd);
        long long dec_geter(void);
        void TimeDec(void);
};

#endif
