#include <iostream>
using namespace std;
#include "MyArray.hpp"

void printArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    MyArray<int> arr1(5);

    // MyArray<int> arr3(100);
    // arr3 = arr1;

    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }
    cout << "arr1的打印输出为: ";
    printArray(arr1);

    cout << "arr1的容量为: " << arr1.getCapacity() << endl;
    cout << "arr1的大小为: " << arr1.getSize() << endl;

    MyArray<int> arr2(arr1);
    cout << "arr2的打印输出为: ";
    printArray(arr2);

    arr2.Pop_Back();
    cout << "arr2尾删后: " << endl;
    cout << "arr2的容量为: " << arr2.getCapacity() << endl;
    cout << "arr2的大小为: " << arr2.getSize() << endl;
}

class Person
{
public:
    Person(){};
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "name: " << arr[i].m_Name << " age: " << arr[i].m_Age << endl;
    }
}

void test02()
{
    MyArray<Person> arr(10);
    Person p1("Tom", 18);
    Person p2("Jerry", 18);
    Person p3("Spike", 35);
    Person p4("Tyke", 8);
    Person p5("Tuffy", 6);

    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    printPersonArray(arr);

    cout << "arr容量为: " << arr.getCapacity() << endl;
    cout << "arr大小为: " << arr.getSize() << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}