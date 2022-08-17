/*
 * @Author: youki.cui
 * @Date: 2022-08-16 21:37:39
 * @LastEditors: youki.cui
 * @LastEditTime: 2022-08-16 21:47:43
 * @Description: Once again to change everything.
 *
 */
#include <iostream>
#include <set>
using namespace std;

void test01()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second)
    {
        cout << "第一次插入成功" << endl;
    }
    else
    {
        cout << "第一次插入失败" << endl;
    }

    ret = s.insert(10);
    if (ret.second)
    {
        cout << "第二次插入成功" << endl;
    }
    else
    {
        cout << "第二次插入失败" << endl;
    }

    multiset<int> ms;
    //允许插入重复的值
    ms.insert(10);
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();

    return 0;
}
