#include <iostream>
using namespace std;

//访问权限
//三种
//公共权限 public      成员 类内可以访问 类外可以访问
//保护权限 protected   成员 类内可以访问 类外不可以访问
//私有权限 private     成员 类内可以访问 类外不可以访问

class Person
{
public:
    string m_Name;

protected:
    string m_Car;

private:
    int m_Password;

private:
    void func()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};

int main()
{
    Person p1;

    p1.m_Name = "李四";
    // p1.m_Car = "奔驰";
    // p1.m_Password = 123456;

    // p1.func();

    return 0;
}