#include <iostream>
#include <iomanip> 
#include <format>
#include <bitset>
using namespace std;

int main() {
    int choice = 0;
    while (1)
    {
        cout << "Номер задания: ";
        cin >> choice;
        switch(choice)
        {
        /* задание 1 */
        case 1: {
            unsigned int n;
            cout << "Введите n (0 <= n <= 31): ";
            cin >> n;
            if (n > 31) cout << "Предупреждение: 2^n может переполниться для unsigned int при n > 31\n";
            unsigned int result = 1U << n;
            cout << "2^"
                << n   << " = " 
                << dec << result << " (dec), " 
                << oct << result << " (oct), " 
                << hex << result << " (hex)  " 
                << dec << endl;
        } break;

        /* задание 2 */
     case 2: {
            unsigned int X, n;
            cout << "Введите число X: ";              cin >> X;
            cout << "Введите номер бита n (0..31): "; cin >> n;
            if (n > 31) { cout << "Номер бита вне диапазона!\n"; } 
            else {
                unsigned int bit = (X >> n) & 1U;
                cout << "Бит " << n << " числа " << X << " = " << bit << endl;
            }
        } break;

        /* задание 3 */
        case 3: {
            unsigned int X, n;
            cout << "Введите число X: ";              cin >> X;
            cout << "Введите номер бита n (0..31): "; cin >> n;
            if (n <= 31) {
                unsigned int newX = X | (1U << n);
                cout << "Число после установки бита " << n << " в 1:\n";
                cout << dec << newX << " (dec), " << oct << newX << " (oct), " << hex << newX << " (hex)" << dec << endl;
                cout << bitset<32>(newX) << endl;
            }
        } break;

        /* задание 4 */
        case 4: {
            unsigned int X, n;
            cout << "Введите число X: ";              cin >> X;
            cout << "Введите номер бита n (0..31): "; cin >> n;
            if (n <= 31) {
                unsigned int newX = X & ~(1U << n);
                cout << "Число после установки бита " << n << " в 0:\n";
                cout << dec << newX << " (dec), " << oct << newX << " (oct), " << hex << newX << " (hex)" << dec << endl;
                cout << bitset<32>(newX) << endl;
            }
        } break;

        /* задание 5 */
        case 5: {
            unsigned int X, n;
            cout << "Введите число X: ";              cin >> X;
            cout << "Введите номер бита n (0..31): "; cin >> n;
            if (n <= 31) {
                unsigned int newX = X ^ (1U << n);
                cout << "Число после инверсии бита " << n << ":\n";
                cout << dec << newX << " (dec), " << oct << newX << " (oct), " << hex << newX << " (hex)" << dec << endl;
                cout << bitset<32>(newX) << endl;
            }
        } break;

        /* задание 6 */
        case 6: {
            unsigned int X, Y, M;

            // Вывод X в двоичном виде (32 бита)
            auto printBin = [](unsigned int val) {
                for (int i = 31; i >= 0; i--) { cout << ((val >> i) & 1); }
                cout << endl;
            };

            cout << "Введите X: ";                     cin >> X;
            cout << "X до замены: ";
            printBin(X);
            cout << endl;
            cout << "Введите Y: ";                     cin >> Y;
            cout << "Введите длину маски M (0..32): "; cin >> M;

            if (M == 0) {} // ничего не меняем
            else if (M >= 32) { X = Y; } // заменяем все биты
            else {
                unsigned int mask = (1U << M) - 1; // маска из M единиц: 000...0111...1
                X = (X & ~mask) | (Y & mask);     // очищаем младшие M бит X, вставляем младшие M бит Y
            }
            
            cout << "Y (младшие " << M << " бит): "; printBin(Y);
            cout << "X после замены: ";              printBin(X);
        } break;

        /* задание 7 */
        case 7: {
            int N, M;
            cout << "Введите два целых числа N и M (могут быть отрицательными): ";
            cin >> N >> M;

            cout << "N = " << N << ", M = " << M << endl;

            cout << "\nСравнение && и &:\n";
            if (N && M) cout << "N && M -> true\n";
            else cout << "N && M -> false\n";

            if (N & M) cout << "N & M -> true (ненулевой результат)\n";
            else cout << "N & M -> false (результат 0)\n";

            cout << "\nСравнение || и |:\n";
            if (N || M) cout << "N || M -> true\n";
            else cout << "N || M -> false\n";

            if (N | M) cout << "N | M -> true (ненулевой результат)\n";
            else cout << "N | M -> false (результат 0)\n";

            cout << "\nВывод: логические операторы (&&, ||) работают с истинностью (0/не 0),\n";
        } break;

        /* задание 8 */
        case 8: {
            unsigned int x;
            cout << "Введите неотрицательное целое число: ";
            cin >> x;

            unsigned int max_len = 0;
            unsigned int current_len = 0;
            unsigned int in_sequence = 0; 

            for (int i = 0; i < 32; ++i) {
                unsigned int bit = (x >> i) & 1U;

                if (bit) {
                    if (in_sequence) current_len++;
                    else {
                        if (i > 0 && !((x >> (i - 1)) & 1U)) in_sequence = current_len = 1;
                    }
                }
                else {
                    if (in_sequence) {
                        if (current_len > max_len) max_len = current_len;
                        in_sequence = current_len = 0;
                    }
                }
            }
//cout << bitset<32>(x);
            cout << "Наибольшее количество еденичных бит, идущих подряд в числе: " << max_len << endl;
        } break;

        /* задание 9*/
        case 9: {
            unsigned long int x;
            cout << "Введите неотрицательное целое число X ";
            cin >> x;
            cout << bitset<32>(x) << '\n';
            x |= ( (x << 1) & (x >> 1) ) ;
            cout << bitset<32>(x) << '\n';
        } break;

        /* задание 10 */
        case 10: {
            cout << bitset<8>(((3U << 6) | 3U))        << '\n';
            cout << bitset<8>(((3U << 5) | (3U << 1))) << '\n';
            cout << bitset<8>(((3U << 4) | (3U << 2))) << '\n'; 
            cout << bitset<8>(3U << 3)                 << '\n';
            cout << bitset<8>(((3U << 4) | (3U << 2))) << '\n'; 
            cout << bitset<8>(((3U << 5) | (3U << 1))) << '\n';
            cout << bitset<8>(((3U << 6) | 3U))        << '\n';
        } break;
        
        /* неправильный ввод */
        default : break;

        } /* конец switch */
    } /* конец while */

    return 0;
}
