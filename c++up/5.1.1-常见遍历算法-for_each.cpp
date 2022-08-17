#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//常用遍历算法 for_each

//普通函数
void print01(int val)
{
    cout << val << " ";
}

//仿函数
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print01);
    cout << endl;

    for_each(v.begin(), v.end(), print02());
}

int main()
{
    test01();

    return 0;
}