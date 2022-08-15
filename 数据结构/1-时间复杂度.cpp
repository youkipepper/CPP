#include <iostream>
using namespace std;

// 算法1-逐步递增型爱你
void loveYou(int n) // n为问题规模
{
    int i = 0; // 爱你的程度
    while (i < n)
    {
        i++; //每次+1
        printf("I Love You %d\n", i);
    }
    printf("I Love You More Than %d\n", n);
}

//算法2-嵌套循环型爱你
void loveYou2(int n)
{
    int i = 0; //爱你的程度
    while (i < n)
    {
        i++;
        printf("I Love You %d\n", i);
        for (int j = 0; j < n; j++)
        {
            printf("I am Iron Man\n");
        }
    }
    printf("I Love You More Than %d\n", n);
}

//算法3-指数递增型爱你
void loveYou3(int n) // n为问题规模
{
    int i = 1; // 爱你的程度
    while (i < n)
    {
        i = i * 2; //每次翻倍
        printf("I Love You %d\n", i);
    }
    printf("I Love You More Than %d\n", n);
}

int main()
{
    loveYou(3000);
    loveYou2(3000);
    loveYou3(3000);

    return 0;
}