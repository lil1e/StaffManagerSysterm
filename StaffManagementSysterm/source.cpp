#include<iostream>
#include<stdlib.h>
using namespace std;
#include "workermanager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "workerbase.h"
int main() {
	//ʵ���������߶���
	WokerManager wm;
	int choice = 0;
	while (true) {
		//չʾ�˵�
		//����չʾ�˵���Ա����
		wm.Show_Menu();
		cout << "��ѡ�����Ĳ�����" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
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
//�������ͨ��
//���ְ������ͨ��




//int main() {
//	//���Դ���
//	WorkerBase* workerbase = NULL;
//	WorkerBase* workerbase1 = NULL;
//	workerbase = new Employee(1, "����", 0001);
//	workerbase->showInfo();
//	workerbase1 = new Boss(2, "BOSS", 0000);
//	workerbase1->showInfo();
//
//	system("pause");
//	return 0;
//}
//��̬����ͨ��