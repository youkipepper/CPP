#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main()
{
    Student stuArray[] =
        {
            {"张三", 18, 100},
            {"李四", 28, 99},
            {"王五", 38, 66}};

    stuArray[2].name = "赵六";
    stuArray[2].age = 80;
    stuArray[2].score = 60;

    for (int i = 0; i < 3; i++)
    {
        cout << "姓名: " << stuArray[i].name << " "
             << " 年龄: " << stuArray[i].age << " 分数 " << stuArray[i].score << endl;
    }

    system("pause");
    return 0;
}