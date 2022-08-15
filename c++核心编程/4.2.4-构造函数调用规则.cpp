#include <iostream>
using namespace std;
class Person
{
public:
    // Person()
    // {
    //     cout << "Person的默认构造函数调用" << endl;
    // }

    Person(int age)
    {
        cout << "Person的有参构造函数低调用" << endl;
        m_Age = age;
    }

    // Person(const Person &p)
    // {
    //     cout << "Person的拷贝构造函数调用" << endl;
    //     m_Age = p.m_Age;
    // }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    int m_Age;
};

// void test01()
// {
//     Person p;
//     p.m_Age = 18;

//     Person p2(p);
//     cout << "p2的年龄为: " << p2.m_Age << endl;
// }

void test02()
{
    Person p(28);
    Person p2(p);

    cout << "p2的年龄为: " << p2.m_Age << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}