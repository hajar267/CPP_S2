#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include<string>
#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<algorithm>


class BitcoinExchange{
    private:
        std::map<int,double> data;
        int date;

    public:
        void ParsingData(void);
        void ParseLine(std::string line);
        int CheckDate(std::string& date);
        int helper(std::string& num);
        void GetFile(char *file);
        int ParseFile(std::string& line);
        double CheckValue(std::string& value);
        void FindDate(double value);
        void Print(int date);
        BitcoinExchange();
        ~BitcoinExchange();
};

#endif
