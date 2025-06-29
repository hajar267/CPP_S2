#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include<string>
#include<iostream>
#include<map>
#include<fstream>
#include<sstream>


class BitcoinExchange{
    private:
        std::map<std::string,double> data;

    public:
        void ParsingData(void);
        void ParseLine(std::string line);
        int CheckDate(std::string& date);
        int helper(std::string& num);
        void GetFile(char *file);
        int ParseFile(std::string& line);
        BitcoinExchange();
        ~BitcoinExchange();
};

#endif
