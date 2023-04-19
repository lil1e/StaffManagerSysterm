#include "workermanager.h"

WokerManager::WokerManager() {
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		//初始化属性
		//初始化记录数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化我呢间是否为空
		this->m_FilesIsEmpty = true;
		ifs.close();
		return;

	}
	// 2.文件存在，但是数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件为空
		cout << "文件为空！" << endl;
		//初始化属性
		//初始化记录数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FilesIsEmpty = true;
		ifs.close();
		return;
	}


}

WokerManager::~WokerManager() {

}

void WokerManager::Show_Menu() {
	cout << "**********************************************" << endl;
	cout << "***********  欢迎使用职工管理系统  ***********" << endl;
	cout << "**************  0.退出管理程序  **************" << endl;
	cout << "**************  1.增加职工信息  **************" << endl;
	cout << "**************  2.显示职工信息  **************" << endl;
	cout << "**************  3.删除离职员工  **************" << endl;
	cout << "**************  4.修改职工信息  **************" << endl;
	cout << "**************  5.查找职工信息  **************" << endl;
	cout << "**************  6.按照编号排序  **************" << endl;
	cout << "**************  7.清空所有文档  **************" << endl;
	cout << "**********************************************" << endl;
}

void WokerManager::exitSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//添加职工----（待修改）---（已修改）
void WokerManager::Add_Emp() {
	cout << "请输入添加职工数量:" << endl;
	int addNum = 0;//保存用户输入数量
	cin >> addNum;

	if (addNum > 0) {
		//添加
		int newSize = this->m_EmpNum + addNum; //新空间大小 = 原来记录人数 + 新增的人数

		//开辟新空间
		WorkerBase** newSpace = new WorkerBase * [newSize];
		//将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			int salary;//职工薪资

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个新职工薪资：" << endl;
			cin >> salary;

			cout << "请选择职工岗位：" << endl;
			cout << "1、普通员工：" << endl;
			cout << "2、经理：" << endl;
			cout << "3、老板：" << endl;
			cin >> dSelect;

			WorkerBase* workerbase = NULL;
			switch (dSelect)
			{
			case 1:
				workerbase = new Employee(id, name, 1,salary);
				break;
			case 2:
				workerbase = new Manager(id, name, 2,salary);
				break;
			case 3:
				workerbase = new Boss(id, name, 3,salary);
				break;
			default:
				break;
			}

			//将创建的职工信息保存到数组中
			newSpace[this->m_EmpNum + i] = workerbase;

		}

		//释放原有的空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//成功添加后保存到文件中
		this->save();

		//提示成功
		cout << "成功添加" << addNum << "名新员工！" << endl;

	}
	else {
		cout << "输入数据有误！" << endl;
	}

	//按任意键后清屏，回到上级目录
	system("pause");
	system("cls");
}

//保存文件功能实现
void WokerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写的方式打开文件

	//for循环中把我们记录的数据进行写入
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->get_m_Id() << " "
			<< this->m_EmpArray[i]->get_m_Name() << " "
			<< this->m_EmpArray[i]->get_m_DeptId() << endl;
	}

	//关闭文件
	ofs.close();
}

//统计文件中的人数
int WokerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		//统计人数
		num++;
	}
	return num;

}

//初始化职工
void WokerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		WorkerBase* workerbase = NULL;
		if (dId == 1) {//普通职工
			workerbase = new Employee(id, name, dId);
		}
		else if (dId == 2) {//经理
			workerbase = new Manager(id, name, dId);
		}
		else {//老板
			workerbase = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = workerbase;
		index++;

	}
	cout << "共从文件中初始化[" << index << "]条数据" << endl;

	//关闭文件
	ifs.close();


}

//显示职工信息----（待修改）----（已修改）
void WokerManager::Show_Emp() {
	//判断文件是否为空或者不存在
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//利用多态调用显示的接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	//按任意键后清屏
    system("pause");
	system("cls");
}

// 判断职工是否存在,存在则返回职工在数组中的位置，不存在返回-1
int WokerManager::IsExit(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->get_m_Id() == id) {
			index = i;
			break;
		}
	}
	return index;
}
//删除职工
void WokerManager::Del_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		//按照职工编号进行删除
		cout << "请输入需要删除的职工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExit(id);
		if (index != -1) {//说明职工存在，需要删除index位置上的职工
			//数据迁移
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数据中记录的人员个数
			this->m_EmpNum--;
			//同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败，未找到该职工！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//修改职工----（待修改）----(已修改)
void WokerManager::Mod_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请输入需要【修改】的职工编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1) {
			//查找到职工
			delete this->m_EmpArray[ret];
			int newId = 0;
			int newSalary;
			string newName = "";
			int dSelect = 0;
			cout << "查找到职工编号为[" << id << "]的职工，请输入新职工号:" << endl;
			cin >> newId;
			cout << "请输入新姓名:" << endl;
			cin >> newName;
			cout << "请输入新薪资:" << endl;
			cin >> newSalary;
			cout << "请输入新岗位:" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			WorkerBase* wokerbase = NULL;
			switch (dSelect)
			{
			case 1:
				wokerbase = new Employee(newId, newName, 1, newSalary);
				break;
			case 2:
				wokerbase = new Manager(newId, newName, 2, newSalary);
				break;
			case 3:
				wokerbase = new Boss(newId, newName, 3, newSalary);
				break;
			}
			//数据更新到数组中
			this->m_EmpArray[ret] = wokerbase;
			cout << "职工信息修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//查找职工
void WokerManager::Find_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请输入查找职工的方式:" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//按照编号查找
			int id;
			cout << "请输入查找的职工的编号" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1) {
				//找到该职工
				cout << "查找成功！该职工的信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2) {
			//按照姓名查找
			string name;
			cout << "请输入查找职工姓名:" << endl;
			cin >> name;
			//加入是否查到的标志
			bool select_flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->get_m_Name() == name) {
					cout << "查找成功！职工编号为["
						<< this->m_EmpArray[i]->get_m_Name()
						<< "]的职工信息如下：" << endl;

					select_flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (select_flag == false) {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else {
			cout << "输入选项有误！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//职工排序
void WokerManager::Sort_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请选择排序方式:" << endl;
		cout << "1、按照职工号进行升序排序" << endl;
		cout << "2、按照职工号进行降序排序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) {
			int minOrMax = i;//申明最小值或者最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {//升序
					if (this->m_EmpArray[minOrMax]->get_m_Id() > this->m_EmpArray[j]->get_m_Id()) {
						minOrMax = j;
					}

				}
				else {//降序
					if (this->m_EmpArray[minOrMax]->get_m_Id() < this->m_EmpArray[j]->get_m_Id()) {
						minOrMax = j;
					}
				}
			}

			//判断一开始认定的最小值或者最大值 是不是计算的最小值或者最大值，如果不是则就交换数据
			if (i != minOrMax) {
				WorkerBase* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}
	}
	cout << "排序成功，排序后结果为:" << endl;
	this->save();//排序后的结果保存到文件中
	this->Show_Emp();
}

// 清空文件
void WokerManager::Clean_File() {
	cout << "确定清空文件？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int selcet = 0;
	cin >> selcet;
	if (selcet == 1) {
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		if (this->m_EmpArray != NULL) {
			//删除堆区的每个职工对象
			for (int i = 0; i < m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;

			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FilesIsEmpty = true;
		}

		cout << "清空成功！" << endl;
	}

	//按任意键清屏
	system("pause");
	system("cls");

}

