#include <iostream>
using namespace std;

class Person
{
public:
    static int m_A;
    //静态成员变量也是也有访问权限的
private:
    static int m_B;
};

int Person::m_A = 100;
int Person::m_B = 200;

void test01()
{
    Person p;
    cout << p.m_A << endl;

    Person p2;
    p.m_A = 200;
    cout << p.m_A << endl;
}

void test02()
{
    //静态成员变量 不属于某个对象, 所有对象都共享同一份数据
    //因此静态成员变量有两种访问方式

    // 1、通过对象进行访问
    Person p;
    // cout << p.m_A << endl;

    // 2、通过类名进行访问
    cout << Person::m_A << endl;

    cout << Person::m_B << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}