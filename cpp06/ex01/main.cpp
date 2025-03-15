#include"Serializer.hpp"


int main() {
    Data ptr(15);

    uintptr_t raw = Serializer::serialize(&ptr);

    Data* ptr2 = Serializer::deserialize(raw);

    std::cout << "value: " << ptr.value << std::endl;
    std::cout << "value2: " << ptr2->value << std::endl;

    return 0;
}