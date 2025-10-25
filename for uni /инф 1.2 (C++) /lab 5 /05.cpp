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

unsigned int getDirectCode(int x) {
    return static_cast<unsigned int>(x < 0 ? -x : x);
}

unsigned int getComplementCode(int x) {
    if (x >= 0) {
        return static_cast<unsigned int>(x);
    } else {
        return static_cast<unsigned int>(-x);
    }
}

unsigned int getInverseCode(int x) {
    if (x >= 0) {
        return static_cast<unsigned int>(x);
    } else {
        unsigned int abs_x = static_cast<unsigned int>(-x);
        return ~abs_x + 1;
    }
}

int main() {
    int X, Y;
    std::cout << "Введите числа ";
    std::cin >> X >> Y;

    unsigned int direct_x = getDirectCode(X);
    unsigned int direct_y = getDirectCode(Y);
    unsigned int complement_x = getComplementCode(X);
    unsigned int complement_y = getComplementCode(Y);
    unsigned int inverse_x = getInverseCode(X);
    unsigned int inverse_y = getInverseCode(Y);

    // Сложение в прямом коде (простое сложение модулей, знак определяется отдельно)
    unsigned int direct_sum = direct_x + direct_y;

    // Сложение в дополнительном коде (простое сложение)
    unsigned int complement_sum = complement_x + complement_y;

    // Сложение в обратном коде (простое сложение, возможен перенос)
    unsigned int inverse_sum = inverse_x + inverse_y;

    std::cout << "       |  дес  |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "доп код x = | " << std::setw(5) << complement_x << " | " << std::setw(6) << std::oct << complement_x << " | " << std::setw(4) << std::hex << complement_x << " | " << toBinary(complement_x) << std::endl;
    std::cout << "доп код y = | " << std::setw(5) << complement_y << " | " << std::setw(6) << std::oct << complement_y << " | " << std::setw(4) << std::hex << complement_y << " | " << toBinary(complement_y) << std::endl;
    std::cout << "доп код x+y=| " << std::setw(5) << complement_sum << " | " << std::setw(6) << std::oct << complement_sum << " | " << std::setw(4) << std::hex << complement_sum << " | " << toBinary(complement_sum) << std::endl;

    return 0;
}
