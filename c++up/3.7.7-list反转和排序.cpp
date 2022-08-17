#include <iostream>
#include <list>
using namespace std;
#include <algorithm>

void printList(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int> l1;
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);

    cout << "反转前: " << endl;
    printList(l1);

    cout << "反转后: " << endl;
    l1.reverse();
    printList(l1);
}

bool myCompare(int v1, int v2)
{
    //降序 就让第一个数>第二个数
    return v1>v2;
}

void test02()
{
    list<int> l1;
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);

    cout << "排序前: " << endl;
    printList(l1);

    cout << "排序后: " << endl;

    //所有不支持随机访问的迭代器的容器, 不可以用标准算法
    //不支持随机访问的迭代器的容器, 内部会提供对应的一些算法
    // sort(l1.begin(), l1.end());
    l1.sort(); //默认排序规则 从小到大 升序

    l1.sort(myCompare);
    printList(l1);

}

int main()
{
    // test01();
    test02();

    return 0;
}