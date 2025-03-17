#include "Serializer.hpp"

    
    uintptr_t Serializer::serialize(Data* ptr){
        uintptr_t ser = reinterpret_cast<uintptr_t>(ptr);
        return ser;
    }

    Data* Serializer::deserialize(uintptr_t raw){
        Data* ptr = reinterpret_cast<Data*>(raw);
        return ptr;
    }

    Data::Data(int val) : value(val) {}