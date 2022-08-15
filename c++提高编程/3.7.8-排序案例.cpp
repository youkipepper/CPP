#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
#include <string>

// list容器 排序案例 对于自定义数据类型 做排序

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};

//指定排序规则
bool comparePerson(Person &p1, Person &p2)
{
    if (p1.m_Age == p2.m_Age)
    {
        return p1.m_Height > p2.m_Height;
    }
    return p1.m_Age < p2.m_Age;
}

void test01()
{
    list<Person> l;
    Person p1("Tom", 20, 120);
    Person p2("Jerry", 18, 40);
    Person p3("Spike", 35, 140);
    Person p4("Tyke", 8, 70);
    Person p5("Tuffy", 6, 30);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);

    cout << "-------------------------------------" << endl;
    cout << "排序后: " << endl;

    l.sort(comparePerson);
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "name: " << (*it).m_Name << " age: " << it->m_Age << " heght: " << it->m_Height << endl;
    }
}

int main()
{
    test01();

    return 0;
}