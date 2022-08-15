#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }

    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "你这个老妖精" << endl;
            return;
        }
        m_Age = age;
    }

    int getAge()
    {
        m_Age = 0;
        return m_Age;
    }

    void setLOver(string lover)
    {
        m_Lover = lover;
    }

private:
    string m_Name;
    int m_Age;
    string m_Lover;
};

int main()
{
    Person p;
    p.setName("张三");

    cout << "姓名为: " << p.getName() << endl;

    p.setAge(1000);
    cout << "年龄为: " << p.getAge() << endl;

    p.setLOver("苍井");
    // cout << "情人为: " << p.m_Lover << endl;

    return 0;
}