#include "RPN.hpp"

double Operations(double first, double second, std::string& op){
    if (op == "+"){
        return first + second;
    }
    else if(op == "-"){
        return first - second;
    }
    else if(op == "*"){
        return first * second;
    }
    else{
        if (second == 0){
            throw std::runtime_error("Cannot divide by zero");
        }
        return first / second;
    }
}

bool RPN::IsNumber(std::string& num){
    std::stringstream ss(num);
    int n = -1;
    if (!(ss>>n)){
        return false;
    }
    if (n < 0 || n >= 10){
        throw std::out_of_range("out of range 0-10");
    }
    return true;
}

bool RPN::IsOperator(std::string& op){
    return (op == "+" || op == "-" || op == "*" || op == "/");
}

void RPN::Execution(std::string line){
    std::stringstream ss(line);
    std::string numopr;
    while(ss >> numopr){
        if(IsOperator(numopr)){
            if (this->num.size()>=2){
                double second = this->num.top();
                this->num.pop();
                double first = this->num.top();
                this->num.pop();
                double result = Operations(first, second, numopr);
                this->num.push(result);
            }
            else{
                throw std::runtime_error("Error: number of operators doesn't match number of digits");
            }
        }
        else if(IsNumber(numopr)){
            std::stringstream ss(numopr);
            double n;
            ss>>n;
            this->num.push(n);
        }
        else{
            throw std::runtime_error("Error: expected number or operator");
        }
    }
    numopr.clear();
    if (this->num.size() == 1){
        std::cout<<this->num.top()<<std::endl;
    }
    else {
        throw std::runtime_error("Error: number of operators doesn't match number of digits");
    }
}
