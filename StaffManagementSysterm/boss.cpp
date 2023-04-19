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
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t薪资：" << this->get_m_Salary()
		<< "\t岗位职责：管理公司所有事务" << endl;
	cout << "当月出勤情况：" << endl;
	for(i=0;i<31;i++)
		if(this)
	

}

string Boss::getDeptName() {
	return string("总裁");
}
