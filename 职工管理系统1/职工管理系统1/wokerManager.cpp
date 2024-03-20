#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include"wokerManager.h"

using namespace std;




wokerManager::wokerManager() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在，打开失败" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空，打开失败" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	this->m_EmpNum = this->get_EmpNum();

	this->m_EmpArray = new Woker * [this->m_EmpNum];

	this->init_Emp();

	ifs.close();

}

void wokerManager::showWokerManager() {

	for (int i = 0; i < m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
	}


}

void wokerManager::init_Emp() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	Woker* woker = NULL;

	int id;
	string name;
	int dId;
	int i = -0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		switch (dId)
		{
		case 1: {
			woker = new Employee(id, name, 1);
			break;
		}
		case 2: {
			woker = new Manager(id, name, 2);
			break;
		}
		case 3: {
			woker = new Boss(id, name, 3);
			break;
		}
		default:
			break;
		}
		this->m_EmpArray[i];
		i++;
	}






}

int wokerManager::get_EmpNum() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	ifs.close();

	return num;

}

wokerManager::~wokerManager() {

	delete[] this->m_EmpArray;
	this->m_EmpArray = NULL;

}

void wokerManager:: save() {
	
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id<<" "
		 << this->m_EmpArray[i]->m_Name<<" "
		 << this->m_EmpArray[i]->m_DpetId<<endl;
	}

	ofs.close();
}

void wokerManager::Add_Emp() {

	cout << "请输入需要添加职工的人数" << endl;
	int addNum = 0;

	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;

		Woker** newSpace = new Woker * [newSize];

		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dId;//部门

			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl
				<< "1、普通员工" << endl
				<< "2、经理" << endl
				<< "3、老板" << endl;
			int slect;
			cin >> slect;
			Woker* woker=NULL;
			switch (slect)
			{
			case 1: {
				woker = new Employee(1, name, 1);
				break;
			}
			case 2: {
				woker = new Manager(1, name, 2);
				break;
			}
			case 3: {
				woker = new Boss(1, name, 3);
				break;
			}
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = woker;
			
		}
		delete[] this->m_EmpArray;

		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		cout << "成功添加" << addNum << "名新职工" << endl;

		this->save();
			
	}
	else
	{
		cout << "输入有误，已退出" << endl;
	}


}


void wokerManager:: showMenu() {

	cout << "****************************************" << endl;
	cout << "**********欢迎使用职工管理系统**********" << endl;
	cout << "**********   0 退出管理系统   **********" << endl;
	cout << "**********   1 添加职工信息   **********" << endl;
	cout << "**********   2 显示职工信息   **********" << endl;
	cout << "**********   3 删除离职职工   **********" << endl;
	cout << "**********   4 修改职工信息   **********" << endl;
	cout << "**********   5 查找职工信息   **********" << endl;
	cout << "**********   6 按照编号排序   **********" << endl;
	cout << "**********   7 清空所有文档   **********" << endl;
	cout << "****************************************" << endl;
}


int main()
{
	wokerManager wk;
	
	int slect = 1;

	while (slect)
	{
		
		wk.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> slect;
		
		switch (slect){
			
			//退出
			case 0: {
				cout << "感谢使用,退出成功" << endl;
				break;
			}
			//添加
			case 1: {
				wk.Add_Emp();
				break;
			}
			//显示
			case 2: {
				wk.showWokerManager();
				break;
			}
			//删除
			case 3: {

				break;
			}
			//修改
			case 4: {

				break;
			}
			case 5: {

				break;
			}
			case 6: {

				break;
			}
			case 7: {

				break;
			}
		
			default:
				cout<<"选择错误，请重新选择"<<endl;
				break;
			}
		system("pause");
		system("cls");
	}


	return 0;
}