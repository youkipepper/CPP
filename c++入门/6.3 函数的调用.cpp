#include <iostream>
using namespace std;
//函数定义的时候, unm1和unm2没有真实数据, 称为“形式参数”,简称“形参”
int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

int main(void)
{
    int a = 10;
    int b = 20;
    //a和b有真实值, 称为“实际参数”, 简称“实参”
    //当调用函数的时候, 实参的值会传递给形参

    int c = add(a, b);
    cout << "c=" << c << endl;

    system("pause");
    return 0;
}