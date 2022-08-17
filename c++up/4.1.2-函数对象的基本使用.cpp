#include <iostream>
using namespace std;
#include <string>

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test01()
{
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }
    int count; //内部自己状态
};

void test02()
{
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");

    cout << "myPrint 调用次数为: " << myPrint.count << endl;
}
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}
void test03()
{
    MyPrint myPrint;
    doPrint(myPrint, "Hello Cpp");
}

int main()
{
    // test01();
    // test02();
    test03();

    return 0;
}