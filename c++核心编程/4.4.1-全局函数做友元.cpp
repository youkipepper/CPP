#include <iostream>
using namespace std;
#include <string>

class Building
{
    friend void goodGay(Building &building);

public:
    Building()
    {
        m_SittingRoom = "客厅";
        M_BedRoom = "卧室";
    }

public:
    string m_SittingRoom;

private:
    string M_BedRoom;
};

void goodGay(Building &building)
{
    cout << "好基友的全局函数 正在访问: " << building.m_SittingRoom << endl;

    cout << "好基友的全局函数 正在访问: " << building.M_BedRoom << endl;
}

void test01()
{
    Building building;
    goodGay(building);
}

int main()
{
    test01();

    return 0;
}