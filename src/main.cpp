#include "DynamicArray.h"
#include <iostream>
#include <utility>    
#include <vector>

// Функция принимает массив "по значению": значит получает СВОЮ копию (или переносится в неё)
void takeArray(DynamicArray<int> arr) {
    std::cout << "  внутри функции: " << arr << ", адрес данных " << arr.address() << std::endl;
}

int main() {
    // ---------- Задание 1: оператор присваивания ----------
    std::cout << "=== Задание 1: оператор присваивания ===" << std::endl;
    DynamicArray<int> a(3);
    a.set(0, 1);
    a.set(1, 2);
    a.set(2, 3);
    DynamicArray<int> b(5);
    std::cout << "до:    a = " << a << ", b = " << b << std::endl;
    b = a;                                    
    std::cout << "после: a = " << a << ", b = " << b << std::endl;
    b[0] = 99;                               
    std::cout << "b[0] = 99: a = " << a << ", b = " << b << std::endl;

    std::cout << "самоприсваивание:" << std::endl;
    DynamicArray<int>& same = b;
    b = same;
    std::cout << "b = " << b << " (не пострадала)" << std::endl;

    std::cout << "цепочка c = d = a:" << std::endl;
    DynamicArray<int> c(1);
    DynamicArray<int> d(1);
    c = d = a;
    std::cout << "c = " << c << ", d = " << d << std::endl;

    // ---------- Задание 2: конструктор переноса ----------
    std::cout << std::endl << "=== Задание 2: конструктор переноса ===" << std::endl;
    DynamicArray<int> source(4);
    source.set(0, 10);
    source.set(1, 20);
    source.set(2, 30);
    source.set(3, 40);
    std::cout << "source = " << source << ", адрес данных " << source.address() << std::endl;
    DynamicArray<int> moved(std::move(source));    
    std::cout << "moved  = " << moved << ", адрес данных " << moved.address() << " (тот же адрес)" << std::endl;
    std::cout << "source стал пустым: размер " << source.getSize() << ", адрес " << source.address() << std::endl;

    // ---------- Задание 3: присваивание с переносом ----------
    std::cout << std::endl << "=== Задание 3: присваивание с переносом ===" << std::endl;
    DynamicArray<int> target(2);
    std::cout << "до:    target = " << target << ", moved = " << moved << std::endl;
    target = std::move(moved);
    std::cout << "после: target = " << target << ", moved размер " << moved.getSize() << std::endl;

    // ---------- Задание 4: копирование против переноса ----------
    std::cout << std::endl << "=== Задание 4: до и после move ===" << std::endl;
    DynamicArray<int> big(5);
    for (int i = 0; i < 5; i++) {
        big.set(i, i * 10);
    }
    std::cout << "big = " << big << ", адрес данных " << big.address() << std::endl;

    std::cout << "1) Передаём в функцию по значению БЕЗ move (копирование):" << std::endl;
    takeArray(big);
    std::cout << "   big после вызова: " << big << " (на месте)" << std::endl;

    std::cout << "2) Передаём С move (перенос):" << std::endl;
    takeArray(std::move(big));                
    std::cout << "   big после вызова: размер " << big.getSize() << " (данные ушли в функцию)" << std::endl;

    std::cout << "3) Кладём в vector (контейнер):" << std::endl;
    DynamicArray<int> item(3);
    item.set(0,52);
    std::vector<DynamicArray<int>> list;
    std::cout << " push_back(item) без move:" << std::endl;
    list.push_back(item);                     // копия
    std::cout << " push_back(std::move(item)) с move:" << std::endl;
    list.push_back(std::move(item));          // перенос
    std::cout << "в векторе " << list.size() << " массива" << std::endl;

    std::cout << std::endl << "Конец программы. Деструкторы освободят всю память." << std::endl;
    return 0;
}
