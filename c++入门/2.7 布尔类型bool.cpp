#include <iostream>
using namespace std;

int main()
{
    // 1、创建bool数据类型
    bool flag = true; // true represent true
    cout << flag << endl;

    flag = false; // false represent false
    cout << flag << endl;

    //本质上1代表真,0代表假

    // 2、查看bool类型所占内存空间
    cout << "bool类型所占内存空间为:" << sizeof(bool) << endl;
    system("pause");

    return 0;
}
