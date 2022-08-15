#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person的无参构造函数调用" << endl;
    }

    Person(int a)
    {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }

    Person(const Person &p)
    {
        age = p.age;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    int age;
};

void test01()
{
    //括号法
    // Person p1;
    // Person p2(10);
    // Person p3(p2);

    // Person p1();

    //注意事项1
    //调用默认构造函数的时候, 不要加()

    // cout << "p2的年龄为: " << p2.age << endl;
    // cout << "p3的年龄为: " << p3.age << endl;

    //显示法
    // Person p1;
    // Person p2 = Person(10);//有参构造
    // Person p3 = Person(p2);//有参拷贝

    // Person(10); //匿名对象 特点: 当前行执行结束后, 系统会立即回收掉
    // cout << "aaaaa" << endl;

    //注意事项2
    //不要利用拷贝构造函数 初始化匿名对象
    // Person(p3);

    //隐式转换法
    Person p4 = 10;
    Person p5 = p4;
}

int main()
{
    test01();

    return 0;
}