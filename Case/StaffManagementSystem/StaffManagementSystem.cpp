#include <iostream>
using namespace std;
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#include "workerManager.h"

int main()
{
    //测试代码
    // Worker *worker = NULL;
    // worker = new Employee(1, "张三", 1);
    // worker->showInfo();
    // delete worker;

    // worker = new Manager(2, "李四", 2);
    // worker->showInfo();
    // delete worker;

    // worker = new Boss(3, "李四", 3);
    // worker->showInfo();
    // delete worker;

    WorkerManager wm;

    int choice = 0;
    while (true)
    {
        wm.ShowMenu();
        cout << "请输入您的选择：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            wm.exitSystem();
            break;
        case 1:
            wm.Add_Emp();
            break;
        case 2:
            wm.Show_Emp();
            break;
        case 3:
            wm.Del_Emp();
            // test
            // {
            //     int ret = wm.IsExist(5);
            //     if (ret != -1)
            //     {
            //         cout << "职工存在" << endl;
            //     }
            //     else
            //     {
            //         cout << "职工不存在" << endl;
            //     }
            // }
            break;
        case 4:
            wm.Mod_Emp();
            break;
        case 5:
            wm.Find_Emp();
            break;
        case 6:
            wm.Sort_Emp();
            break;
        case 7:
            wm.Clean_File();
            break;
        default:
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}
