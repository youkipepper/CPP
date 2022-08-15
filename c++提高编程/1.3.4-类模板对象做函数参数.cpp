#include <iostream>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "name: " << this->m_Name << endl;
        cout << "age: " << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

//指定传入类型
void printPerson(Person<string, int> &p)
{
    p.showPerson();
}

void test01()
{
    Person<string, int> p("Tom", 18);
    printPerson(p);
}

// 2、参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    p.showPerson();
    cout << "T1的类型为: " << typeid(T1).name() << endl;
    cout << "T2的类型为: " << typeid(T2).name() << endl;
}

void test02()
{
    Person<string, int> p("Jerry", 16);
    printPerson2(p);
}

// 3、整个类模板化
template <class T>
void printPerson3(T &p)
{
    p.showPerson();
    cout << "T的数据类型" << typeid(T).name() << endl;
}

void test03()
{
    Person<string, int> p("Spike", 20);
    printPerson3(p);
}

int main()
{
    // test01();
    // test02();
    test03();

    return 0;
}