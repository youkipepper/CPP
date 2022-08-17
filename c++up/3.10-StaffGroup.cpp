/*
 * @Author: youki.cui
 * @Date: 2022-08-17 10:43:21
 * @LastEditors: youki.cui
 * @LastEditTime: 2022-08-17 12:01:26
 *
 */
/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 *
 *
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *            佛祖保佑     永不宕机     永无BUG
 *
 *        佛曰:
 *                写字楼里写字间，写字间里程序员；
 *                程序人员写程序，又拿程序换酒钱。
 *                酒醒只在网上坐，酒醉还来网下眠；
 *                酒醉酒醒日复日，网上网下年复年。
 *                但愿老死电脑间，不愿鞠躬老板前；
 *                奔驰宝马贵者趣，公交自行程序员。
 *                别人笑我忒疯癫，我笑自己命太贱；
 *                不见满街漂亮妹，哪个归得程序员？
 */

/*
 * @Author: youki.cui
 * @Date: 2022-08-17 10:20:29
 * @LastEditors: youki.cui
 * @LastEditTime: 2022-08-17 10:21:07
 *
 */
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
#include <ctime>

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];
        worker.m_Salary = rand() % 10000 + 10000;
        v.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生随机部门编号
        int deptId = rand() % 3;

        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m)
{
    cout << "策划部门: " << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA); //统计具体人数
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
    }

    cout << "-------------------------------" << endl;

    cout << "美术部门: " << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU); //统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
    }

    cout << "-------------------------------" << endl;

    cout << "研发部门: " << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA); //统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    vector<Worker> vWorker;
    createWorker(vWorker);

    // test
    // for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    // {
    //     cout << "姓名: " << it->m_Name << " 工资: " << it->m_Salary << endl;
    // }

    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    showWorkerByGroup(mWorker);

    system("pause");
    return 0;
}