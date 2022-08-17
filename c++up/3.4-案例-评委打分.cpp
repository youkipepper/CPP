#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }

    string m_Name;
    int m_Score;
};

void creatPerson(vector<Person> &v)
{
    for (int i = 0; i < 5; i++)
    {
        string nameSeed = "ABCDE";
        string name = "选手";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 将评委的分数 放入到deque容器中
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        // test
        // cout << "选手: " << it->m_Name << " 得分: " << endl;
        // for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        // {
        //     cout << *dit << " ";
        // }
        // cout << endl;

        //  排序
        sort(d.begin(), d.end());

        //去除最高和最低分
        d.pop_back();
        d.pop_front();

        //取平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit; //累加每个评委的分数
        }

        int avg = sum / d.size();

        //将平均分 赋值给选手身上
        it->m_Score = avg;
    }
}

void showScore(vector<Person> &p)
{
    for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
    {
        cout << "name: " << it->m_Name << "averageScore: " << it->m_Score << endl;
    }
}

int main()
{
    //随机数种子
    srand((unsigned int)time(NULL));

    // 1、创建5名选手
    vector<Person> v; //存放选手的容器
    creatPerson(v);

    // test
    // for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << "name: " << (*it).m_Name << " score: " << (*it).m_Score << endl;
    // }

    // 2、给5名选手打分
    setScore(v);

    // 3、显示最后的得分
    showScore(v);

    return 0;
}