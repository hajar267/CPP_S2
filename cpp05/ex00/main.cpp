#include <iostream>
#include"Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat("hajar ", 0);
    }
    catch(std::exception& e){
        std::cout<<"exceptions caught : "<< e.what() <<std::endl;
    }
}