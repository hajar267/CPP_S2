#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include <unistd.h>

int main() {
    Base a;
    
    Base *b = a.generate();

    a.identify(b);
    a.identify(*b);


    delete b;
//     for (int i = 0; i < 3; i++) {
//         srand(time(0));
//         sleep(1);
//     std::cout << rand() % 10 << " ";
// }
    return 0;

}