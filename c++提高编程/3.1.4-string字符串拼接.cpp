#include <iostream>
using namespace std;
#include <string>

void test01()
{
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << "str1= " << str1 << endl;

    str1 += ":";
    cout << "str1= " << str1 << endl;

    string str2 = "LOL DNF";
    str1 += str2;
    cout << "str1= " << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << "str3= " << str3 << endl;

    str3.append("game abcde", 4);
    cout << "str3= " << str3 << endl;

    // str3.append(str2);
    cout << "str3=" << str3 << endl;

    str3.append(str2, 4, 3);
    cout << "str3= " << str3 << endl;

}

int main()
{
    test01();

    return 0;
}