#include "PmergeMe.hpp"

int main(int ac, char **av){
    try {
        if (ac < 2){
            throw std::runtime_error("number of arguments not enogh ");
        }
        PmergeMe test;
        test.ParseVec(av, ac);
        test.ParseDeq(av, ac);
    }
    catch(std::exception& e){
        std::cerr<<e.what()<<std::endl;
    }
}
