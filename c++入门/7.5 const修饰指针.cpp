#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 10;

    const int *p = &a;
    // *p = 20;
    p = &b;

    int *const p2 = &a;
    *p2 = 100;
    // p2 = &b;

    return 0;
}