#include <iostream>
using namespace std;

void test01()
{
    string str1 = "abcdefg";

    int pos = str1.find("df");

    if (pos == -1)
    {
        cout << "未找到字符串" << endl;
    }
    else
    {
        cout << "找到字符串, pos= " << pos << endl;
    }

    // rfind 和 find区别
    // rfind 是从右往左查找
    // find 是从左往右查找
    pos = str1.rfind("de");
    cout << "pos= " << pos << endl;
}

void test02()
{
    string str1 = "abcdefg";

    // 从 1号位置起 3个字符 替换为“1111”
    str1.replace(1, 3, "1111");
    cout << "str1= " << str1 << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}