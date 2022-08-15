#include <iostream>
using namespace std;
#include <string>

class MyPrint
{
public:
    //重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};

void MyPrint02(string test)
{
    cout << test << endl;
}

void test01()
{
    MyPrint myprint;

    myprint("Hello World"); //由于使用起来非常类似于函数调用, 因此被称为仿函数

    MyPrint02("Hello World");
}

//仿函数非常灵活, 没有固定写法
//加法类

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test02()
{
    MyAdd myadd;
    int ret = myadd(100, 100);
    cout << "ret= " << ret << endl;

    //匿名函数对象
    cout << MyAdd()(100, 100) << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}