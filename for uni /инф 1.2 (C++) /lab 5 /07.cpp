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
    int A1, A2, A3, A4, B1, B2, B3, B4;
    std::cout << "Введите 8 чисел (A1, A2, A3, A4, B1, B2, B3, B4): ";
    std::cin >> A1 >> A2 >> A3 >> A4 >> B1 >> B2 >> B3 >> B4;

    // Упаковка в вектора
    uint16_t Aodd = 0, Aeven = 0, Bodd = 0, Beven = 0;

    // Вектор Aodd: A3 (биты 11-8), A1 (биты 3-0)
    Aodd |= (static_cast<uint16_t>(A3 & 0xF) << 8); // Младшие 4 бита A3 в биты 11-8
    Aodd |= (static_cast<uint16_t>(A1 & 0xF) << 0); // Младшие 4 бита A1 в биты 3-0

    // Вектор Aeven: A4 (биты 15-12), A2 (биты 7-4)
    Aeven |= (static_cast<uint16_t>(A4 & 0xF) << 12); // Младшие 4 бита A4 в биты 15-12
    Aeven |= (static_cast<uint16_t>(A2 & 0xF) << 4);  // Младшие 4 бита A2 в биты 7-4

    // Вектор Bodd: B3 (биты 11-8), B1 (биты 3-0)
    Bodd |= (static_cast<uint16_t>(B3 & 0xF) << 8);
    Bodd |= (static_cast<uint16_t>(B1 & 0xF) << 0);

    // Вектор Beven: B4 (биты 15-12), B2 (биты 7-4)
    Beven |= (static_cast<uint16_t>(B4 & 0xF) << 12);
    Beven |= (static_cast<uint16_t>(B2 & 0xF) << 4);

    // Сложение векторов
    uint16_t Codd = Aodd + Bodd;
    uint16_t Ceven = Aeven + Beven;

    // Соединение векторов в один результатирующий вектор C
    uint16_t C = Codd | Ceven;

    std::cout << "       |  дес  |  восм  |  hex  |  двоичный" << std::endl;
    std::cout << "Codd   | " << std::setw(5) << Codd << " | " << std::setw(6) << std::oct << Codd << " | " << std::setw(4) << std::hex << Codd << " | " << toBinary(Codd) << std::endl;
    std::cout << "Ceven  | " << std::setw(5) << Ceven << " | " << std::setw(6) << std::oct << Ceven << " | " << std::setw(4) << std::hex << Ceven << " | " << toBinary(Ceven) << std::endl;
    std::cout << "C      | " << std::setw(5) << C << " | " << std::setw(6) << std::oct << C << " | " << std::setw(4) << std::hex << C << " | " << toBinary(C) << std::endl;

    return 0;
}
