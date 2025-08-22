#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other){
    this->deq = other.deq;
    this->vec = other.vec;
    this->jaco_seq = other.jaco_seq;
    this->jaco_deq = other.jaco_deq;
    this->main_deq = other.main_deq;
    this->main_vec = other.main_vec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    if (this != &other){
        this->deq = other.deq;
        this->vec = other.vec;
        this->jaco_seq = other.jaco_seq;
        this->jaco_deq = other.jaco_deq;
        this->main_deq = other.main_deq;
        this->main_vec = other.main_vec;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::ParseVec(char **av, int ac){
    timeval tv;
    gettimeofday(&tv, NULL);
    long long first = (long long)tv.tv_sec * 1000000 + tv.tv_usec;
    for (int i=1; i < ac; i++){
        std::stringstream ss(av[i]);
        int j;
        std::string remain;
        if (!(ss>>j)){
            throw std::runtime_error("Expected just positif integers .");
        }
        if (ss>>remain || j < 0){
            throw std::runtime_error("Expected just positif integers .");
        }
        vec.push_back(j);
    }
    SortVec(vec);
    gettimeofday(&tv, NULL);
    long long final = (long long)tv.tv_sec * 1000000 + tv.tv_usec;
    vec_time = final - first;
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
    InsertVec(pend, odd);
    return ;
}


void PmergeMe::InsertVec(std::vector<int>& pend, int odd){
    Jacobs(pend.size());
    size_t jaco_size = jaco_seq.size();
    size_t i = 0;
    while( i < jaco_size){
        int value = pend[jaco_seq[i] - 1];
        std::vector<int>::iterator it = lower_bound(main_vec.begin(), main_vec.end(), value);
        if (it != main_vec.end()){
            if (*it == value){
                throw std::runtime_error(" duplication ");
            }
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

void PmergeMe::ParseDeq(char **av, int ac){
    timeval tv;
    gettimeofday(&tv, NULL);
    long long first = (long long)tv.tv_sec * 1000000 + tv.tv_usec;

    for (int i = 1; i < ac; i++){
        std::stringstream ss(av[i]);
        int j;
        std::string remain;
        if (!(ss>>j)){
            throw std::runtime_error("Expected just positif integers .");
        }
        if (ss>>remain || j < 0){
            throw std::runtime_error("Expected just positif integers .");
        }
        deq.push_back(j);
    }
    SortDeq(deq);
    gettimeofday(&tv, NULL);
    long long final = (long long)tv.tv_sec * 1000000 + tv.tv_usec;
    deq_time = final - first;
}

void PmergeMe::JacobsDeq(size_t size){
    std::deque<size_t> jaco;
    if (size <= 3){
        for (size_t i = 1; i <= size; i++){
            jaco_deq.push_back(i);
        }
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
    Jacobs_helperDeq(jaco, size);

}

void PmergeMe::Jacobs_helperDeq(std::deque<size_t>& jaco, size_t size){
    size_t i = 1;
    jaco_deq.push_back(jaco[0]);
    while(jaco_deq.size() < size){
        size_t first = jaco[i - 1];
        size_t next = 0;
        if (i >= jaco.size()){
            next = size + 1;
        }
        else {
            next = jaco[i];
            jaco_deq.push_back(next);
        }
        for(size_t j = next - 1; j > first; j--){
            jaco_deq.push_back(j);
        }
        i++;
    }
}

void PmergeMe::InsertDec(std::deque<int>& pend, int odd){
    JacobsDeq(pend.size());
    size_t jaco_size = jaco_deq.size();
    size_t i = 0;
    while( i < jaco_size){
        int value = pend[jaco_deq[i] - 1];
        std::deque<int>::iterator it = lower_bound(main_deq.begin(), main_deq.end(), value);
        if (it != main_deq.end()){
            if (*it == value){
                throw std::runtime_error(" duplication ");
            }
            main_deq.insert(it, value);
        }
        else {
            main_deq.push_back(value);
        }
        i++;
    }
    if (odd != -1){
        std::deque<int>::iterator it = lower_bound(main_deq.begin(), main_deq.end(), odd);
        if (it != main_deq.end()){
            main_deq.insert(it, odd);
        }
        else {
            main_deq.push_back(odd);
        }
    }
    jaco_deq.clear();

}

void PmergeMe::SortDeq(std::deque<int>& nums){
    if (nums.size() == 1){
        main_deq.push_back(nums[0]);
        return ;
    }
    std::deque<int> main;
    std::deque<int> pend;

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

    SortDeq(main);

    InsertDec(pend, odd);
    return ;
}

void PmergeMe::Print(void){
    std::cout<<"Befor : ";
    for( size_t i=0; i < vec.size(); i++){
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"After : ";
    for( size_t i=0; i < main_vec.size(); i++){
        std::cout<<main_vec[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Time to process a range of "<<vec.size()<<" elements with std::vector<> : "<< vec_time << "us" <<std::endl;
    std::cout<<"Time to process a range of "<<deq.size()<<" elements with std::deque<> : "<< deq_time << "us" <<std::endl;
}
