#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptID = dId;
};

void Employee::showInfo()
{
    cout << "ְ�����: " << this->m_Id
         << "\tְ������: " << this->m_Name
         << "\t��λ: "<<this->getDeptName()
         << "\t��λְ��: ��ɾ�����������" << endl;
}

string Employee::getDeptName()
{
    return string("Ա��");
}