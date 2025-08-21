#include"BitcoinExchange.hpp"

int main (int ac, char **av){
    try {
        if (ac != 2){
            throw std::runtime_error("Error: could not open file");
        }
        BitcoinExchange test;
        test.ParsingData();
        test.GetFile(av[1]);
    }
    catch(std::exception& e) {
        std::cerr<<e.what()<<std::endl;
    }
}
