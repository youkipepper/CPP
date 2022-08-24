#include <iostream>
#include <algorithm>
using namespace std;

void bubblesort1A(int A[], int n) //冒泡排序算法(版本1A)
{
    bool sorted = false; //整体排序标志, 假定尚未排序
    while (!sorted)
    {
        sorted = true; //假定已经排序
        for (int i = 1; i < n; i++)
        {
            if (A[i - 1])
            {
                swap(A[i - 1], A[i]);
                sorted = false;
            }
        }
        n--;
    }
}

int main()
{
    int ArrayTest[]={9,3,5,1,3};
    bubblesort1A(ArrayTest,3);
    return 0;
}