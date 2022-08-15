#include <iostream>
using namespace std;

class Person
{
public:
    // this指针的本质 是指针常量 指针的指向是不可以修改的
    // Person *const this;
    //在成员函数后面加const,修饰的是this指针,让指针修改的值也不可以修改
    void showPerson() const
    {
        this->m_B = 100;
        // this->m_A = 100;
        // this = NULL; // this指针是不可以修改指针的指向的
    }

    void func()
    {
    }

    int m_A = 100;
    mutable int m_B; //特殊变量, 即使在常函数中, 也可以修改这个值, 也可以修改这个值, 加关键字 mutable
};

void test01()
{
    Person p;
    p.showPerson();
}

void test02()
{
    const Person p; //在对象前加const, 变为常对象
    // p.m_A = 100;
    p.m_B = 100;

    //常对象只能调用常函数
    p.showPerson();
    // p.func();
}