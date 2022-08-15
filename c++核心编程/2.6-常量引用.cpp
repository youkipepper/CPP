#include <iostream>
using namespace std;

void showValue(const int &val)
{
    // val = 1000;
    cout << "val = " << val << endl;
}

int main()
{
    // int a = 10;

    //加上 const 之后, 编译器将代码修改 int temp = 0; const int & ref =temp
    // const int &ref = 10; //引用必须引一块合法的内存空间
    // ref = 20;            //加上 const 之后变为只读, 不可以修改

    int a = 100;
    showValue(a);

    cout << "a= " << a << endl;

    return 0;
}