#include <iostream>
using namespace std;

//目前阶段的占位参数还用不到, 后面课程会用到
//占位参数 还可以有默认值
void func(int a, int = 10)
{
    cout << "this is func" << endl;
}

int main(void)
{
    func(10, 10);

    return 0;
}