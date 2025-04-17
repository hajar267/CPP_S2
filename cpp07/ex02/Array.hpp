#ifndef ARRAY_HPP
#define ARRAY_HPP


template <typename T >
class Array{
    private:
        T *array;
        unsigned int _n;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](const size_t index);
        size_t size()const;

};

#include "Array.tpp"
#endif