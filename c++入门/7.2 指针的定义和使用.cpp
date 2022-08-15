#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p = &a;
    cout << "a的地址为: " << (long long)&a << endl;
    cout << "指针p为: " << (long long)p << endl;

    *p = 1000;
    cout << "a= " << a << endl;
    cout << "*p= " << *p << endl;

    return 0;
}