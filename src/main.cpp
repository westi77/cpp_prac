#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    DynamicArray<int> a(4);
    a.set(0, 1);
    a.set(1, 2);
    a.set(2, 3);
    a.set(3, 4);
    std::cout << "a = " << a << std::endl;

    // ---------- Задание 1: оператор [] ----------
    std::cout << std::endl << "=== Задание 1: оператор [] ===" << std::endl;
    std::cout << "a[2] = " << a[2] << std::endl;      // чтение
    a[2] = 30;                                         // запись
    std::cout << "после a[2] = 30: " << a << std::endl;
    try {
        std::cout << a[10] << std::endl;               // индекса 10 нет
    } catch (const std::out_of_range& e) {
        std::cout << "out_of_range: " << e.what() << std::endl;
    }
    try {
        a[-1] = 5;                                     // отрицательный индекс тоже ошибка
    } catch (const std::out_of_range& e) {
        std::cout << "out_of_range: " << e.what() << std::endl;
    }

    // ---------- Задание 2: == и != ----------
    std::cout << std::endl << "=== Задание 2: == и != ===" << std::endl;
    DynamicArray<int> b(a);                            // b - копия a
    std::cout << "b = " << b << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;  // 1 (true)
    std::cout << "a != b: " << (a != b) << std::endl;  // 0 (false)
    b[0] = 100;
    std::cout << "после b[0] = 100, b = " << b << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;  // 0
    std::cout << "a != b: " << (a != b) << std::endl;  // 1
    DynamicArray<int> shortArray(2);
    std::cout << "массивы разного размера равны? " << (a == shortArray) << std::endl;   // 0

    // ---------- Задание 3: ----------
    std::cout << std::endl << "=== Задание 3: ===" << std::endl;
    DynamicArray<int> c(2);
    c.set(0, 10);
    c.set(1, 20);
    std::cout << "a = " << a << ", c = " << c << std::endl;
    a += c;                                            // c короче: прибавятся только первые 2 элемента
    std::cout << "a += c: " << a << std::endl;
    a -= c;
    std::cout << "a -= c: " << a << std::endl;
    a += 5;                                            // число ко всем элементам
    std::cout << "a += 5: " << a << std::endl;
    a -= 5;
    std::cout << "a -= 5: " << a << std::endl;

    // ---------- Задание 4: begin() и end() ----------
    std::cout << std::endl << "=== Задание 4: цикл for по массиву ===" << std::endl;
    std::cout << "Читаем: ";
    for (const auto& x : a) {                          // только читаем
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (auto& x : a) {                                // &: можем менять элементы
        x = x * 2;
    }
    std::cout << "После x = x * 2: " << a << std::endl;

    const DynamicArray<int>& constA = a;               // константная ссылка: менять нельзя, читать можно
    int sum = 0;
    for (int x : constA) {
        sum = sum + x;
    }
    std::cout << "Сумма элементов: " << sum << std::endl;

    std::cout << std::endl << "=== Массив string ===" << std::endl;
    DynamicArray<std::string> s(2);
    s[0] = "hello";
    s[1] = "world";
    DynamicArray<std::string> s2(s);
    std::cout << "s = " << s << std::endl;
    std::cout << "s == s2: " << (s == s2) << std::endl;
    for (auto& word : s) {
        word = word + "!";
    }
    std::cout << "после добавления ! : " << s << std::endl;
    std::cout << "s == s2: " << (s == s2) << std::endl;

    return 0;
}
