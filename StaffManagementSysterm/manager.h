#pragma once

#include <iostream>
using namespace std;
#include "workerbase.h"

//������
class Manager :public WorkerBase
{
public:
	Manager(int id, string name, int did);
	Manager(int id, string name, int did, int salary);

	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
