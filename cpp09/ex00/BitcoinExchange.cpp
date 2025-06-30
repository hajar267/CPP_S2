#include "BitcoinExchange.hpp"

int BitcoinExchange::helper(std::string& num){
    if (num.empty()){
        std::cerr<<"error in date"<<std::endl; //we can check it here or just skip the first one
        return 0;
    }
    std::stringstream ss(num);
    std::string rem;
    int nm;
    ss>>nm;
    if(ss>>rem){
        std::cerr<<"error in date"<<std::endl;
        return 0;
    }
    return 1;
}

int BitcoinExchange::CheckDate(std::string& date){
    std::stringstream ss(date);
    std::string year, month, day, remain;
    getline(ss,year,'-') && getline(ss,month,'-') && getline(ss,day);
    if (!helper(year) || !helper(month) || !helper(day)){
        return 0;
    }
    std::stringstream dt;
    dt<<year<<month<<day;
    int result;
    dt>>result;
    this->date = result;
    return 1;
}

void BitcoinExchange::ParseLine(std::string line){
    std::string date;
    std::string prc;
    std::stringstream ss(line);
    getline(ss,date,',') && getline(ss,prc);
    if(!CheckDate(date)){
        return;
    }
    std::stringstream pr(prc);
    double price;
    pr>>price;
    std::string remain;
    if (pr>>remain){
        std::cerr<<"error in price"<<std::endl;
        return;
    }
    data[this->date] = price;
}

void BitcoinExchange::ParsingData(void){
    std::ifstream datafile("data.csv");
    if(!datafile.is_open()){
        std::cerr<<"failed to open file"<<std::endl;
        return ;
    }
    std::string line;
    getline(datafile, line);
    while(getline(datafile, line)){
        ParseLine(line);
    }
    //     std::map<std::string,double>::iterator it;
    // for(it = data.begin(); it != data.end(); ++it){
    //     std::cout<<it->first<<","<<it->second<<std::endl;
    // }
    datafile.close();
}

double BitcoinExchange::CheckValue(std::string& value){
    std::stringstream ss(value);
    double v;
    ss>>v;
    if (v < 0 || v > 1000){
        std::cerr<<"error in value"<<std::endl;
        return -1;
    }
    return v;
}

void BitcoinExchange::FindDate(double value){
    std::map<int,double>::iterator it = data.upper_bound(this->date);
    if (it != data.begin()){
        it--;
        std::stringstream ss;
        std::cout<<it->first<< " | " << value * it->second<<std::endl;
    }
    else{
        std::cerr<<"error"<<std::endl;
    }
}

int BitcoinExchange::ParseFile(std::string& line){
    std::stringstream ss(line);
    std::string date, value;
    getline(ss,date,'|') && getline(ss,value);
    // strim all spaces from date and send it to checkdate function
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    if(!CheckDate(date)){
        return 0;
    }
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);
    double v=CheckValue(value);
    if(v<0){
        return 0;
    }
    FindDate(v);
    // std::cout<<this->date<<" | "<<value<<std::endl;
    return 1;
}

void BitcoinExchange::GetFile(char *file){
    std::ifstream fl(file);
    if(!fl.is_open()){
        std::cerr<<"failed to open file"<<std::endl;
        return ;
    }
    std::string line;
    while(getline(fl, line)){
        ParseFile(line);
    }
}

BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::~BitcoinExchange(){

}

