#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* name;
    int age;

public:
    // Конструктор с параметрами
    Student(const char* n = "Unknown", int a = 0) : age(a) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    // Конструктор копирования
    Student(const Student& obj) {
        name = new char[strlen(obj.name) + 1];
        strcpy_s(name, strlen(obj.name) + 1, obj.name);
        age = obj.age;
    }

    // Деструктор
    ~Student() {
        delete[] name;
    }

    // Перегрузка оператора префиксного инкремента (++age)
    Student& operator++() {
        ++age;
        return *this;
    }

    // Перегрузка оператора постфиксного инкремента (age++)
    Student operator++(int) {
        Student temp = *this;
        ++age;
        return temp;
    }

    // Перегрузка оператора префиксного декремента (--age)
    Student& operator--() {
        --age;
        return *this;
    }

    // Перегрузка оператора постфиксного декремента (age--)
    Student operator--(int) {
        Student temp = *this;
        --age;
        return temp;
    }

    // Метод для вывода информации
    void Print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student s1("Dima", 18);

    cout << "Initial: ";
    s1.Print();

    cout << "Using prefix increment (++s1): ";
    ++s1;
    s1.Print();

    cout << "Using postfix increment (s1++): ";
    s1++;
    s1.Print();

    cout << "Using prefix decrement (--s1): ";
    --s1;
    s1.Print();

    cout << "Using postfix decrement (s1--): ";
    s1--;
    s1.Print();

    return 0;
}
