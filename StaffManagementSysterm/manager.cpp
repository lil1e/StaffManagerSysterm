#include "manager.h"
Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
Manager::Manager(int id, string name, int did, int salary) {
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

void Manager::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t薪资：" << this->get_m_Salary()
		<< "\t岗位职责：完成老板交代的各项任务，并下发任务给员工" << endl;
}

string Manager::getDeptName() {
	return string("经理");
}
