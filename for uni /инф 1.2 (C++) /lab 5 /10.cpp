#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

// Функция для получения номера символа в алфавите
int getAlphabetPosition(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return 0; // Не буква
}

// Функция для перевода в строчный регистр (битовая операция)
char toLowercaseBitwise(char c) {
    // Устанавливаем 6-й бит (0x20 = 32)
    return c | 0x20;
}

// Функция для перевода в заглавный регистр (битовая операция)
char toUppercaseBitwise(char c) {
    // Сбрасываем 6-й бит (0xDF = ~0x20)
    return c & 0xDF;
}

// Функция для инвертирования регистра (битовая операция)
char toggleCaseBitwise(char c) {
    // Инвертируем 6-й бит (XOR с 0x20)
    return c ^ 0x20;
}

int main() {
    // ========== ЧАСТЬ 1: Работа с ASCII символами ==========
    std::cout << "=== ЧАСТЬ 1: Работа с ASCII символами ===" << std::endl;

    char c1, c2, c3;
    std::cout << "\nВведите 3 латинских символа: ";
    std::cin >> c1 >> c2 >> c3;

    std::cout << "\nВведенные символы:" << std::endl;
    std::cout << "1-й символ: '" << c1 << "' (код: " << (int)(unsigned char)c1 << ")" << std::endl;
    std::cout << "2-й символ: '" << c2 << "' (код: " << (int)(unsigned char)c2 << ")" << std::endl;
    std::cout << "3-й символ: '" << c3 << "' (код: " << (int)(unsigned char)c3 << ")" << std::endl;

    // Выводим номера в алфавите для 1-го и 2-го символов (до изменения)
    std::cout << "\nНомера в алфавите (до изменения):" << std::endl;
    int pos1_initial = getAlphabetPosition(c1);
    int pos2_initial = getAlphabetPosition(c2);

    if (pos1_initial > 0) {
        std::cout << "1-й символ '" << c1 << "' - номер в алфавите: " << pos1_initial << std::endl;
    } else {
        std::cout << "1-й символ '" << c1 << "' - не является буквой" << std::endl;
    }

    if (pos2_initial > 0) {
        std::cout << "2-й символ '" << c2 << "' - номер в алфавите: " << pos2_initial << std::endl;
    } else {
        std::cout << "2-й символ '" << c2 << "' - не является буквой" << std::endl;
    }

    // Изменяем регистр символов с помощью битовых операций
    std::cout << "\nИзменение регистра с помощью битовых операций:" << std::endl;

    // 1-й символ в строчный
    char c1_lower = toLowercaseBitwise(c1);
    std::cout << "1-й символ: '" << c1 << "' -> '" << c1_lower << "' (строчный)" << std::endl;
    std::cout << "   Операция: c | 0x20 (установка 6-го бита)" << std::endl;

    // 2-й символ в заглавный
    char c2_upper = toUppercaseBitwise(c2);
    std::cout << "2-й символ: '" << c2 << "' -> '" << c2_upper << "' (заглавный)" << std::endl;
    std::cout << "   Операция: c & 0xDF (сброс 6-го бита)" << std::endl;

    // 3-й символ - инвертируем регистр
    char c3_toggled = toggleCaseBitwise(c3);
    std::cout << "3-й символ: '" << c3 << "' -> '" << c3_toggled << "' (инвертирован регистр)" << std::endl;
    std::cout << "   Операция: c ^ 0x20 (инверсия 6-го бита)" << std::endl;

    // Выводим номера измененных символов в алфавите
    std::cout << "\nНомера в алфавите (после изменения):" << std::endl;

    int pos1_modified = getAlphabetPosition(c1_lower);
    int pos2_modified = getAlphabetPosition(c2_upper);
    int pos3_modified = getAlphabetPosition(c3_toggled);

    if (pos1_modified > 0) {
        std::cout << "1-й символ '" << c1_lower << "' - номер в алфавите: " << pos1_modified;
        if (pos1_initial > 0 && pos1_initial == pos1_modified) {
            std::cout << " ✓ (правильно, номер не изменился)" << std::endl;
        } else if (pos1_initial > 0) {
            std::cout << " (было: " << pos1_initial << ")" << std::endl;
        } else {
            std::cout << std::endl;
        }
    } else {
        std::cout << "1-й символ '" << c1_lower << "' - не является буквой" << std::endl;
    }

    if (pos2_modified > 0) {
        std::cout << "2-й символ '" << c2_upper << "' - номер в алфавите: " << pos2_modified;
        if (pos2_initial > 0 && pos2_initial == pos2_modified) {
            std::cout << " ✓ (правильно, номер не изменился)" << std::endl;
        } else if (pos2_initial > 0) {
            std::cout << " (было: " << pos2_initial << ")" << std::endl;
        } else {
            std::cout << std::endl;
        }
    } else {
        std::cout << "2-й символ '" << c2_upper << "' - не является буквой" << std::endl;
    }

    if (pos3_modified > 0) {
        int pos3_initial = getAlphabetPosition(c3);
        std::cout << "3-й символ '" << c3_toggled << "' - номер в алфавите: " << pos3_modified;
        if (pos3_initial > 0 && pos3_initial == pos3_modified) {
            std::cout << " ✓ (правильно, номер не изменился)" << std::endl;
        } else if (pos3_initial > 0) {
            std::cout << " (было: " << pos3_initial << ")" << std::endl;
        } else {
            std::cout << std::endl;
        }
    } else {
        std::cout << "3-й символ '" << c3_toggled << "' - не является буквой" << std::endl;
    }

    // Проверка правильности
    std::cout << "\nПроверка правильности:" << std::endl;
    bool correct1 = (pos1_initial > 0 && pos1_initial == pos1_modified);
    bool correct2 = (pos2_initial > 0 && pos2_initial == pos2_modified);
    int pos3_initial = getAlphabetPosition(c3);
    bool correct3 = (pos3_initial > 0 && pos3_initial == pos3_modified);

    if (correct1 && correct2 && correct3) {
        std::cout << "✓ Все номера в алфавите правильные - изменение регистра не влияет на позицию в алфавите" << std::endl;
    } else {
        std::cout << "Результаты проверки:" << std::endl;
        if (pos1_initial > 0) {
            std::cout << "  1-й символ: " << (correct1 ? "✓" : "✗") << std::endl;
        }
        if (pos2_initial > 0) {
            std::cout << "  2-й символ: " << (correct2 ? "✓" : "✗") << std::endl;
        }
        if (pos3_initial > 0) {
            std::cout << "  3-й символ: " << (correct3 ? "✓" : "✗") << std::endl;
        }
    }

    // ========== ЧАСТЬ 2: Работа с KOI8-R ==========
    std::cout << "\n\n=== ЧАСТЬ 2: Работа с KOI8-R ===" << std::endl;

    // Русский текст в кодировке KOI8-R
    // Пример: "Привет" в KOI8-R
    // В KOI8-R русские буквы имеют коды от 0xE0 до 0xFF
    // Для демонстрации используем строку с русскими символами

    std::cout << "\nВведите русский текст (в кодировке KOI8-R) или нажмите Enter для использования примера: ";
    std::cin.ignore(); // Очищаем буфер после предыдущего ввода
    std::string russianText;
    std::getline(std::cin, russianText);

    // Если строка пустая, используем пример
    if (russianText.empty()) {
        // Пример текста на русском (в реальности нужно было бы использовать KOI8-R коды)
        // Для демонстрации используем символы, которые при сбросе 7-го бита дадут читаемый результат
        // В KOI8-R русские буквы: А=0xE1, Б=0xE2, В=0xE3, и т.д.
        // При сбросе 7-го бита (0x7F): 0xE1 & 0x7F = 0x61 = 'a'
        // Это создаст транслитерацию

        // Создаем строку с русскими символами в KOI8-R
        // Для примера используем прямые коды KOI8-R
        unsigned char koi8r_text[] = {
            0xF0, 0xD2, 0xC9, 0xD7, 0xC5, 0xD4  // "ПРИВЕТ" в KOI8-R
        };
        russianText = std::string((char*)koi8r_text, 6);
        std::cout << "Используется пример: \"ПРИВЕТ\" в KOI8-R" << std::endl;
    }

    std::cout << "\nИсходный текст (KOI8-R):" << std::endl;
    std::cout << "Длина: " << russianText.length() << " символов" << std::endl;
    std::cout << "Коды символов (hex): ";
    for (size_t i = 0; i < russianText.length(); ++i) {
        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2)
                  << (int)(unsigned char)russianText[i] << " ";
    }
    std::cout << std::dec << std::endl;

    // Сбрасываем 7-й бит каждого символа
    std::string transliterated;
    std::cout << "\nСброс 7-го бита (операция: c & 0x7F):" << std::endl;
    std::cout << "Коды символов после сброса (hex): ";

    for (size_t i = 0; i < russianText.length(); ++i) {
        unsigned char original = (unsigned char)russianText[i];
        unsigned char modified = original & 0x7F; // Сброс 7-го бита
        transliterated += (char)modified;
        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2)
                  << (int)modified << " ";
    }
    std::cout << std::dec << std::endl;

    // Выводим результат
    std::cout << "\nРезультат (транслитерация):" << std::endl;
    std::cout << transliterated << std::endl;

    // Анализ читаемости транслитерации
    std::cout << "\nАнализ читаемости транслитерации:" << std::endl;
    std::cout << "При сбросе 7-го бита (старшего бита) в кодировке KOI8-R:" << std::endl;
    std::cout << "- Русские заглавные буквы в KOI8-R имеют коды от 0xE0 до 0xFF" << std::endl;
    std::cout << "- При сбросе 7-го бита (операция & 0x7F) получаем коды от 0x60 до 0x7F" << std::endl;
    std::cout << "- Это соответствует латинским строчным буквам и некоторым символам" << std::endl;
    std::cout << "- Результат представляет собой транслитерацию русских букв в латинские" << std::endl;
    std::cout << "- Читаемость: результат может быть частично читаемым, так как:" << std::endl;
    std::cout << "  * Некоторые русские буквы транслитерируются в похожие латинские (например, Р->p, И->i)" << std::endl;
    std::cout << "  * Но не все соответствия идеальны из-за особенностей кодировки" << std::endl;
    std::cout << "  * Транслитерация работает только для заглавных русских букв" << std::endl;

    // Дополнительная информация
    std::cout << "\nДополнительная информация:" << std::endl;
    std::cout << "Примеры соответствий KOI8-R -> транслитерация (после & 0x7F):" << std::endl;
    std::cout << "  А (0xE1) -> a (0x61)" << std::endl;
    std::cout << "  Б (0xE2) -> b (0x62)" << std::endl;
    std::cout << "  В (0xE3) -> c (0x63)" << std::endl;
    std::cout << "  Р (0xF0) -> p (0x70)" << std::endl;
    std::cout << "  И (0xD2) -> R (0x52) - не идеальное соответствие" << std::endl;
    std::cout << "\nВывод: Транслитерация частично читаема, но не идеальна из-за особенностей" << std::endl;
    std::cout << "       кодировки KOI8-R и ограничений метода сброса одного бита." << std::endl;

    return 0;
}

