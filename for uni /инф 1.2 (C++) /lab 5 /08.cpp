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
    int X;
    int S;
    std::cout << "Введите число X и количество бит S: ";
    std::cin >> X >> S;

    unsigned int X_unsigned = static_cast<unsigned int>(X);
    unsigned int Y = 0;

    if (S > 0) {
        // Логический сдвиг влево
        Y = X_unsigned << S;
    } else if (S < 0) {
        // Логический сдвиг вправо
        Y = X_unsigned >> (-S);
    } else {
        // S == 0, ничего не делаем
        Y = X_unsigned;
    }

    std::cout << "       |  дес  |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "X      | " << std::setw(5) << X_unsigned << " | " << std::setw(6) << std::oct << X_unsigned << " | " << std::setw(4) << std::hex << X_unsigned << " | " << toBinary(X_unsigned) << std::endl;
    std::cout << "Y      | " << std::setw(5) << Y << " | " << std::setw(6) << std::oct << Y << " | " << std::setw(4) << std::hex << Y << " | " << toBinary(Y) << std::endl;

    return 0;
}
