#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct student
{
    string sName;
    int score;
};

struct teacher
{
    string tName;
    student sArray[5];
};

void allocateSpace(teacher tArray[], int len)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSeed[i];
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].sName = "Student_";
            tArray[i].sArray[j].sName += nameSeed[j];
            int random = rand() % 61 + 40;
            tArray[i].sArray[j].score = random;
        }
    }
}

void printInfo(teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << tArray[i].tName << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生姓名:" << tArray[i].sArray[j].sName << " 成绩：" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));
    teacher tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray, len);
    printInfo(tArray, len);
    return 0;
}