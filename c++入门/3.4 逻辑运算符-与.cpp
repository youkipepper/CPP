#include <iostream>
using namespace std;

int main()
{
    //逻辑运算符-与 &&
    int a = 10;
    int b = 10;

    cout << (a && b) << endl;

    a = 0;
    b = 10;
    cout << (a && b) << endl;

    a = 0;
    b = 0;
    cout << (a && b) << endl;

    system("pause");

    return 0;
}
//同真为真,其余为假
