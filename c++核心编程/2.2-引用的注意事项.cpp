#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    // int &b;
    int &b = a;

    int c = 20;

    b = c; //赋值操作, 而不是更改引用

    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << "c= " << c << endl;

    return 0;
}