#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* name;
    int age;

public:
    // ����������� � �����������
    Student(const char* n = "Unknown", int a = 0) : age(a) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    // ����������� �����������
    Student(const Student& obj) {
        name = new char[strlen(obj.name) + 1];
        strcpy_s(name, strlen(obj.name) + 1, obj.name);
        age = obj.age;
    }

    // ����������
    ~Student() {
        delete[] name;
    }

    // ���������� ��������� ����������� ���������� (++age)
    Student& operator++() {
        ++age;
        return *this;
    }

    // ���������� ��������� ������������ ���������� (age++)
    Student operator++(int) {
        Student temp = *this;
        ++age;
        return temp;
    }

    // ���������� ��������� ����������� ���������� (--age)
    Student& operator--() {
        --age;
        return *this;
    }

    // ���������� ��������� ������������ ���������� (age--)
    Student operator--(int) {
        Student temp = *this;
        --age;
        return temp;
    }

    // ����� ��� ������ ����������
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
