#include <iostream>
using namespace std;

int main()
{
    //选择结构—多行if结构
    //输入考试分数,如果分数大于600, 视为考上一本大学,在屏幕上输出,
    //如果没考上一本大学, 打印未考上一本大学

    // 1、输入考试分数
    int score = 0;
    cout << "请输入一个考试分数:" << endl;
    cin >> score;

    // 2、提示用户输入的分数
    cout << "您输入的分数:" << score << endl;

    // 3、判断 如果是大于600, 打印考上一本
    if (score > 600) // 大于600分执行下面大括号中的内容
    {
        cout << "介个比考上一本大学🎉" << endl;
    }
    else // 不大于600分,执行else后打括号中的内容
    {
        cout << "没考上,搬砖去吧🧱" << endl;
    }

    system("pause");

    return 0;
}
