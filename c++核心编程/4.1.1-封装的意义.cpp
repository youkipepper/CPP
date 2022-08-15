#include <iostream>
using namespace std;

const double π = 3.14;

class Circle
{
    //访问权限:公共权限
public:
    //属性
    int m_r;

    //行为
    double calculateZC()
    {
        return 2 * π * m_r;
    }
};

int main()
{
    //通过圆类 创建具体的圆(对象)
    //实例化 (通过一个累 创建一个对象的过程)
    Circle c1;
    //给圆对象 的属性进行赋值
    c1.m_r = 10;

    cout << "圆的周长为: " << c1.calculateZC() << endl;

    return 0;
}