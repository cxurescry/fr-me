#include <iostream>
#include <iomanip>
#include <string>

// Функция для вывода числа в двоичном виде (32 бита для int)
std::string toBinary(unsigned int num) {
    std::string bin = "";
    for (int i = 15; i >= 0; --i) {
        bin += ((num >> i) & 1) ? '1' : '0';
        if (i % 4 == 0 && i != 0) bin += ' '; // Разделение по 4 бита для удобства
    }
    return bin;
}

int main() {
    signed int X;
    std::cout << "Введите целое десятичное число X (может быть отрицательным): ";
    std::cin >> X;

    // Используем переменную с модификатором unsigned для форматирования вывода
    unsigned int X_unsigned = static_cast<unsigned int>(X);

    std::cout << "\nЧисло X в различных системах счисления (беззнаковое представление):" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "X =    | " << std::setw(14) << std::dec << X_unsigned << " | "
              << std::setw(16) << std::oct << X_unsigned << " | "
              << std::setw(21) << std::hex << std::uppercase << X_unsigned << " | "
              << toBinary(X_unsigned) << std::endl;
    return 0;
}
