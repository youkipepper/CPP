#include <iostream>
#include <set>
using namespace std;

// set 容器 大小和交换

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//大小
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    printSet(s1);
    // 判断是否为空
    if (s1.empty())
    {
        cout << "s1 为空" << endl;
    }
    else
    {
        cout << "s1 不为空" << endl;
    }
}

int main()
{
    test01();

    return 0;
}