#include <iostream>
#include <map>
#include <string>
using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value: " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 2));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;

    // cout << m[4] << endl;

    printMap(m);

    m.erase(m.begin());
    printMap(m);

    m.erase(3);
    printMap(m);

    // m.erase(m.begin(),m.end());
    m.clear();
    printMap(m);
}

int main()
{
    test01();

    return 0;
}