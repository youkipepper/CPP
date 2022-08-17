#include <iostream>
using namespace std;
#include <vector>
// vector 容器预留空间

void test01()
{
    vector<int> v;

    //利用reserve预留空间
    v.reserve(10000);

    int num = 0;
    int *p = 0;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(i);

        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "num = " << num << endl;
}

int main()
{
    test01();

    return 0;
}