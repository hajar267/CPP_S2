#include"ScalarConverter.hpp"

bool isint(std::string& c){
	std::stringstream s(c);
	int j;
	s>>j;
	if (j){
		return true;
	}
	return false;
}

bool isitchar(std::string& c){
	if (c.length() == 1 && !std::isdigit(c[0]))
		return true;
	return false;
}

void ScalarConverter::convert(std::string value){
	char c;
	int i;
	float f;
	double d;
	if (isitchar(value))
	{
		c = value[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (value == "nanf" || value == "-inff" || value =="+inff"){
    	f = std::strtof(value.c_str(), NULL);
    	d = static_cast<double>(f);
		std::cout<< "char: impossible"<<"\nint: impossible"<<"\nfloat: "<< f <<"f\ndouble: "<< d <<std::endl;
		return ;
	}
	else if (value == "nan" || value == "-inf" || value == "+inf"){
		d = std::strtod(value.c_str(), NULL);
    	f = static_cast<float>(d);
		std::cout<< "char: impossible"<<"\nint: impossible"<<"\nfloat: "<< f <<"f\ndouble: "<< d <<std::endl;
		return ;
	}
	else if (value.find('.')!=std::string::npos && value.find('f')!=std::string::npos){
		std::stringstream flt(value);
		flt >> f;
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}
	else if (value.find('.')!=std::string::npos){
		std::stringstream dbl(value);
		dbl >> d;
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}
	else if (isint(value)){
		std::stringstream integer(value);
		integer >> i;
		c = static_cast<char>(i);
		d = static_cast<double>(i);
		f = static_cast<float>(i);
	}
	else{
		std::cout<<"no convertion !"<<std::endl;
		return ;
	}
	if (!std::isprint(c)){
		std::cout<<"char: Non displayable"<<std::endl;
	}
	else{
		std::cout<< "char : "<<c<<std::endl;
	}
	std::cout<<"int : "<<i<<"\nfloat : "<< std::fixed << std::setprecision(1)<<f<< "f" <<"\ndouble : "<<d<<std::endl;
}
