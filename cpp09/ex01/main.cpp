#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr<<"err in args"<<std::endl;
        return 1;
    }
    RPN test;
    test.ParseLine(av[1]);
    return 0;
}
