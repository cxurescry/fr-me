#include <iostream>
#include <iomanip>

int main() {
    int N, M;
    
    std::cout << "Введите два целых десятичных числа N и M (могут быть отрицательными): ";
    std::cin >> N >> M;
    
    std::cout << "\nВведенные числа:" << std::endl;
    std::cout << "N = " << N << std::endl;
    std::cout << "M = " << M << std::endl;
    
    std::cout << "\n=== Использование логических операторов (&&, ||, !) ===" << std::endl;
    
    // Логическое И (&&)
    std::cout << "\n1. Логическое И (&&):" << std::endl;
    if (N > 0 && M > 0) {
        std::cout << "   Условие (N > 0 && M > 0): ИСТИНА" << std::endl;
        std::cout << "   Оба числа положительные" << std::endl;
    } else {
        std::cout << "   Условие (N > 0 && M > 0): ЛОЖЬ" << std::endl;
        std::cout << "   Хотя бы одно число не положительное" << std::endl;
    }
    
    // Логическое ИЛИ (||)
    std::cout << "\n2. Логическое ИЛИ (||):" << std::endl;
    if (N > 0 || M > 0) {
        std::cout << "   Условие (N > 0 || M > 0): ИСТИНА" << std::endl;
        std::cout << "   Хотя бы одно число положительное" << std::endl;
    } else {
        std::cout << "   Условие (N > 0 || M > 0): ЛОЖЬ" << std::endl;
        std::cout << "   Оба числа не положительные" << std::endl;
    }
    
    // Логическое НЕ (!)
    std::cout << "\n3. Логическое НЕ (!):" << std::endl;
    if (!(N == 0)) {
        std::cout << "   Условие (!(N == 0)): ИСТИНА" << std::endl;
        std::cout << "   N не равно нулю" << std::endl;
    } else {
        std::cout << "   Условие (!(N == 0)): ЛОЖЬ" << std::endl;
        std::cout << "   N равно нулю" << std::endl;
    }
    
    // Комбинированное условие с логическими операторами
    std::cout << "\n4. Комбинированное условие:" << std::endl;
    if ((N > 0 && M < 0) || (N < 0 && M > 0)) {
        std::cout << "   Условие ((N > 0 && M < 0) || (N < 0 && M > 0)): ИСТИНА" << std::endl;
        std::cout << "   Числа имеют разные знаки" << std::endl;
    } else {
        std::cout << "   Условие ((N > 0 && M < 0) || (N < 0 && M > 0)): ЛОЖЬ" << std::endl;
        std::cout << "   Числа имеют одинаковые знаки или одно из них равно нулю" << std::endl;
    }
    
    std::cout << "\n=== Использование побитовых операторов (&, |, ~) ===" << std::endl;
    
    // Побитовое И (&)
    std::cout << "\n1. Побитовое И (&):" << std::endl;
    int bitwiseAnd = N & M;
    std::cout << "   N & M = " << bitwiseAnd << std::endl;
    if (N & M) {
        std::cout << "   Условие (N & M): ИСТИНА (результат не равен нулю)" << std::endl;
    } else {
        std::cout << "   Условие (N & M): ЛОЖЬ (результат равен нулю)" << std::endl;
    }
    
    // Побитовое ИЛИ (|)
    std::cout << "\n2. Побитовое ИЛИ (|):" << std::endl;
    int bitwiseOr = N | M;
    std::cout << "   N | M = " << bitwiseOr << std::endl;
    if (N | M) {
        std::cout << "   Условие (N | M): ИСТИНА (результат не равен нулю)" << std::endl;
    } else {
        std::cout << "   Условие (N | M): ЛОЖЬ (результат равен нулю)" << std::endl;
    }
    
    // Побитовое НЕ (~)
    std::cout << "\n3. Побитовое НЕ (~):" << std::endl;
    int bitwiseNotN = ~N;
    std::cout << "   ~N = " << bitwiseNotN << std::endl;
    if (~N) {
        std::cout << "   Условие (~N): ИСТИНА (результат не равен нулю)" << std::endl;
    } else {
        std::cout << "   Условие (~N): ЛОЖЬ (результат равен нулю)" << std::endl;
    }
    
    // Комбинированное условие с побитовыми операторами
    std::cout << "\n4. Комбинированное условие с побитовыми операторами:" << std::endl;
    if ((N & 1) && (M & 1)) {
        std::cout << "   Условие ((N & 1) && (M & 1)): ИСТИНА" << std::endl;
        std::cout << "   Оба числа нечетные (младший бит = 1)" << std::endl;
    } else {
        std::cout << "   Условие ((N & 1) && (M & 1)): ЛОЖЬ" << std::endl;
        std::cout << "   Хотя бы одно число четное" << std::endl;
    }
    
    // Сравнение логических и побитовых операторов
    std::cout << "\n=== Сравнение результатов ===" << std::endl;
    
    bool logicalAnd = (N > 0) && (M > 0);
    bool bitwiseAndBool = (N > 0) & (M > 0);
    std::cout << "(N > 0) && (M > 0) = " << std::boolalpha << logicalAnd << std::endl;
    std::cout << "(N > 0) & (M > 0) = " << std::boolalpha << bitwiseAndBool << std::endl;
    
    bool logicalOr = (N > 0) || (M > 0);
    bool bitwiseOrBool = (N > 0) | (M > 0);
    std::cout << "(N > 0) || (M > 0) = " << std::boolalpha << logicalOr << std::endl;
    std::cout << "(N > 0) | (M > 0) = " << std::boolalpha << bitwiseOrBool << std::endl;
    
    bool logicalNot = !(N == 0);
    bool bitwiseNotBool = ~(N == 0);
    std::cout << "!(N == 0) = " << std::boolalpha << logicalNot << std::endl;
    std::cout << "~(N == 0) = " << std::boolalpha << bitwiseNotBool << std::endl;
    std::cout << "   Примечание: ~(N == 0) работает некорректно, так как ~ применяется к целому числу (0 или 1)" << std::endl;
    
    std::cout << "\n=== ВЫВОД ===" << std::endl;
    std::cout << "Корректность замены логических операций на побитовые в условных операторах:" << std::endl;
    std::cout << "\n1. Логические операторы (&&, ||, !):" << std::endl;
    std::cout << "   - Используют short-circuit evaluation (сокращенное вычисление)" << std::endl;
    std::cout << "   - Для &&: если левая часть ложь, правая часть не вычисляется" << std::endl;
    std::cout << "   - Для ||: если левая часть истина, правая часть не вычисляется" << std::endl;
    std::cout << "   - Возвращают булево значение (true/false)" << std::endl;
    std::cout << "   - Оператор ! инвертирует булево значение" << std::endl;
    
    std::cout << "\n2. Побитовые операторы (&, |, ~):" << std::endl;
    std::cout << "   - Всегда вычисляют оба операнда" << std::endl;
    std::cout << "   - Выполняют операции над каждым битом" << std::endl;
    std::cout << "   - Возвращают целочисленное значение" << std::endl;
    std::cout << "   - Оператор ~ инвертирует все биты числа" << std::endl;
            
    return 0;
}

