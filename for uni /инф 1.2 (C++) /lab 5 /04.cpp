#include <iostream>
#include <iomanip>
#include <string>

std::string toBinary(unsigned short num) {
    std::string bin = "";
    for (int i = 15; i >= 0; --i) {
        bin += ((num >> i) & 1) ? '1' : '0';
        if (i % 4 == 0 && i != 0) bin += ' ';
    }
    return bin;
}

int main() {
    int X;
    std::cout << "Введите число ";
    std::cin >> X;

    unsigned short X_unsigned = static_cast<unsigned short>(X);
    unsigned short X_plus_1_unsigned = X_unsigned + 1;

    std::cout << "       |  дес  |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "x =    | " << std::setw(5) << std::dec << X_unsigned << " | " << std::setw(6) << std::oct << X_unsigned << " | " << std::setw(4) << std::hex << X_unsigned << " | " << toBinary(X_unsigned) << std::endl;
    std::cout << "x + 1 =| " << std::setw(5) << std::dec << X_plus_1_unsigned << " | " << std::setw(6) << std::oct << X_plus_1_unsigned << " | " << std::setw(4) << std::hex << X_plus_1_unsigned << " | " << toBinary(X_plus_1_unsigned) << std::endl;

    return 0;
}
