#include <iostream>
using namespace std;
int main(void)
{
    // 数组名用途
    // 1、可以通过数组名统计整个数组占用内存大小
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "整个数组占用的内存空间为:  " << sizeof(arr) << endl;
    cout << "每个元素占用的内存空间为:  " << sizeof(arr[0]) << endl;
    cout << "数组中元素的个数为:" << sizeof(arr) / sizeof(arr[0]) << endl;

    // 2、可以通过数组名称查看数组首地址
    cout << "数组首地址为: " << arr << endl;
    cout << "数组中第一个元素的首地址为: " << &arr[0] << endl;

    // 数组名是常量, 不可以进行赋值操作
    // arr=100;

    system("pause");
    return 0;
}
