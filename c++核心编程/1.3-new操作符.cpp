#include <iostream>
using namespace std;

int *func()
{
    int *p = new int(100);
    return p;
}

void test01()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    //堆区的数据 由程序员管理开辟, 程序员管理释放
    //如果想释放堆区数据, 利用关键字 delete

    delete p;
    // cout << *p << endl;
    // cout << *p << endl;
}

void test02()
{
    int *arr = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    //释放数组的时候 要加[]才可以
    delete[] arr;
}

int main()
{
    // test01();
    test02();

    return 0;
}