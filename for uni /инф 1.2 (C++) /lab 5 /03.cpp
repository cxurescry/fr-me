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

// Функция для получения прямого кода (просто модуль)
unsigned int getDirectCode(int x) {
    return static_cast<unsigned int>(x < 0 ? -x : x);
}

// Функция для получения дополнительного кода
unsigned int getComplementCode(int x) {
    if (x >= 0) {
        return static_cast<unsigned int>(x);
    } else {
        return static_cast<unsigned int>(-x);
    }
}

// Функция для получения обратного кода
unsigned int getInverseCode(int x) {
    if (x >= 0) {
        return static_cast<unsigned int>(x);
    } else {
        unsigned int abs_x = static_cast<unsigned int>(-x);
        return ~abs_x + 1; // Обратный код = инверсия модуля + 1
    }
}

int main() {
    int X;
    std::cout << "Введите число ";
    std::cin >> X;

    bool isNegative = (X < 0);
    unsigned int abs_X = static_cast<unsigned int>(isNegative ? -X : X);

    unsigned int direct_code = getDirectCode(X);
    unsigned int complement_code = getComplementCode(X);
    unsigned int inverse_code = getInverseCode(X);

    std::cout << "Исходное число: " << X << " (знак: " << (isNegative ? "отрицательное" : "положительное") << ")" << std::endl;
    std::cout << "       |  дес  |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "Прямой | " << std::setw(5) << direct_code << " | " << std::setw(6) << std::oct << direct_code << " | " << std::setw(4) << std::hex << direct_code << " | " << toBinary(direct_code) << std::endl;
    std::cout << "Дополн.| " << std::setw(5) << complement_code << " | " << std::setw(6) << std::oct << complement_code << " | " << std::setw(4) << std::hex << complement_code << " | " << toBinary(complement_code) << std::endl;
    std::cout << "Обратный| " << std::setw(5) << inverse_code << " | " << std::setw(6) << std::oct << inverse_code << " | " << std::setw(4) << std::hex << inverse_code << " | " << toBinary(inverse_code) << std::endl;

    return 0;
}
