#include"BitcoinExchange.hpp"

int main(int ac,char** av){
    if (ac != 2){
        std::cerr<<"err in args"<<std::endl;
        return 1;
    }
    BitcoinExchange test;
    test.ParsingData();
    test.GetFile(av[1]);
}