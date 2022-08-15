#include <iostream>
using namespace std;
#include <string>

class Building;

class GoodGay
{
public:
    GoodGay();
    void visit();
    void visit2();

    Building *building;
};

class Building
{
    friend void GoodGay::visit();

public:
    Building();

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

//类外实现成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "visit 函数正在访问: " << building->m_SittingRoom << endl;
    cout << "visit 函数正在访问: " << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
    cout << "visit2 函数正在访问: " << building->m_SittingRoom << endl;
    // cout << "visit 函数正在访问: " << building->m_BedRoom << endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main()
{
    test01();

    return 0;
}