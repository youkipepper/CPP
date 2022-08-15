#include <iostream>
using namespace std;
#include <string>

//普通写法
class Caculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        //如果想拓展新功能, 需要修改原码
        //在真实开发中 提倡 开闭原则
        //开闭原则: 对拓展进行开发, 对修改进行关闭
    }

    int m_Num1;
    int m_Num2;
};

void test01()
{
    Caculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
}

//利用多态实现计算器
//多态好处:
//1、组织结构清晰
//2、可读性强
//3、对于前期和后期

//实现计算器抽象类

//实现计算器抽象类
class AbstractCaculator
{
public:
    virtual int getResult()
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

//加法计算器类
class AddCaculator : public AbstractCaculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

//减法计算器类
class SubCaculator : public AbstractCaculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

//乘法计算器类
class MulCaculator : public AbstractCaculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test02()
{
    //多态使用条件
    //父类指针或者引用指向子类对象

    //加法运算
    AbstractCaculator *abc = new AddCaculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    //用完后记得销毁
    delete abc;

    abc = new SubCaculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    abc = new MulCaculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;
}

int main()
{
    // test01();
    test02();

    return 0;
}