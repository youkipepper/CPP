#include <iostream>
#include <string>
using namespace std;

struct hero
{
    string name;
    int age;
    string gender;
};

void Bubble(hero heroArray[],int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            hero temp = heroArray[j];
            if (heroArray[j].age > heroArray[j + 1].age)
            {
                heroArray[j] = heroArray[j + 1];
                heroArray[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    hero heroArray[] =
        {
            {"刘备", 23, "男"},
            {"关羽", 22, "男"},
            {"张飞", 20, "男"},
            {"赵云", 21, "男"},
            {"貂蝉", 19, "女"}};
    int len = sizeof(heroArray) / sizeof(heroArray[0]);

    Bubble(heroArray, len);

    for (int i = 0; i < len; i++)
    {
        cout << "姓名： " << heroArray[i].name << " 年龄： " << heroArray[i].age << " 性别： " << heroArray[i].gender << endl;
    }
    return 0;
}