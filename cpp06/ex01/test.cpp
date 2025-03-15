#include <iostream>
#include <stdint.h>  // uintptr_t

struct Data {
    int value;
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data d = {42};

    uintptr_t raw = serialize(&d);
    std::cout << "Serialized pointer (as int): " << raw << std::endl;

    Data* restored = deserialize(raw);
    std::cout << "Restored value: " << restored->value << std::endl;

    return 0;
}
