#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// Функция для вывода числа в двоичном виде (16 бит)
std::string toBinary(unsigned short num) {
    std::string bin = "";
    for (int i = 15; i >= 0; --i) {
        bin += ((num >> i) & 1) ? '1' : '0';
        if (i % 4 == 0 && i != 0) bin += ' ';
    }
    return bin;
}

// Функция для форматирования числа с ведущими нулями в восьмеричной системе
std::string toOctalString(unsigned short num) {
    std::ostringstream oss;
    oss << std::oct << num;
    std::string result = oss.str();
    // Дополняем до 6 цифр ведущими нулями
    while (result.length() < 6) {
        result = "0" + result;
    }
    return result;
}

// Функция для форматирования числа с ведущими нулями в шестнадцатеричной системе
std::string toHexString(unsigned short num) {
    std::ostringstream oss;
    oss << std::hex << num;
    std::string result = oss.str();
    // Дополняем до 4 цифр ведущими нулями
    while (result.length() < 4) {
        result = "0" + result;
    }
    return result;
}

// Прямой код (sign-magnitude)
unsigned short toDirectCode(int num) {
    if (num >= 0) {
        return static_cast<unsigned short>(num);
    } else {
        // Знаковый бит + модуль
        return 0x8000 | static_cast<unsigned short>(abs(num));
    }
}

// Обратный код (one's complement)
unsigned short toOnesComplement(int num) {
    if (num >= 0) {
        return static_cast<unsigned short>(num);
    } else {
        // Для отрицательного числа инвертируем все биты
        return static_cast<unsigned short>(~abs(num));
    }
}

// Дополнительный код (two's complement)
unsigned short toTwosComplement(int num) {
    return static_cast<unsigned short>(num);
}

// Извлечение значения из прямого кода
int fromDirectCode(unsigned short code) {
    if (code & 0x8000) {
        return -(code & 0x7FFF);
    } else {
        return code & 0x7FFF;
    }
}

// Извлечение значения из обратного кода
int fromOnesComplement(unsigned short code) {
    if (code & 0x8000) {
        // Инвертируем все биты кроме знакового и делаем отрицательным
        unsigned short absVal = (~code) & 0x7FFF;
        return -static_cast<int>(absVal);
    } else {
        return code & 0x7FFF;
    }
}

// Извлечение значения из дополнительного кода
int fromTwosComplement(unsigned short code) {
    return static_cast<short>(code);
}

// Сложение в прямом коде
unsigned short addDirectCode(unsigned short x, unsigned short y) {
    int signX = (x & 0x8000) ? -1 : 1;
    int signY = (y & 0x8000) ? -1 : 1;
    int valX = (x & 0x7FFF) * signX;
    int valY = (y & 0x7FFF) * signY;
    int result = valX + valY;
    return toDirectCode(result);
}

// Сложение в обратном коде
unsigned short addOnesComplement(unsigned short x, unsigned short y) {
    unsigned int sum = static_cast<unsigned int>(x) + static_cast<unsigned int>(y);
    // End-around carry: если есть перенос из 16-го бита, добавляем его к младшему разряду
    if (sum > 0xFFFF) {
        sum = (sum & 0xFFFF) + 1;
    }
    // Если есть перенос в знаковый разряд при сложении положительных чисел
    if (!(x & 0x8000) && !(y & 0x8000) && (sum & 0x8000)) {
        sum = (sum & 0x7FFF) + 1;
    }
    return static_cast<unsigned short>(sum & 0xFFFF);
}

// Сложение в дополнительном коде
unsigned short addTwosComplement(unsigned short x, unsigned short y) {
    return x + y;
}

int main() {
    int X, Y;
    std::cout << "Введите числа ";
    std::cin >> X >> Y;

    // Получаем абсолютные значения и знаки
    int absX = abs(X);
    int absY = abs(Y);

    // Преобразуем в разные коды
    unsigned short X_direct = toDirectCode(X);
    unsigned short Y_direct = toDirectCode(Y);
    unsigned short X_ones = toOnesComplement(X);
    unsigned short Y_ones = toOnesComplement(Y);
    unsigned short X_twos = toTwosComplement(X);
    unsigned short Y_twos = toTwosComplement(Y);

    // Выводим исходные числа
    std::cout << "\nИсходные числа:" << std::endl;
    std::cout << "       |   дес   |  восм  |  hex  |  двоичный" << std::endl;
    
    std::cout << "x =    | " << std::setw(7) << std::dec << X << " | " 
              << std::setw(6) << toOctalString(absX) << " | " 
              << std::setw(4) << toHexString(absX) << " | " 
              << toBinary(X_direct) << std::endl;
    
    std::cout << "y =    | " << std::setw(7) << std::dec << Y << " | " 
              << std::setw(6) << toOctalString(absY) << " | " 
              << std::setw(4) << toHexString(absY) << " | " 
              << toBinary(Y_direct) << std::endl;

    std::cout << std::endl;

    // Стандартное сложение
    int standardSum = X + Y;
    int absStandardSum = abs(standardSum);
    unsigned short standardSum_code = toDirectCode(standardSum);
    
    std::cout << "Стандартное сложение:" << std::endl;
    std::cout << "       |   дес   |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "x + y =| " << std::setw(7) << std::dec << standardSum << " | " 
              << std::setw(6) << toOctalString(absStandardSum) << " | " 
              << std::setw(4) << toHexString(absStandardSum) << " | " 
              << toBinary(standardSum_code) << std::endl;

    std::cout << std::endl;

    // Сложение в прямом коде
    unsigned short directSum = addDirectCode(X_direct, Y_direct);
    int directSumValue = fromDirectCode(directSum);
    int absDirectSum = abs(directSumValue);
    
    std::cout << "Сложение в прямом коде:" << std::endl;
    std::cout << "       |   дес   |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "пр код x =    | " << std::setw(7) << std::dec << fromDirectCode(X_direct) << " | " 
              << std::setw(6) << toOctalString(X_direct) << " | " 
              << std::setw(4) << toHexString(X_direct) << " | " 
              << toBinary(X_direct) << std::endl;
    std::cout << "пр код y =    | " << std::setw(7) << std::dec << fromDirectCode(Y_direct) << " | " 
              << std::setw(6) << toOctalString(Y_direct) << " | " 
              << std::setw(4) << toHexString(Y_direct) << " | " 
              << toBinary(Y_direct) << std::endl;
    std::cout << "пр код x + y =| " << std::setw(7) << std::dec << directSumValue << " | " 
              << std::setw(6) << toOctalString(directSum) << " | " 
              << std::setw(4) << toHexString(directSum) << " | " 
              << toBinary(directSum) << std::endl;

    std::cout << std::endl;

    // Сложение в дополнительном коде
    unsigned short twosSum = addTwosComplement(X_twos, Y_twos);
    int twosSumValue = fromTwosComplement(twosSum);
    
    std::cout << "Сложение в дополнительном коде:" << std::endl;
    std::cout << "       |   дес   |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "доп код x =    | " << std::setw(7) << std::dec << X_twos << " | " 
              << std::setw(6) << toOctalString(X_twos) << " | " 
              << std::setw(4) << toHexString(X_twos) << " | " 
              << toBinary(X_twos) << std::endl;
    std::cout << "доп код y =    | " << std::setw(7) << std::dec << Y_twos << " | " 
              << std::setw(6) << toOctalString(Y_twos) << " | " 
              << std::setw(4) << toHexString(Y_twos) << " | " 
              << toBinary(Y_twos) << std::endl;
    std::cout << "доп код x + y =| " << std::setw(7) << std::dec << twosSum << " | " 
              << std::setw(6) << toOctalString(twosSum) << " | " 
              << std::setw(4) << toHexString(twosSum) << " | " 
              << toBinary(twosSum) << std::endl;

    std::cout << std::endl;

    // Сложение в обратном коде
    unsigned short onesSum = addOnesComplement(X_ones, Y_ones);
    int onesSumValue = fromOnesComplement(onesSum);
    
    std::cout << "Сложение в обратном коде:" << std::endl;
    std::cout << "       |   дес   |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "обр код x =    | " << std::setw(7) << std::dec << fromOnesComplement(X_ones) << " | " 
              << std::setw(6) << toOctalString(X_ones) << " | " 
              << std::setw(4) << toHexString(X_ones) << " | " 
              << toBinary(X_ones) << std::endl;
    std::cout << "обр код y =    | " << std::setw(7) << std::dec << fromOnesComplement(Y_ones) << " | " 
              << std::setw(6) << toOctalString(Y_ones) << " | " 
              << std::setw(4) << toHexString(Y_ones) << " | " 
              << toBinary(Y_ones) << std::endl;
    std::cout << "обр код x + y =| " << std::setw(7) << std::dec << onesSumValue << " | " 
              << std::setw(6) << toOctalString(onesSum) << " | " 
              << std::setw(4) << toHexString(onesSum) << " | " 
              << toBinary(onesSum) << std::endl;

    return 0;
}

