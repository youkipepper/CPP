#include <iostream>
using namespace std;
#include <string>

template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "name: " << this->m_Name << endl;
        cout << "age:" << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    // Person p("孙悟空", 1000);
    Person<string, int> p("孙悟空", 1000);
    p.showPerson();
}

void test02()
{
    Person<string> p("猪八戒", 999);
    p.showPerson();
}

int main()
{
    // test01();
    test02();

    return 0;
}