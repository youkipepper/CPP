#include <iostream>
using namespace std;

void BubbleSort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void PrintArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main(void)
{
    int arr[] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, len);
    PrintArray(arr, len);

    system("pause");
    return 0;
}