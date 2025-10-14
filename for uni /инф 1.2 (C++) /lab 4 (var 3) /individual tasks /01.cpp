// task1.cpp
#include <bits/stdc++.h>
using namespace std;

// Пример: ввод: 37  (hex) -> рассматриваем 2*4 = 8 бит: 00110111 -> ответ 2

int main() {
    string hexs;
    if (!(cin >> hexs)) return 0;

    // убрать возможный "0x" или "0X"
    if (hexs.size() >= 2 && hexs[0]=='0' && (hexs[1]=='x' || hexs[1]=='X')) hexs = hexs.substr(2);

    // длина в битах = 4 * число hex-символов
    int nbits = 4 * (int)hexs.size();

    // преобразуем hex-строку в число (unsigned long long достаточно для до 16 hex-символов)
    unsigned long long value = 0;
    for (char c : hexs) {
        value <<= 4;
        if ('0' <= c && c <= '9') value |= (c - '0');
        else if ('a' <= c && c <= 'f') value |= (10 + c - 'a');
        else if ('A' <= c && c <= 'F') value |= (10 + c - 'A');
    }

    // представление битов как в строке длины nbits (MSB слева)
    vector<int> bits(nbits);
    for (int i = 0; i < nbits; ++i) {
        // MSB на позиции 0
        int pos_from_lsb = nbits - 1 - i;
        bits[i] = ( (value >> pos_from_lsb) & 1ULL ) ? 1 : 0;
    }

    int best = 0;
    int i = 0;
    while (i < nbits) {
        if (bits[i] == 1) {
            int j = i;
            while (j+1 < nbits && bits[j+1] == 1) ++j;
            // run [i..j] состоит из единиц; проверим, что слева и справа есть нули
            bool left_zero  = (i-1 >= 0) && (bits[i-1] == 0);
            bool right_zero = (j+1 < nbits) && (bits[j+1] == 0);
            if (left_zero && right_zero) {
                best = max(best, j - i + 1);
            }
            i = j + 1;
        } else ++i;
    }

    cout << best << "\n";
    return 0;
}
