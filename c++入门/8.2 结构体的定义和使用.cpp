#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
} s3;

int main(void)
{
    // struct在C++中可以省略
    struct Student s1;
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;

    cout << " 姓名: " << s1.name << " 年龄: " << s1.age << " 分数: " << s1.score << endl;

    struct Student s2 = {"李四", 19, 80};
    cout << " 姓名: " << s2.name << " 年龄: " << s2.age << " 分数: " << s2.score << endl;

    s3.name = "王五";
    s3.age = 20;
    s3.score = 60;
    cout << " 姓名: " << s3.name << " 年龄: " << s3.age << " 分数: " << s3.score << endl;

    system("pause");
    return 0;
}