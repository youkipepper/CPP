#include <iostream>
using namespace std;

void func(int &ref)
{
    ref = 100;
}

int main()
{
    int a = 10;

    int &ref = a;
    ref = 20;

    cout << "a: " << endl;
    cout << "ref: " << endl;

    return 0;
}