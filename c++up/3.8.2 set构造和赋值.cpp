// version 1.0

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

// set 容器构造和赋值
// set 容器特点: 所有元素插入的时候自动排序
// set 容器不允许插入重复的数值
void test01()
{
    set<int> s1;

    //插入数据 只有 insert 方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

    //拷贝构造
    set<int>s2(s1);
    printSet(s2);

    //赋值
    set<int>s3;
    s3=s2;
    printSet(s3);

    //遍历容器
    printSet(s1);
}

int main()
{
    test01();

    return 0;
}