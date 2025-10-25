#include <iostream>
#include <iomanip>
#include <string>

// Функция для вывода числа в двоичном виде (16 бит)
std::string toBinary(unsigned int num) {
    std::string bin = "";
    for (int i = 15; i >= 0; --i) {
        bin += ((num >> i) & 1) ? '1' : '0';
        if (i % 4 == 0 && i != 0) bin += ' '; // Разделение по 4 бита для удобства
    }
    return bin;
}

int main() {
    unsigned int X;
    std::cout << "введите число ";
    std::cin >> X;

    unsigned int X_plus_1 = X + 1;

    std::cout << "       |  дес  |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "x =    | " << std::setw(5) << X << " | " << std::setw(6) << std::oct << X << " | " << std::setw(4) << std::hex << X << " | " << toBinary(X) << std::endl;
    std::cout << "x+1=   | " << std::setw(5) << X_plus_1 << " | " << std::setw(6) << std::oct << X_plus_1 << " | " << std::setw(4) << std::hex << X_plus_1 << " | " << toBinary(X_plus_1) << std::endl;

    return 0;
}
