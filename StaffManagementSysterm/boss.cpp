#include "boss.h"
Boss::Boss(int id, string name, int did ) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

Boss::Boss(int id, string name, int did, int salary) {
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

void Boss::showInfo() {
	int i,j;
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\tн�ʣ�" << this->get_m_Salary()
		<< "\t��λְ�𣺹���˾��������" << endl;
	cout << "���³��������" << endl;
	for(i=0;i<31;i++)
		if(this)
	

}

string Boss::getDeptName() {
	return string("�ܲ�");
}
