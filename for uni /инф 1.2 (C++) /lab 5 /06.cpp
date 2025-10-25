#include <iostream>
#include <iomanip>
#include <string>

std::string toBinary(unsigned int num) {
    std::string bin = "";
    for (int i = 15; i >= 0; --i) {
        bin += ((num >> i) & 1) ? '1' : '0';
        if (i % 4 == 0 && i != 0) bin += ' ';
    }
    return bin;
}

int main() {
    signed int X;
    std::cout << "Введите число ";
    std::cin >> X;

    unsigned int X_unsigned = static_cast<unsigned int>(X);

    std::cout << "Число хранится в компьютере в дополнительном коде (signed int)." << std::endl;
    std::cout << "       |  дес  |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "x =    | " << std::setw(5) << X_unsigned << " | " << std::setw(6) << std::oct << X_unsigned << " | " << std::setw(4) << std::hex << X_unsigned << " | " << toBinary(X_unsigned) << std::endl;

    return 0;
}
