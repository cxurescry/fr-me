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
    unsigned int X, Y;
    std::cout << "Введите числа ";
    std::cin >> X >> Y;

    unsigned int res = X + Y;

    std::cout << "       |  дес  |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "x =    | " << std::setw(5) << std::dec << X << " | " << std::setw(6) << std::oct << X << " | " << std::setw(4) << std::hex << X << " | " << toBinary(X) << std::endl;
    std::cout << "y =    | " << std::setw(5) << std::dec << Y << " | " << std::setw(6) << std::oct << Y << " | " << std::setw(4) << std::hex << Y << " | " << toBinary(Y) << std::endl;
    std::cout << "x + y =| " << std::setw(5) << std::dec << res << " | " << std::setw(6) << std::oct << res << " | " << std::setw(4) << std::hex << res << " | " << toBinary(res) << std::endl;

    return 0;
}
