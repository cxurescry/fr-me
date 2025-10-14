// task2.cpp
#include <bits/stdc++.h>
using namespace std;

// Пример: ввод: 54 (hex) -> 01010100 (8 бит) -> результат 01111100

int main() {
    string hexs;
    if (!(cin >> hexs)) return 0;
    if (hexs.size() >= 2 && hexs[0]=='0' && (hexs[1]=='x' || hexs[1]=='X')) hexs = hexs.substr(2);
    int nbits = 4 * (int)hexs.size();

    unsigned long long value = 0;
    for (char c : hexs) {
        value <<= 4;
        if ('0' <= c && c <= '9') value |= (c - '0');
        else if ('a' <= c && c <= 'f') value |= (10 + c - 'a');
        else if ('A' <= c && c <= 'F') value |= (10 + c - 'A');
    }

    vector<int> bits(nbits);
    for (int i = 0; i < nbits; ++i) {
        int pos_from_lsb = nbits - 1 - i;
        bits[i] = ((value >> pos_from_lsb) & 1ULL) ? 1 : 0;
    }

    // создаём копию и устанавливаем нули, которые находятся между двумя единицами
    vector<int> res = bits;
    for (int i = 1; i + 1 < nbits; ++i) {
        if (bits[i] == 0 && bits[i-1] == 1 && bits[i+1] == 1) res[i] = 1;
    }

    // выводим результат в двоичном виде (MSB слева), а также в hex
    for (int b : res) cout << b;
    cout << "\n";

    // собрать обратно в число и вывести hex (с ведущими нулями, при необходимости)
    unsigned long long outv = 0;
    for (int i = 0; i < nbits; ++i) {
        outv = (outv << 1) | (res[i] & 1ULL);
    }
    // выведем в hex с ведущими нулями до ceil(nbits/4)
    int hex_digits = (nbits + 3) / 4;
    std::ostringstream oss;
    oss << std::uppercase << std::hex << outv;
    string hexout = oss.str();
    if ((int)hexout.size() < hex_digits) hexout = string(hex_digits - hexout.size(), '0') + hexout;
    cout << hexout << "\n";
    return 0;
}
