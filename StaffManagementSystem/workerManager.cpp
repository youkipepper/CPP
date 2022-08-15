#include "workerManager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"

WorkerManager::WorkerManager()
{
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;

    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        this->m_EmpNum = 0;
        this->m_FilesEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ�գ�" << endl;
        this->m_EmpNum = 0;
        this->m_FilesEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    this->m_FilesEmpty = false;

    int num = this->get_EmpNum();
    // cout << "ְ��������Ϊ��" << num << endl;
    this->m_EmpNum = num;

    this->m_EmpArray = new Worker *[this->m_EmpNum];
    this->init_Emp();

    // ���Դ���
    // for (int i = 0; i < this->m_EmpNum; i++)
    // {
    //     cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
    //          << "������" << this->m_EmpArray[i]->m_Name
    //          << "���ű�ţ�" << this->m_EmpArray[i]->m_DeptID << endl;
    // }
}

void WorkerManager::ShowMenu()
{
    cout << "*******************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� *********" << endl;
    cout << "*************  0.�˳���������  ************" << endl;
    cout << "*************  1.����ְ����Ϣ  ************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  ************" << endl;
    cout << "*************  3.ɾ����ְְ��  ************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  ************" << endl;
    cout << "*************  5.����ְ����Ϣ  ************" << endl;
    cout << "*************  6.���ձ������  ************" << endl;
    cout << "*************  7.��������ĵ�  ************" << endl;
    cout << "*******************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::Add_Emp()
{
    cout << "����������ְ�������� " << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        int newSize = this->m_EmpNum + addNum;
        Worker **newSpace = new Worker *[newSize];

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
            cin >> id;
            cout << "�������" << i + 1 << "����ְ��������" << endl;
            cin >> name;
            cout << "�������ְ����λ��" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;

            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }

            newSpace[this->m_EmpNum + 1] = worker;
        }

        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->m_FilesEmpty = false;

        cout << "�ɹ�����" << addNum << "����ְ��" << endl;

        this->save();
    }
    else
    {
        cout << "������������" << endl;
    }

    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptID << endl;
    }

    ofs.close();
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    ifs.close();

    return num;
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;

        if (dId == 1)
        {
            worker = new Manager(id, name, dId);
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
}

void WorkerManager::Show_Emp()
{
    if (this->m_FilesEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
            index = i;
        break;
    }

    return index;
}

void WorkerManager::Del_Emp()
{
    if (this->m_FilesEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "��������Ҫɾ����ְ����ţ�" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();

            cout << "ɾ���ɹ���" << endl;
        }
        else
        {
            cout << "ɾ��ʧ��,δ�ҵ���ְ��" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp()
{
    if (this->m_FilesEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "�������޸�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
            cin >> newId;

            cout << "��������������" << endl;
            cin >> newName;

            cout << "�������λ��" << endl;
            cout << "1����ְͨԱ" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }

            this->m_EmpArray[ret] = worker;
            cout << "�޸ĳɹ���" << this->m_EmpArray[ret]->m_DeptID << endl;

            this->save();
        }
        else
        {
            cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp()
{
    if (this->m_FilesEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else
    {
        cout << "��������ҵķ�ʽ��" << endl;
        cout << "1������ְ����Ų���" << endl;
        cout << "2������������" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            int id;
            cout << "��������ҵ�ְ����ţ�" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "���ҳɹ�����ְԱ��Ϣ���£�" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "��������ҵ�������" << endl;
            cin >> name;

            bool flag = false;
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (m_EmpArray[i]->m_Name == name)
                {
                    cout << "���ҳɹ���ְԱ���Ϊ��"
                         << m_EmpArray[i]->m_Id
                         << " �ŵ���Ϣ���£�" << endl;

                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else
        {
            cout << "����ѡ������" << endl;
        }
    }

    system("pause");
    system("cls");
}

void WorkerManager::Sort_Emp()
{
    if (this->m_FilesEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ��" << endl;
        cout << "1����ְ���Ž�������" << endl;
        cout << "2����ְ���Ž��н���" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1)
                {
                    if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else
                {
                    if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax)
            {
                Worker *temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }
        cout << "����ɹ����������Ϊ��" << endl;
        this->save();
        this->Show_Emp();
    }
}

void WorkerManager::Clean_File()
{
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FilesEmpty = true;
        }
        cout << "��ճɹ�" << endl;
    }
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray = NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}