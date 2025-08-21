#include "RPN.hpp"

int main(int ac, char **av){
    try{
        if (ac != 2){
            throw std::runtime_error("bad number of arguments");
        }
        RPN test;
        test.Execution(av[1]);
    }
    catch(std::exception& e){
        std::cerr<<e.what()<<std::endl;
    }
    return 0;
}
