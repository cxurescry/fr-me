#include <iostream>
#include <bitset>
using namespace std;

int main() {
    cout << "Числа с шестью двоичными цифрами, где 1 > 0:\n\n";
    cout << "Двоичное\tДесятичное\n";
    cout << "--------------------------\n";

    // Диапазон 6-значных двоичных чисел: от 32 (100000₂) до 63 (111111₂)
    for (int n = 32; n <= 63; n++) {
        bitset<6> bin(n); // Представление в двоичном виде (6 бит)
        string s = bin.to_string();

        int ones = 0, zeros = 0;
        for (char c : s) {
            if (c == '1') ones++;
            else zeros++;
        }

        if (ones > zeros) {
            cout << s << "\t" << n << endl;
        }
    }

    return 0;
}
