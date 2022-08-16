/*
 * @Author: youki.cui
 * @Date: 2022-08-16 22:07:59
 * @LastEditors: youki.cui
 * @LastEditTime: 2022-08-16 22:11:56
 * @Description: Once again to change everything.
 *
 */
#include <iostream>
using namespace std;

void test01()
{
    pair<string, int> p("Tom", 20);
    cout << "name: " << p.first << " age: " << p.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 18);
    cout << "name: " << p2.first << " age: " << p2.second << endl;
}

int main()
{
    test01();

    return 0;
}