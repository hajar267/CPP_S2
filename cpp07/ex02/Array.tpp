template <typename T>
Array<T>::Array(): array(NULL),_n(0){

    std::cout<<"constractor "<<std::endl;
}


template <typename T>
Array<T>::Array(unsigned int n): array(new T[n]), _n(n){
    std::cout<<"param constractor "<<std::endl;
}

template <typename T>
Array<T>::Array(const Array& other): _n(other._n){
    array = new T[other._n];
    for(size_t i=0; i < other._n ; i++){
        array[i] = other.array[i];
    }
    std::cout<<"HERE  2"<<std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
    if (this != other)
    {
        delete[] array;
        array = new T[other._n];
        for(size_t i=0; i < other._n ; i++){
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](const size_t index){
    if (index >= _n)
    {
        throw std::out_of_range("Index is out of bounds!");
    }
    return this->array[index];
}

template <typename T>
size_t Array<T>::size()const {
    return _n;
}