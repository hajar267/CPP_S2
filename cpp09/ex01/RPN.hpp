#ifndef RPN_HPP
#define RPN_HPP

#include<string>
#include<iostream>
#include<sstream>
#include<stack>
#include<exception>

class RPN{
    private:
        std::stack<double> num;

    public:
        void Execution(std::string line);
        bool IsOperator(std::string& op);
        bool IsNumber(std::string& num);
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
};

#endif
