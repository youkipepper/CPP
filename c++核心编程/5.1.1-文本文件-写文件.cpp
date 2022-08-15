#include <iostream>
using namespace std;
#include <fstream> //头文件包含

//文本文件 写文件

void test01()
{
    ofstream ofs; //创建流文件

    ofs.open("./test.text", ios::out); //指定打开方式
    ofs << "姓名: 张三" << endl;
    ofs << "性别: 男" << endl;
    ofs << "年龄: 18" << endl;

    ofs.close();
}

int main()
{
    test01();

    return 0;
}