#include <iostream>
using namespace std;

// int &test01()
// {
//     int a = 10;
//     return a;
// }

int &test02()
{
    static int a = 10; //静态变量, 存放在全局区, 全局区上的数据在程序结束后系统释放
    return a;
}

int main()
{
    // int &ref = test01();
    // cout << "trf=" << ref << endl;
    // cout << "trf=" << ref << endl;

    int &trf2 = test02();
    cout << "trf2= " << trf2 << endl;
    cout << "trf2= " << trf2 << endl;
    cout << "trf2= " << trf2 << endl;

    test02() = 1000;

    cout << "trf2= " << trf2 << endl;
    cout << "trf2= " << trf2 << endl;

    return 0;
}