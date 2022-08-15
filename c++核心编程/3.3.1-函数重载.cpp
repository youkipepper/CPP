#include <iostream>
using namespace std;

//函数重载的满足条件
// 1、同一作用域下
// 2、函数名称相同
// 3、- 函数参数 类型不同 或者 个数不同 或者 顺序不同
void func()
{
    cout << "func 的调用" << endl;
}

void func(int a)
{
    cout << "func(int a) 的调用!" << endl;
}

void func(double a)
{
    cout << "func(double a) 的调用!" << endl;
}

void func(int a, double b)
{
    cout << "func(int a, double b) 的调用!" << endl;
}

void func(double a, int b)
{
    cout << "func(int a, double b) 的调用!" << endl;
}

// void func(double a, int b)
// {
//     cout << "func(int a, double b) 的调用!" << endl;
// }

int main()
{
    // func();
    // func(10);
    // func(3.14);
    func(10, 3.14);

    return 0;
}