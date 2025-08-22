#include "BitcoinExchange.hpp"

void BitcoinExchange::datelogic(int num, int flag){
    if (flag == 1 && (num > 2025 || num < 2009)){
        throw std::runtime_error("Error: bad input => ");
    }
    if (flag == 2 && (num < 1 || num > 12)){
        throw std::runtime_error("Error: bad input => ");
    }
    if(flag == 3 && (num < 1 || num > 31)){
        throw std::runtime_error("Error: bad input => ");
    }
}

void BitcoinExchange::helper(std::string& num, int flag){
    if (num.empty()){
        throw std::runtime_error("Error: bad input => ");
    }
    std::stringstream ss(num);
    std::string rem;
    int nm;
    ss>>nm;
    if(ss>>rem){
        throw std::runtime_error("Error: bad input => ");
    }
    if (isdate == 1){
        datelogic(nm, flag);
    }
}

void BitcoinExchange::CheckDate(std::string& date){
    std::stringstream ss(date);
    std::string year, month, day, remain;
    getline(ss,year,'-') && getline(ss,month,'-') && getline(ss,day);
    helper(year, 1); helper(month, 2); helper(day, 3);
    std::stringstream dt;
    dt<<year<<month<<day;
    int result;
    dt>>result;
    this->date = result;
}

void BitcoinExchange::ParseLine(std::string line){
    std::string date;
    std::string prc;
    std::stringstream ss(line);
    getline(ss,date,',') && getline(ss,prc);
    isdate = 0;
    CheckDate(date);
    std::stringstream pr(prc);
    double price;
    pr>>price;
    std::string remain;
    if (pr>>remain){
        throw std::runtime_error("Error: bad input => ");
    }
    data[this->date] = price;
}

void BitcoinExchange::ParsingData(void){
    std::ifstream datafile("data.csv");
    if(!datafile.is_open()){
        throw std::runtime_error("Error: could not open file");
    }
    std::string line;
    getline(datafile, line);
    while(getline(datafile, line)){
        try{
            ParseLine(line);
        }
        catch(std::exception& e){
            std::cerr<<e.what()<< line <<std::endl;
        }
    }
    datafile.close();
}

double BitcoinExchange::CheckValue(std::string& value){
    if (value.empty()){
        throw std::runtime_error("Error: bad input => ");
    }
    std::stringstream ss(value);
    std::string rem;
    double v = 0;
    if (!(ss>>v)){
        throw std::runtime_error("Error: bad input => ");
    }
    if (v < 0){
        throw std::logic_error("Error: not a positive number.");
    }
    if (v > 1000){
        throw std::logic_error("Error: too large a number.");
    }
    if (ss>>rem){
        throw std::runtime_error("Error: bad input => ");
    }
    return v;
}

void BitcoinExchange::Print(int date){
    std::stringstream ss;
    ss<<date;
    std::string splt;
    ss>>splt;
    std::cout<<splt.substr(0, 4)<<"-"<<splt.substr(4, 2)<<"-"<<splt.substr(6,2);
}

void BitcoinExchange::FindDate(double value){
    std::map<int,double>::iterator it = data.upper_bound(this->date);
    if (it != data.begin()){
        it--;
        Print(it->first);
        std::cout<< " => " << value << " = " <<value * it->second<<std::endl;
    }
    else{
        std::map<int,double>::iterator it = data.begin();
        Print(it->first);
        std::cout<< " => " << value << " = " <<value * it->second<<std::endl;
    }
}

int BitcoinExchange::ParseFile(std::string& line){
    if (line.empty()){
        return 0;
    }
    std::stringstream ss(line);
    std::string date, value;
    getline(ss,date,'|') && getline(ss,value);
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);
    if (isHeader == 1 && date == "date" && value == "value"){
        return 0;
    }
    isdate = 1;
    CheckDate(date);
    double v = CheckValue(value);
    if(v < 0){
        return 0;
    }
    FindDate(v);
    return 1;
}

void BitcoinExchange::GetFile(char *file){
    std::ifstream fl(file);
    if(!fl.is_open()){
        throw std::runtime_error("Error: could not open file");
    }
    std::string line;
    getline(fl, line);
    try {
        isHeader = 1;
        ParseFile(line);
    }
    catch(std::runtime_error& e) {
        std::cerr<<e.what()<<line<<std::endl;
    }
    catch(std::logic_error& e){
        std::cerr<<e.what()<<std::endl;
    }
    isHeader = 0;
    while(getline(fl, line)){
        try{
            ParseFile(line);
        }
        catch(std::runtime_error& e) {
            std::cerr<<e.what()<<line<<std::endl;
        }
        catch(std::logic_error& e){
            std::cerr<<e.what()<<std::endl;
        }
    }
}

BitcoinExchange::BitcoinExchange(): date(0), isHeader(0){

}

BitcoinExchange::~BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
    this->data = obj.data;
    this->date = obj.date;
    this->isHeader = obj.isHeader;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
    if (this != &obj){
        this->data = obj.data;
        this->date = obj.date;
        this->isHeader = obj.isHeader;
    }
    return *this;
}
