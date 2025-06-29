#include "BitcoinExchange.hpp"

int BitcoinExchange::helper(std::string& num){
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
    std::string year, month, day;
    getline(ss,year,'-') && getline(ss,month,'-') && getline(ss,day);
    if (!helper(year) || !helper(month) || !helper(day)){
        return 0;
    }
    int y,m,d;
    ss>>y;
    ss>>m;
    ss>>d;
    //maybe i will check later for the correct day year and month
    // std::cout<<date<<" - ";
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
    //store date and price in map
    data[date] = price;
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

int BitcoinExchange::ParseFile(std::string& line){
    std::stringstream ss(line);
    std::string date, value;
    getline(ss,date,'|') && getline(ss,value);
    std::cout<<date<<" | "<<value<<std::endl;
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
        // ParseFile
    }
}

BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::~BitcoinExchange(){

}
