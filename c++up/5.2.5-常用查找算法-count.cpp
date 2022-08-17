#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);

    int num = count(v.begin(), v.end(), 40);
    cout << "40的元素个数为: " << num << endl;
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name;
        this->m_Age;
    }
    string m_Name;
    int m_Age;

    bool operator==(const Person&p)
    {
        if(this->m_Age==p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
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

    Person p("Butch", 20);

    int num = count(v.begin(), v.end(), p);
    cout << "与 Butch 同岁数人员个数为: " << num << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}