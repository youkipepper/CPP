#include <iostream>
#include <map>
using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " second = " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printMap(m);

    if (m.empty())
    {
        cout << "m为空" << endl;
    }
    else
    {
        cout << "m不为空" << endl;
        cout << "m的大小为: " << m.size() << endl;
    }
}

void test02()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    map<int, int> m2;
    m2.insert(pair<int, int>(5, 500));
    m2.insert(pair<int, int>(6, 600));
    m2.insert(pair<int, int>(7, 700));
    m2.insert(pair<int, int>(8, 800));

    cout << "交换前: " << endl;
    printMap(m);
    printMap(m2);

    cout << "交换后: " << endl;
    m.swap(m2);
    printMap(m);
    printMap(m2);
}

int main()
{
    // test01();
    test02();

    return 0;
}