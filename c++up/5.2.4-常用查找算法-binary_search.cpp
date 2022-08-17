#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    bool ret = binary_search(v.begin(), v.end(), 9);
    if (ret)
    {
        cout << "找到了元素" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

int main()
{
    test01();

    return 0;
}