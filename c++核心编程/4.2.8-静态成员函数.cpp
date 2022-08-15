#include <iostream>
using namespace std;

class Person
{
public:
    static void func()
    {
        m_A = 100; //静态成员函数可以访问 静态成员变量
        // m_B = 200; //静态成员函数 不可以访问 非静态成员
        cout << "static void func调用" << endl;
    }

    static int m_A;
    int m_B;

    //静态成员函数是也是有访问权限的
private:
    static void func2()
    {
        cout << " static void func2的调用" << endl;
    }
};

int Person::m_A = 0;

void test01()
{
    //1、通过对象访问
    Person p;
    p.func();

    //2、通过类名访问
    Person::func();
    
    // Person::func2();
}

int main()
{
    test01();
    return 0;
}