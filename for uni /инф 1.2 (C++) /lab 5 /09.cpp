#include <iostream>
#include <iomanip>
#include <string>

int main() {
    int N, M;
    std::cout << "Введите числа N и M: ";
    std::cin >> N >> M;

    std::cout << "N = " << N << ", M = " << M << std::endl;

    // Сравнения с помощью оператора if
    if (N == M) {
        std::cout << "N равно M" << std::endl;
    } else if (N != M) {
        std::cout << "N не равно M" << std::endl;
    }

    if (N > M) {
        std::cout << "N больше M" << std::endl;
    } else if (N < M) {
        std::cout << "N меньше M" << std::endl;
    }

    if (N >= M) {
        std::cout << "N больше или равно M" << std::endl;
    } else if (N <= M) {
        std::cout << "N меньше или равно M" << std::endl;
    }

    // Проверка корректности замены логических операций на битовые
    // Пример: N && M эквивалентно (N != 0) & (M != 0) только если рассматривать ненулевое значение как true
    // Это не всегда корректно, так как логические операции работают с истинностью, а битовые - с битами.
    std::cout << "\nАнализ замены логических операций на битовые:" << std::endl;
    std::cout << "Логическое И (&&): " << (N && M) << std::endl;
    std::cout << "Битовое И (&): " << (N & M) << std::endl;
    std::cout << "Замена НЕкорректна, так как результаты могут отличаться." << std::endl;

    return 0;
}
