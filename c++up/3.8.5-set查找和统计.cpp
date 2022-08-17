#include <iostream>
#include <set>
using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    set<int>::iterator pos = s1.find(300);
    if (pos != s1.end())
    {
        cout << "找到元素: " << *pos << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }
}

void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    //统计 30 的个数
    int num = s1.count(30);
    //对于 set 而言, 统计结果 要么是 0 要么是 1
    cout << "num = " << num << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}