#include <iostream>
#include <lib.h>

int main(int, char**) {
    std::string helloJim = generateHelloString("Jim");
    std::cout << helloJim << std::endl;

    return 0;
}
