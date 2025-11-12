// task7.cpp
#include <iostream>
#include <string>

using namespace std;

string boolStr(bool b) { return b ? "true" : "false"; }

string toBinarySigned(long long v) {
    unsigned long long u = static_cast<unsigned long long>(v);
    string s;
    for (int i = 63; i >= 0; --i)
        s.push_back(((u >> i) & 1ULL) ? '1' : '0');
    size_t pos = s.find('1');
    if (pos == string::npos)
        return "0";
    return s.substr(pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cout << "Введите целое N: ";
    if (!(cin >> N)) return 0;
    cout << "Введите целое M: ";
    if (!(cin >> M)) return 0;

    cout << "\nВведено N = " << N << ", M = " << M << "\n";
    cout << "Бинарное N = " << toBinarySigned(N) << "\n";
    cout << "Бинарное M = " << toBinarySigned(M) << "\n\n";

    bool log_and = (N && M);
    bool log_or  = (N || M);
    bool log_notN = (!N);
    bool log_notM = (!M);

    bool bit_and_as_bool = ((N & M) != 0);
    bool bit_or_as_bool  = ((N | M) != 0);
    bool bit_notN_nonzero = ((~N) != 0);
    bool bit_notM_nonzero = ((~M) != 0);

    cout << "Операция        | логический результат | битовый аналог | совпадает?\n";
    cout << "----------------|----------------------|----------------|------------\n";
    cout << "N && M          | " << boolStr(log_and)
         << "                 | " << boolStr(bit_and_as_bool)
         << "          | " << (log_and == bit_and_as_bool ? "Да" : "Нет") << "\n";

    cout << "N || M          | " << boolStr(log_or)
         << "                  | " << boolStr(bit_or_as_bool)
         << "          | " << (log_or == bit_or_as_bool ? "Да" : "Нет") << "\n";

    cout << "!N              | " << boolStr(log_notN)
         << "                 | ~N != 0 → " << boolStr(bit_notN_nonzero)
         << "     | " << (log_notN == bit_notN_nonzero ? "Да" : "Нет") << "\n";

    cout << "!M              | " << boolStr(log_notM)
         << "                 | ~M != 0 → " << boolStr(bit_notM_nonzero)
         << "     | " << (log_notM == bit_notM_nonzero ? "Да" : "Нет") << "\n\n";

    cout << "Пояснения:\n";
    cout << " - (N && M) истинно, если оба числа ≠ 0.\n";
    cout << " - (N & M) != 0 истинно, если у N и M есть общие установленные биты.\n";
    cout << " - (N || M) истинно, если хотя бы одно число ≠ 0.\n";
    cout << " - (N | M) != 0 истинно, если хотя бы один бит установлен в N или M.\n";
    cout << " - !N даёт true только если N == 0. Побитовый ~N просто инвертирует все биты.\n";

    return 0;
}
