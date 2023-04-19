#include<iostream>
#include<stdlib.h>
using namespace std;
#include "workermanager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "workerbase.h"
int main() {
	//实例化管理者对象
	WokerManager wm;
	int choice = 0;
	while (true) {
		//展示菜单
		//调用展示菜单成员函数
		wm.Show_Menu();
		cout << "请选择您的操作：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
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
//界面测试通过
//添加职工测试通过




//int main() {
//	//测试代码
//	WorkerBase* workerbase = NULL;
//	WorkerBase* workerbase1 = NULL;
//	workerbase = new Employee(1, "张三", 0001);
//	workerbase->showInfo();
//	workerbase1 = new Boss(2, "BOSS", 0000);
//	workerbase1->showInfo();
//
//	system("pause");
//	return 0;
//}
//多态测试通过