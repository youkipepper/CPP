#include <iostream>
#include <map>
using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value= " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));

    map<int, int>::iterator pos = m.find(3);
    if (pos != m.end())
    {
        cout << "找到了元素 key = " << pos->first << " value = " << pos->second;
    }
    else
    {
        cout << "未找到元素" << endl;
    }
    cout << endl;

    //统计
    //map不允许插入重复 key 元素, count 统计而言, 结果要么是0, 要么是1
    int num = m.count(3);
    cout << "num = " << num << endl;
}

int main()
{
    test01();

    return 0;
}