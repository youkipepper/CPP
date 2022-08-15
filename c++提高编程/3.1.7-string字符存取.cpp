#include <iostream>
using namespace std;

void test01()
{
    string str = "hello";

    // cout << "str= " << str << endl;

    for (size_t i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    str[0] = 'x';
    cout << "str= " << str << endl;
    str.at(1) = 'x';
    cout << "str= " << str << endl;
}

int main()
{
    test01();

    return 0;
}