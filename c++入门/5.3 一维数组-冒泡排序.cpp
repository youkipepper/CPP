#include <iostream>
using namespace std;
int main(void)
{
    int arr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9, 10, 12, 11};
    cout << "排序前:"
         << " ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "排序后:"
         << " ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}