#include <iostream>
using namespace std;

class CPU
{
public:
    virtual void caculate() = 0;
    virtual ~CPU() {}
};

class VideoCard
{
public:
    virtual void display() = 0;
    virtual ~VideoCard() {}
};

class Memory
{
public:
    virtual void storage() = 0;
    virtual ~Memory() {}
};

class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    void work()
    {
        m_cpu->caculate();
        m_vc->display();
        m_mem->storage();
    }

    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }

        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }

        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

class IntelCPU : public CPU
{
public:
    virtual void caculate()
    {
        cout << "Intel的CPU开始计算了!" << endl;
    }
};

class IntelVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Intel的显卡开始显示了!" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Intel的内存条开始存储了!" << endl;
    }
};

class LenovoCPU : public CPU
{
public:
    virtual void caculate()
    {
        cout << "Lenovo的CPU开始计算了!" << endl;
    }
};

class LenovoVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Lenovo的显卡开始显示了!" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Lenovo的内存条开始存储了!" << endl;
    }
};

void test01()
{
    CPU *intelcpu = new IntelCPU;
    VideoCard *intelvideocard = new IntelVideoCard;
    Memory *intelmem = new IntelMemory;

    cout << "第一台电脑开始工作" << endl;
    Computer *computer1 = new Computer(intelcpu, intelvideocard, intelmem);
    computer1->work();
    delete computer1;

    cout << "--------------------" << endl;
    cout << "第二台电脑开始工作" << endl;
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    computer2->work();
    delete computer2;

    cout << "--------------------" << endl;
    cout << "第三台电脑开始工作" << endl;
    Computer *computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
    computer3->work();
    delete computer3;
}

int main()
{
    test01();

    return 0;
}