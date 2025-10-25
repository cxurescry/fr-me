#include <iostream>
#include <string>
#include <locale>

int main() {
    char symbol1, symbol2, symbol3;
    std::cout << "Введите 3 латинских символа: ";
    std::cin >> symbol1 >> symbol2 >> symbol3;

    // Перевод 1 символа в строчный
    if (symbol1 >= 'A' && symbol1 <= 'Z') {
        symbol1 = symbol1 | 0x20; // Установка 5-го бита (символ становится строчным)
    }

    // Перевод 2 символа в заглавный
    if (symbol2 >= 'a' && symbol2 <= 'z') {
        symbol2 = symbol2 & 0xDF; // Сброс 5-го бита (символ становится заглавным)
    }

    // Вывод номеров символов в алфавите
    int num1 = (symbol1 >= 'a' && symbol1 <= 'z') ? (symbol1 - 'a' + 1) : (symbol1 - 'A' + 1);
    int num2 = (symbol2 >= 'a' && symbol2 <= 'z') ? (symbol2 - 'a' + 1) : (symbol2 - 'A' + 1);
    int num3 = (symbol3 >= 'a' && symbol3 <= 'z') ? (symbol3 - 'a' + 1) : (symbol3 - 'A' + 1);

    std::cout << "Номер символа 1 в алфавите: " << num1 << std::endl;
    std::cout << "Номер символа 2 в алфавите: " << num2 << std::endl;
    std::cout << "Номер символа 3 в алфавите: " << num3 << std::endl;

    // Ввод текста на русском языке в кодировке KOI8-R
    std::string russian_text;
    std::cout << "Введите текст на русском языке (KOI8-R): ";
    std::cin.ignore(); // Очистка буфера
    std::getline(std::cin, russian_text);

    // Сброс 7-го (старшего) бита каждого символа
    for (char& c : russian_text) {
        c = c & 0x7F; // Сброс старшего бита
    }

    std::cout << "\nРезультат после сброса 7-го бита:" << std::endl;
    std::cout << russian_text << std::endl;

    std::cout << "\nАнализ читаемости транслитерации:" << std::endl;
    std::cout << "После сброса 7-го бита символы русского текста в кодировке KOI8-R становятся символами ASCII." << std::endl;
    std::cout << "Это приводит к появлению набора символов, которые могут быть читаемы как транслитерация, но часто не являются осмысленным текстом." << std::endl;
    std::cout << "Например, буква 'А' (KOI8-R: 0xC1) становится символом '!' (ASCII: 0x21). Это может быть полезно для некоторых целей, но не для чтения." << std::endl;

    return 0;
}
