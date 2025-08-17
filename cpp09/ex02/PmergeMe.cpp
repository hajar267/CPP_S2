#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

void PmergeMe::Print(void){
    for( size_t i=0; i < main_vec.size(); i++){
        std::cout<<main_vec[i]<<" ";
    }
    std::cout<<std::endl;
}

void Printt(std::vector<int>& vec){
    for( size_t i=0; i < vec.size(); i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

void Printtt(std::vector<size_t>& vec){
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
    SortVec(vec);
    Print();
}

void PmergeMe::SortVec(std::vector<int>& nums){
    if (nums.size() == 1){
        main_vec.push_back(nums[0]);
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
    Printt(main);

    InsertVec(pend, odd);
    return ;
    // call function that accept main and pend and insert pend into main

    //generate a sequence of jacobs stor this sequence in a vector and the push the remain indices

    //insert each element from the pend into the main

    // also insert the odd one if exist
}


void PmergeMe::InsertVec(std::vector<int>& pend, int odd){
    Jacobs(pend.size());
    Printtt(jaco_seq);
    size_t jaco_size = jaco_seq.size();
    size_t i = 0;
    while( i < jaco_size){
        size_t value = pend[jaco_seq[i] - 1];
        std::vector<int>::iterator it = lower_bound(main_vec.begin(), main_vec.end(), value);
        if (it != main_vec.end()){
            main_vec.insert(it, value);
        }
        else {
            main_vec.push_back(value);
        }
        i++;
    }
    if (odd != -1){
        std::vector<int>::iterator it = lower_bound(main_vec.begin(), main_vec.end(), odd);
        if (it != main_vec.end()){
            main_vec.insert(it, odd);
        }
        else {
            main_vec.push_back(odd);
        }
    }
    jaco_seq.clear();
}


void PmergeMe::Jacobs(size_t size){
    std::vector<size_t> jaco;
    if (size <= 3){
        for (size_t i = 1; i <= size; i++){
            jaco_seq.push_back(i);
        }
    // Printt(jaco_seq);
        return ;
    }
    jaco.push_back(0);
    jaco.push_back(1);
    size_t i = 2;
    size_t value = 0;
    while (value < size){
        value = jaco[i - 1] + 2 * jaco[i - 2];
        if (value >= size)
            break;
        jaco.push_back(value);
        i++;
    }
    jaco.erase(jaco.begin(), jaco.begin() + 2);
    Jacobs_helper(jaco, size);
    // Printt(jaco_seq);
}

void PmergeMe::Jacobs_helper(std::vector<size_t>& jaco, size_t size){
    size_t i = 1;
    jaco_seq.push_back(jaco[0]);
    while(jaco_seq.size() < size){
        size_t first = jaco[i - 1];
        size_t next = 0;
        if (i >= jaco.size()){
            next = size + 1;
        }
        else {
            next = jaco[i];
            jaco_seq.push_back(next);
        }
        for(size_t j = next - 1; j > first; j--){
            jaco_seq.push_back(j);
        }
        i++;
    }
}