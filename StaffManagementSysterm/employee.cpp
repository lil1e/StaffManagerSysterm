#include "employee.h"

Employee::Employee(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

Employee::Employee(int id, string name, int did, int salary) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
	this->m_Salary = salary;
	int j;
	this->m_Performance = 0;
	for (j = 0; j < 31; j++)
	{
		this->m_Check_Attendance[j] = -2;
	}
}

void Employee::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\tн�ʣ�" << this->get_m_Salary()
		<< "\t��λְ����ɾ��������ĸ�������" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}
