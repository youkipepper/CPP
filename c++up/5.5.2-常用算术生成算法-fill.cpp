#include <iostream>
using namespace std;
#include <numeric>
#include <vector>
#include <algorithm>

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v;
    v.resize(10);

    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();

    return 0;
}  