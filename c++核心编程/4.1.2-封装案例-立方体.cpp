#include <iostream>
using namespace std;

class Cube
{
public:
    void setL(int l)
    {
        m_L = l;
    }

    int getL()
    {
        return m_L;
    }

    void setW(int w)
    {
        m_W = w;
    }

    int getW()
    {
        return m_W;
    }

    void setH(int h)
    {
        m_H = h;
    }

    int getH()
    {
        return m_H;
    }

    int calculateS()
    {
        return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
    }

    int calculateV()
    {
        return m_L * m_W * m_H;
    }

    bool isSameByClass(Cube &c)
    {
        if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
        {
            return true;
        }
        return false;
    }

private:
    int m_L;
    int m_W;
    int m_H;
};

bool isSame(Cube c1, Cube c2)
{
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
    {
        return true;
    }
    return false;
}

int main()
{
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);

    cout << "c1的面积为: " << c1.calculateS() << endl;
    cout << "c1的体积为: " << c1.calculateV() << endl;

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);

    bool ret = isSame(c1, c2);
    if (ret)
    {
        cout << "c1和c2是相等的" << endl;
    }
    else
    {
        cout << "c1和c2是不相等的" << endl;
    }

    ret = c1.isSameByClass(c2);
    if (ret)
    {
        cout << "成员函数c1和c2是相等的" << endl;
    }
    else
    {
        cout << "成员函数c1和c2是不相等的" << endl;
    }

    return 0;
}