#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

void PmergeMe::Print(void){
    for( size_t i=0; i < vec.size(); i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

void PmergeMe::Parse(char **av, int ac){
    for (int i=1; i < ac; i++){
        std::stringstream ss(av[i]);
        int j;
        std::string remain;
        ss>>j;
        if (ss>>remain || j < 0){
            return ; //error
        }
        vec.push_back(j);
    }
    Print();
}

void PmergeMe::SortVec(std::vector<int>& nums){
    if (nums.size() <= 1){
        return ;
    }
    std::vector<int> main;
    std::vector<int> pend;

    for (size_t i=0; i < nums.size() - 1; i+=2){
        int a = nums[i];
        int b = nums[i + 1];
        if (a < b){
            main.push_back(b);
            pend.push_back(a);
        }
        else {
            main.push_back(a);
            pend.push_back(b);
        }
    }
    int odd = -1;
    if (nums.size()%2 != 0){
        odd = nums[nums.size()-1];
    }

    SortVec(main);

    //generate a sequence of jacobs stor this sequence in a vector and the push the remain indices

    //insert each element from the pend into the main

    // also insert the odd one if exist
}


void PmergeMe::InsertVec(void){

}

void PmergeMe::Jacobs(size_t size){
    std::vector<size_t> jaco;
    int j =1;
    while (j < size){
        jaco.push_back(j);
        size_t jc = (j - 1) + 2 * (j - 2);
    }
}