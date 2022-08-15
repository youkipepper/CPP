#include <iostream>
using namespace std;

class MyInteger
{
    friend ostream &operator<<(ostream &cout, MyInteger myint);

public:
    MyInteger()
    {

        m_Num = 0;
    }

    //重载前置++运算符
    MyInteger &operator++()
    {
        //先进行++运算
        m_Num++;

        //再将自身返回
        return *this;
    }

    //重载后置++运算符
    // void operator++(int) int代表占位参数, 可以用于区分前置和后置递增
    MyInteger operator++(int)
    {
        //先 记录当时结果
        MyInteger temp = *this;

        //后 递增
        m_Num++;

        //最后将记录的结果做返回
        return temp;
    }

private:
    int m_Num = 0;
};

//重载左移运算符
ostream &operator<<(ostream &cout, MyInteger myint)
{
    cout << myint.m_Num;
    return cout;
}

void test01()
{
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}

void test02()
{
    MyInteger myint;

    cout << myint++ << endl;
    cout << myint << endl;
}

int main()
{
    // test01();
    test02();

    // int a = 0;
    // cout << ++(++a) << endl;
    // cout << a << endl;

    return 0;
}