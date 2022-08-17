#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#include <string>

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到大于5的数字为: " << *it << endl;
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
    string m_Name;
    int m_Age;
};

class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age > 20;
    }
};

void test02()
{
    vector<Person> v;
    Person p1("Tom", 20);
    Person p2("Jerry", 18);
    Person p3("Spike", 35);
    Person p4("Tyke", 8);
    Person p5("Tuffy", 6);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到姓名: " << it->m_Name << " 年龄: " << it->m_Age << endl;
    }
}

int main()
{
    // test01();
    test02();

    return 0;
}