#include <iostream>
using namespace std;

void test01()
{
    string str = "abcdef";
    string subStr = str.substr(1, 3);

    cout << "subStr = " << subStr << endl;
}

void test02()
{
    string email = "zhangsan@sina.com";
    int pos = email.find("@");
    cout << pos << endl;

    string userName = email.substr(0, pos);
    cout << userName << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}