#pragma once

// Часть 2. 
class DynamicArray {
private:
    int* data;      
    int size;       

public:
    DynamicArray(int arraySize);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    int getSize();
    void print();
    void set(int index, int value);              // ничего не возвращает, при ошибке бросает исключение
    int get(int index);
    void push_back(int value);
    void add(const DynamicArray& other);
    void sub(const DynamicArray& other);
};
