#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

// Функция для вывода числа в двоичном виде (16 бит)
std::string toBinary(unsigned int num) {
    std::string bin = "";
    for (int i = 15; i >= 0; --i) {
        bin += ((num >> i) & 1) ? '1' : '0';
        if (i % 4 == 0 && i != 0) bin += ' '; // Разделение по 4 бита для удобства
    }
    return bin;
}

// Функция для форматирования числа в восьмеричной системе
std::string toOctalString(unsigned int num) {
    std::ostringstream oss;
    oss << std::oct << num;
    return oss.str();
}

// Функция для форматирования числа в шестнадцатеричной системе
std::string toHexString(unsigned int num) {
    std::ostringstream oss;
    oss << std::hex << std::uppercase << num;
    return oss.str();
}

// Преобразование в прямой код (sign-magnitude)
// sign: true если отрицательное, false если положительное
// absValue: абсолютное значение числа
unsigned int toDirectCode(bool sign, unsigned int absValue) {
    if (!sign) {
        // Положительное число: просто возвращаем модуль
        return absValue;
    } else {
        // Отрицательное число: устанавливаем знаковый бит (15-й бит для 16-битного числа)
        return (1 << 15) | absValue;
    }
}

// Преобразование в обратный код (one's complement)
unsigned int toOnesComplement(bool sign, unsigned int absValue) {
    if (!sign) {
        // Положительное число: просто возвращаем модуль
        return absValue;
    } else {
        // Отрицательное число: инвертируем все биты модуля
        // Для 16-битного числа инвертируем младшие 15 бит
        return (~absValue) & 0xFFFF;
    }
}

// Преобразование в дополнительный код (two's complement)
unsigned int toTwosComplement(bool sign, unsigned int absValue) {
    if (!sign) {
        // Положительное число: просто возвращаем модуль
        return absValue;
    } else {
        // Отрицательное число: инвертируем все биты модуля и добавляем 1
        return ((~absValue) & 0xFFFF) + 1;
    }
}

int main() {
    int X;
    std::cout << "Введите целое десятичное число X (может быть отрицательным): ";
    std::cin >> X;

    // Сохраняем знак числа и его абсолютное значение
    bool isNegative = (X < 0);
    unsigned int absValue = static_cast<unsigned int>(std::abs(X));

    // Преобразуем в разные коды, используя только сохраненный знак и модуль
    unsigned int directCode = toDirectCode(isNegative, absValue);
    unsigned int onesComplement = toOnesComplement(isNegative, absValue);
    unsigned int twosComplement = toTwosComplement(isNegative, absValue);

    // Выводим исходное число
    std::cout << "\nИсходное число X:" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "X =    | " << std::setw(14) << std::dec << X << " | "
              << std::setw(16) << toOctalString(static_cast<unsigned int>(X < 0 ? -X : X)) << " | "
              << std::setw(21) << toHexString(static_cast<unsigned int>(X < 0 ? -X : X)) << " | "
              << toBinary(static_cast<unsigned int>(X)) << std::endl;

    // Выводим прямой код
    std::cout << "\nПрямой код (sign-magnitude):" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "пр.код | " << std::setw(14) << std::dec << directCode << " | "
              << std::setw(16) << toOctalString(directCode) << " | "
              << std::setw(21) << toHexString(directCode) << " | "
              << toBinary(directCode) << std::endl;

    // Выводим обратный код
    std::cout << "\nОбратный код (one's complement):" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "обр.код| " << std::setw(14) << std::dec << onesComplement << " | "
              << std::setw(16) << toOctalString(onesComplement) << " | "
              << std::setw(21) << toHexString(onesComplement) << " | "
              << toBinary(onesComplement) << std::endl;

    // Выводим дополнительный код
    std::cout << "\nДополнительный код (two's complement):" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "доп.код| " << std::setw(14) << std::dec << twosComplement << " | "
              << std::setw(16) << toOctalString(twosComplement) << " | "
              << std::setw(21) << toHexString(twosComplement) << " | "
              << toBinary(twosComplement) << std::endl;

    return 0;
}

