#include <iostream>
using namespace std;
int main(void)
{
    int arr[2][3] =
        {
            {1, 2, 3},
            {4, 5, 6}};

    cout << "二维数组占用的空间为: " << sizeof(arr) << endl;
    cout << "二维数组第一行占用内存为: " << sizeof(arr[0]) << endl;
    cout << "二维数组第一个元素占用内存为:" << sizeof(arr[0][0]) << endl;

    cout << "二维数组行数为:" << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "二维数组列数为:" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

    cout << "二维数组的首地址为:" << (long)arr << endl;
    cout << "二维数组第一行首地址为:" << (long)arr[0] << endl;
    cout << "二维数组第二行首地址为:" << (long)arr[1] << endl;

    cout << "二维数组第一个元素的首地址为:" << (long)&arr[0][0] << endl;
    cout << "二维数组第一个元素的首地址为:" << (long)&arr[0][1] << endl;

    system("pause");
    return 0;
}