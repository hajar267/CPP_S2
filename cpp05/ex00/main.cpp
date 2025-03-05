#include <iostream>
#include"Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat("hajar ", 180);
    }
    catch(std::exception& e){
        std::cout<<Bureaucrat.getName()<<" : "<< e.what() <<std::endl;
    }
}