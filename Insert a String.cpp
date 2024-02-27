#include <iostream>
#include <string>

int main() {
    std::string inputString;

    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    std::cout << "You entered: " << inputString << std::endl;

    return 0;
}