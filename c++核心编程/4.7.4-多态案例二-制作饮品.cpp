#include <iostream>
using namespace std;

class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourCup() = 0;
    virtual void PutSomething() = 0;
    void makeDrink()
    {
        Boil();
        Brew();
        PourCup();
        PutSomething();
    }

    virtual ~AbstractDrinking(){}
};

class Coffee : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "煮农夫山泉" << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    virtual void PourCup()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入糖和牛奶" << endl;
    }
};

class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "煮矿泉水" << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }
    virtual void PourCup()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入柠檬" << endl;
    }
};

void doWork(AbstractDrinking *abs)
{
    abs->makeDrink();
    delete abs;
}

void test01()
{
    doWork(new Coffee);

    cout << "---------------------" << endl;

    doWork(new Tea);
}

int main()
{
    test01();

    return 0;
}