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
            std::cerr<<"can't devide in 0"<<std::endl; //i should throw exception
        }
        return first / second;
    }
}

bool RPN::IsNumber(std::string& num){
    std::stringstream ss(num);
    int n = -1;
    ss>>n;
    if (n < 0 || n >= 10){
        std::cerr<<"err in num"<<std::endl;
        return false;
    }
    return true;
}

bool RPN::IsOperator(std::string& op){
    return (op == "+" || op == "-" || op == "*" || op == "/");
}

void RPN::ParseLine(std::string line){
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
                std::cerr<<"err num of opp doesn't match num of digits"<<std::endl;
            }
        }
        else if(IsNumber(numopr)){
            std::stringstream ss(numopr);
            double n;
            ss>>n;
            this->num.push(n);
        }
        else{
            std::cerr<<"not a number or opr"<<std::endl;
        }
    }
    if (this->num.size() == 1){
        std::cout<<this->num.top()<<std::endl;
    }
    else {
        std::cerr<<"err num of opp doesn't match num of digits"<<std::endl;
    }
}
