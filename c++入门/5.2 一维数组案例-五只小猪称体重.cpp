#include <iostream>
using namespace std;
int main()
{
    // 1、创建5只小猪体重数组
    int arr[5] = {300, 350, 500, 400, 250};
    // 2、从数组中找到最大的值
    int max = 0; // 先认定一个为最大值为0
    for (int i = 0; i < 5; i++)
    {
        // cout << arr[i] << endl;
        //  如果访问的数组中的元素比认定的最大值还要大, 更新最大值
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    // 3、打印最大值
    cout << "最重的小猪体重为: " << max << endl;

    system("pause");
    return 0;
}