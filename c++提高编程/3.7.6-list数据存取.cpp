#include <iostream>
#include <list>
using namespace std;

void test01()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    cout << "第一个元素为: " << l1.front() << endl;
    cout << "最后一个元素为: " << l1.back() << endl;

    list<int>::iterator it = l1.begin();
    // it=it+1;
    it++;
    it--;
}

int main()
{
    test01();

    return 0;
}