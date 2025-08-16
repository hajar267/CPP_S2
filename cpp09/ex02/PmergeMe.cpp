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
            std::cerr << "Error: Invalid argument '" << av[i] << "'" << std::endl;
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
    // call function that accept main and pend and insert pend into main

    //generate a sequence of jacobs stor this sequence in a vector and the push the remain indices

    //insert each element from the pend into the main

    // also insert the odd one if exist
}


void PmergeMe::InsertVec(std::vector<int>& main, std::vector<int>& pend){
    // using the jacobs sequence + the remain indices
    // using lower-bound to find the position to insert each element from pend into main
    // insert the specific element from pend with the specfic indices from jacobs sequence 
    // into the main in indice of returning of lower=bound
}

void PmergeMe::Jacobs(size_t size){
    std::vector<size_t> jaco;
    if (size <= 3){
        for (size_t i = 0; i < size; i++){
            jaco.push_back(i);
        }
        return ;
    }
    jaco.push_back(0);
    jaco.push_back(1);
    size_t i = 2;
    while (jaco.size() < size){
        size_t value = jaco[i - 1] + 2 * jaco[i - 2];
        jaco.push_back(value);
        i++;
        if (jaco[j] - jaco[j - 1] > 1){
            for(size_t i = j - 1 ; i > j - 1; i--){
                jaco.push_back(i);
            }
        }
        if ()
    }
}


/*
   generate jacobs sequence
   int i=0;
   while(i < size){}
*/