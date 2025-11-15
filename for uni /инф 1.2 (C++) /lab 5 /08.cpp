#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// Функция для вывода числа в двоичном виде (32 бита)
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

// Логический сдвиг (для unsigned)
unsigned int logicalShift(unsigned int x, int s) {
    if (s > 0) {
        // Сдвиг влево
        return x << s;
    } else {
        // Сдвиг вправо (заполнение нулями)
        return x >> (-s);
    }
}

// Арифметический сдвиг (для signed)
int arithmeticShift(int x, int s) {
    if (s > 0) {
        // Сдвиг влево
        return x << s;
    } else {
        // Сдвиг вправо (с сохранением знака)
        return x >> (-s);
    }
}

// Циклический сдвиг (rotate) для unsigned
unsigned int cyclicShift(unsigned int x, int s) {
    if (s > 0) {
        // Циклический сдвиг влево
        unsigned int mask = (1U << 32) - 1; // Маска для 32 бит
        unsigned int shift = s % 32;
        return ((x << shift) | (x >> (32 - shift))) & mask;
    } else {
        // Циклический сдвиг вправо
        unsigned int mask = (1U << 32) - 1; // Маска для 32 бит
        unsigned int shift = (-s) % 32;
        return ((x >> shift) | (x << (32 - shift))) & mask;
    }
}

// Реверс младших |S| бит числа X
unsigned int reverseBits(unsigned int x, int numBits) {
    unsigned int result = 0;
    unsigned int mask = (1U << numBits) - 1; // Маска для numBits бит
    unsigned int bits = x & mask; // Извлекаем младшие numBits бит

    // Реверсируем биты
    for (int i = 0; i < numBits; ++i) {
        result |= ((bits >> i) & 1) << (numBits - 1 - i);
    }

    // Сохраняем остальные биты без изменений
    result |= (x & ~mask);

    return result;
}

int main() {
    int X;
    int S;

    std::cout << "Введите целое десятичное число X (может быть отрицательным): ";
    std::cin >> X;
    std::cout << "Введите количество бит для сдвига S: ";
    std::cin >> S;

    // Определяем направление сдвига
    int shiftAmount = (S > 0) ? S : -S;
    bool shiftLeft = (S > 0);

    // Преобразуем X в unsigned для логического и циклического сдвига
    unsigned int X_unsigned = static_cast<unsigned int>(X);

    // Выполняем сдвиги
    unsigned int logicalResult = logicalShift(X_unsigned, S);
    int arithmeticResult = arithmeticShift(X, S);
    unsigned int cyclicResult = cyclicShift(X_unsigned, S);

    // Реверс младших |S| бит
    unsigned int Y = reverseBits(X_unsigned, shiftAmount);

    // Выводим исходное число X
    std::cout << "\nИсходное число X:" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "X =    | " << std::setw(14) << std::dec << X << " | "
              << std::setw(16) << toOctalString(X_unsigned) << " | "
              << std::setw(21) << toHexString(X_unsigned) << " | "
              << toBinary(X_unsigned) << std::endl;

    // Выводим логический сдвиг
    std::cout << "\nЛогический сдвиг (unsigned):" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "лог.   | " << std::setw(14) << std::dec << logicalResult << " | "
              << std::setw(16) << toOctalString(logicalResult) << " | "
              << std::setw(21) << toHexString(logicalResult) << " | "
              << toBinary(logicalResult) << std::endl;

    // Выводим арифметический сдвиг
    std::cout << "\nАрифметический сдвиг (signed):" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    unsigned int arithmeticResult_unsigned = static_cast<unsigned int>(arithmeticResult);
    std::cout << "арифм. | " << std::setw(14) << std::dec << arithmeticResult << " | "
              << std::setw(16) << toOctalString(arithmeticResult_unsigned) << " | "
              << std::setw(21) << toHexString(arithmeticResult_unsigned) << " | "
              << toBinary(arithmeticResult_unsigned) << std::endl;

    // Выводим циклический сдвиг
    std::cout << "\nЦиклический сдвиг (rotate, unsigned):" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "цикл.  | " << std::setw(14) << std::dec << cyclicResult << " | "
              << std::setw(16) << toOctalString(cyclicResult) << " | "
              << std::setw(21) << toHexString(cyclicResult) << " | "
              << toBinary(cyclicResult) << std::endl;

    // Выводим результат реверса бит
    std::cout << "\nРеверс младших " << shiftAmount << " бит (Y):" << std::endl;
    std::cout << "       |   десятичная   |   восьмеричная   |   шестнадцатеричная   |   двоичная" << std::endl;
    std::cout << "Y =    | " << std::setw(14) << std::dec << Y << " | "
              << std::setw(16) << toOctalString(Y) << " | "
              << std::setw(21) << toHexString(Y) << " | "
              << toBinary(Y) << std::endl;

    return 0;
}

