#include <iostream>
#include <set>
#include <string>
using namespace std;

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

class MyCompare
{
public:
    bool operator()(const Person &s1, const Person &s2)const
    {
        return s1.m_Age > s2.m_Age;
    }
};

void test01()
{
    //自定义数据类型 都会指定排序规则
    set<Person, MyCompare> s;
    Person p1("Tom", 2);
    Person p2("Jerry", 18);
    Person p3("Spike", 35);
    Person p4("Tyke", 8);
    Person p5("Tuffy", 6);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);

    for (set<Person, MyCompare>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "name: " << (*it).m_Name << " age: " << it->m_Age << endl;
    }
}

int main()
{
    test01();

    return 0;
}