#include <iostream>
using namespace std;

void mySwap01(int a, int b) // 1、值传递
{
    int temp = a;
    a = b;
    b = temp;

    cout << "swap01 a= " << a << endl;
    cout << "swap02 b= " << b << endl;
}

void mySwap02(int *p1, int *p2) // 2、地址传递
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    // mySwap01(a, b);

    // mySwap02(&a, &b);

    mySwap03(a, b);

    cout << "a= " << a << endl;
    cout << "b= " << b << endl;

    return 0;
}