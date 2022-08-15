#include <iostream>
using namespace std;

template <class T> // typename可以替换为class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    // mySwap(a, b);
    // mySwap(a, c);//错误, 推导不出一致T类型

    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
}

template <class T>
void func()
{
    cout << "func 调用" << endl;
}

void test02()
{
    func<int>();
}

int main()
{
    // test01();
    test02();

    return 0;
}