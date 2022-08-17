#include <iostream>
using namespace std;

void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

template <typename T> //声明一个模板, 告诉编译器后面代码中紧跟着的T不要报错
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
    // swapInt(a, b);

    // 1、自动类型推导
    // mySwap(a, b);

    // 2、显示指定类型
    mySwap<int>(a, b);

    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
}

int main()
{
    test01();

    return 0;
}