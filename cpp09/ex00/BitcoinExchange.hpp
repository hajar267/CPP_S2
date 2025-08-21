#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include<string>
#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<exception>


class BitcoinExchange{
    private:
        std::map<int,double> data;
        int date;
        bool isHeader;

    public:
        void ParsingData(void);
        void ParseLine(std::string line);
        void CheckDate(std::string& date);
        void helper(std::string& num);
        void GetFile(char *file);
        int ParseFile(std::string& line);
        double CheckValue(std::string& value);
        void FindDate(double value);
        void Print(int date);
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();
};

#endif
