#ifndef RPN_HPP
#define RPN_HPP

#include<string>
#include<iostream>
#include<sstream>
#include<stack>

class RPN{
    private:
        std::stack<double> num;

    public:
        void ParseLine(std::string line);
        bool IsOperator(std::string& op);
        bool IsNumber(std::string& num);
};

#endif
