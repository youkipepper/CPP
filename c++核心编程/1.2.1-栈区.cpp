#include <iostream>
using namespace std;

int *func()
{
    int a = 0; //局部变量 存放在栈区, 栈区的数据在函数执行完后自动释放
    return &a; //返回局部变量地址
}

int main()
{
    //接受func函数的返回值
    int *p = func();

    cout << *p << endl; //第一次可以打印正确的数字, 是因为编译器做了保留
    cout << *p << endl; //第二次这个数据就不再保留了

    return 0;
}