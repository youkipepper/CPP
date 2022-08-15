#include <iostream>
using namespace std;

//如果传入了数据, 就用传入的数据, 如果没有, 那就用默认值
int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

//注意事项
// 1、如果某个位置已经有了默认参数, 那么从这个位置往后, 从左往右都必须有默认值
// int func2(int a = 10, int b, int c)
// {
//     return a + b + c;
// }

// 2、如果函数的声明有了默认参数, 函数的实现就不能有默认参数了
//声明和实现只能有一个有默认参数
int func2(int a = 10, int b = 10);

int func2(int a, int b)
{
    return a + b;
}

int main()
{
    cout << func(10, 30) << endl;

    cout << func2(10, 10) << endl;
    return 0;
}