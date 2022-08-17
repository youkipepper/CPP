#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

//常用查找算法
// find

//查找 内置数据类型
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //查找 容器中 是否有 5 这个元素
    vector<int>::iterator it = find(v.begin(), v.end(), 50);
    if (it == v.end())
    {
        cout << "没有找到!" << endl;
    }
    else
    {
        cout << "找到: " << *it << endl;
    }
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    //重载 == 底层find知道如何对比Person数据类型
    bool operator==(const Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

//查找 自定义数据类型
void test02()
{
    vector<Person> v;
    Person p1("Tom", 2);
    Person p2("Jerry", 18);
    Person p3("Spike", 35);
    Person p4("Tyke", 8);
    Person p5("Tuffy", 6);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person pp("Jerry", 18);

    vector<Person>::iterator it = find(v.begin(), v.end(), pp);
    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到元素 姓名" << it->m_Name << " 年龄: " << it->m_Age << endl;
    }
}

int main()
{
    // test01();
    test02();

    return 0;
}