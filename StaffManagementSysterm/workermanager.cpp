#include "workermanager.h"

WokerManager::WokerManager() {
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		//��ʼ������
		//��ʼ����¼��
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ�����ؼ��Ƿ�Ϊ��
		this->m_FilesIsEmpty = true;
		ifs.close();
		return;

	}
	// 2.�ļ����ڣ���������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ������
		//��ʼ����¼��
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FilesIsEmpty = true;
		ifs.close();
		return;
	}


}

WokerManager::~WokerManager() {

}

void WokerManager::Show_Menu() {
	cout << "**********************************************" << endl;
	cout << "***********  ��ӭʹ��ְ������ϵͳ  ***********" << endl;
	cout << "**************  0.�˳��������  **************" << endl;
	cout << "**************  1.����ְ����Ϣ  **************" << endl;
	cout << "**************  2.��ʾְ����Ϣ  **************" << endl;
	cout << "**************  3.ɾ����ְԱ��  **************" << endl;
	cout << "**************  4.�޸�ְ����Ϣ  **************" << endl;
	cout << "**************  5.����ְ����Ϣ  **************" << endl;
	cout << "**************  6.���ձ������  **************" << endl;
	cout << "**************  7.��������ĵ�  **************" << endl;
	cout << "**********************************************" << endl;
}

void WokerManager::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//���ְ��----�����޸ģ�---�����޸ģ�
void WokerManager::Add_Emp() {
	cout << "���������ְ������:" << endl;
	int addNum = 0;//�����û���������
	cin >> addNum;

	if (addNum > 0) {
		//���
		int newSize = this->m_EmpNum + addNum; //�¿ռ��С = ԭ����¼���� + ����������

		//�����¿ռ�
		WorkerBase** newSpace = new WorkerBase * [newSize];
		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			int salary;//ְ��н��

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "�������" << i + 1 << "����ְ��н�ʣ�" << endl;
			cin >> salary;

			cout << "��ѡ��ְ����λ��" << endl;
			cout << "1����ͨԱ����" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ壺" << endl;
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

			//��������ְ����Ϣ���浽������
			newSpace[this->m_EmpNum + i] = workerbase;

		}

		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//�ɹ���Ӻ󱣴浽�ļ���
		this->save();

		//��ʾ�ɹ�
		cout << "�ɹ����" << addNum << "����Ա����" << endl;

	}
	else {
		cout << "������������" << endl;
	}

	//����������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�����ʵ��
void WokerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ķ�ʽ���ļ�

	//forѭ���а����Ǽ�¼�����ݽ���д��
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->get_m_Id() << " "
			<< this->m_EmpArray[i]->get_m_Name() << " "
			<< this->m_EmpArray[i]->get_m_DeptId() << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ��е�����
int WokerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		//ͳ������
		num++;
	}
	return num;

}

//��ʼ��ְ��
void WokerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		WorkerBase* workerbase = NULL;
		if (dId == 1) {//��ְͨ��
			workerbase = new Employee(id, name, dId);
		}
		else if (dId == 2) {//����
			workerbase = new Manager(id, name, dId);
		}
		else {//�ϰ�
			workerbase = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = workerbase;
		index++;

	}
	cout << "�����ļ��г�ʼ��[" << index << "]������" << endl;

	//�ر��ļ�
	ifs.close();


}

//��ʾְ����Ϣ----�����޸ģ�----�����޸ģ�
void WokerManager::Show_Emp() {
	//�ж��ļ��Ƿ�Ϊ�ջ��߲�����
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//���ö�̬������ʾ�Ľӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	//�������������
    system("pause");
	system("cls");
}

// �ж�ְ���Ƿ����,�����򷵻�ְ���������е�λ�ã������ڷ���-1
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
//ɾ��ְ��
void WokerManager::Del_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		//����ְ����Ž���ɾ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExit(id);
		if (index != -1) {//˵��ְ�����ڣ���Ҫɾ��indexλ���ϵ�ְ��
			//����Ǩ��
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���������м�¼����Ա����
			this->m_EmpNum--;
			//ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//�޸�ְ��----�����޸ģ�----(���޸�)
void WokerManager::Mod_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������Ҫ���޸ġ���ְ�����" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1) {
			//���ҵ�ְ��
			delete this->m_EmpArray[ret];
			int newId = 0;
			int newSalary;
			string newName = "";
			int dSelect = 0;
			cout << "���ҵ�ְ�����Ϊ[" << id << "]��ְ������������ְ����:" << endl;
			cin >> newId;
			cout << "������������:" << endl;
			cin >> newName;
			cout << "��������н��:" << endl;
			cin >> newSalary;
			cout << "�������¸�λ:" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//���ݸ��µ�������
			this->m_EmpArray[ret] = wokerbase;
			cout << "ְ����Ϣ�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//����ְ��
void WokerManager::Find_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "���������ְ���ķ�ʽ:" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//���ձ�Ų���
			int id;
			cout << "��������ҵ�ְ���ı��" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1) {
				//�ҵ���ְ��
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2) {
			//������������
			string name;
			cout << "���������ְ������:" << endl;
			cin >> name;
			//�����Ƿ�鵽�ı�־
			bool select_flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->get_m_Name() == name) {
					cout << "���ҳɹ���ְ�����Ϊ["
						<< this->m_EmpArray[i]->get_m_Name()
						<< "]��ְ����Ϣ���£�" << endl;

					select_flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (select_flag == false) {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else {
			cout << "����ѡ������" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//ְ������
void WokerManager::Sort_Emp() {
	if (this->m_FilesIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��ѡ������ʽ:" << endl;
		cout << "1������ְ���Ž�����������" << endl;
		cout << "2������ְ���Ž��н�������" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) {
			int minOrMax = i;//������Сֵ�������ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {//����
					if (this->m_EmpArray[minOrMax]->get_m_Id() > this->m_EmpArray[j]->get_m_Id()) {
						minOrMax = j;
					}

				}
				else {//����
					if (this->m_EmpArray[minOrMax]->get_m_Id() < this->m_EmpArray[j]->get_m_Id()) {
						minOrMax = j;
					}
				}
			}

			//�ж�һ��ʼ�϶�����Сֵ�������ֵ �ǲ��Ǽ������Сֵ�������ֵ�����������ͽ�������
			if (i != minOrMax) {
				WorkerBase* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}
	}
	cout << "����ɹ����������Ϊ:" << endl;
	this->save();//�����Ľ�����浽�ļ���
	this->Show_Emp();
}

// ����ļ�
void WokerManager::Clean_File() {
	cout << "ȷ������ļ���" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int selcet = 0;
	cin >> selcet;
	if (selcet == 1) {
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		if (this->m_EmpArray != NULL) {
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;

			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FilesIsEmpty = true;
		}

		cout << "��ճɹ���" << endl;
	}

	//�����������
	system("pause");
	system("cls");

}

