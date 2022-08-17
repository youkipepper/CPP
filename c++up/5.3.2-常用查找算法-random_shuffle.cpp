#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#include <ctime>

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    srand((unsigned int)time(NULL));

    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), myPrint);
}

int main()
{
    test01();

    return 0;
}