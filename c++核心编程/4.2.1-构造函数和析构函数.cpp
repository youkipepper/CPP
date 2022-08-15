#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person 构造函数的调用" << endl;
    }

    ~Person()
    {
        cout << "Person 的析构函数调用" << endl;
    }
};

//构造和析构都是必须有的实现, 如果我们自己不提供, 编译器就会提供一个空实现
void test01()
{
    Person p; //在栈上的数据, test01执行完毕后,释放这个对象
}

int main()
{
    // test01();
    
    Person p;

    return 0;
}




