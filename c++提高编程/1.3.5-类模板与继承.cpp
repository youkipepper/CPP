#include <iostream>
using namespace std;

template <class T>
class Base
{
    T m;
};

class Son : public Base<int>
{
};

template <class T1, class T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout << "T1的类型为: " << typeid(T1).name() << endl;
        cout << "T2的类型为: " << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test01()
{
    Son s1;
}

void test02()
{
    Son2<int, char> s2;
}

int main()
{
    // test01();
    test02();

    return 0;
}