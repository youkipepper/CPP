#include <iostream>
using namespace std;

template <class T1, class T2>
class Person;

template <class T1, class T2>
void printPerson2(Person<T1, T2> p)
{

    cout << "out::name: " << p.m_Name << endl;
    cout << "out::age: " << p.m_Age << endl;
}

template <class T1, class T2>

class Person
{
    friend void printPerson(Person<T1, T2> p)
    {
        cout << "name: " << p.m_Name << endl;
        cout << "age: " << p.m_Age << endl;
    }

    friend void printPerson2<>(Person<T1, T2> p);
    // {
    //     cout << "name: " << p.m_Name << endl;
    //     cout << "age: " << p.m_Age << endl;
    // }

public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

void test01()
{
    Person<string, int> p("Tom", 18);
    printPerson(p);
}

void test02()
{
    Person<string, int> p("Jerry", 20);
    printPerson2(p);
}

int main()
{
    test01();
    test02();

    return 0;
}