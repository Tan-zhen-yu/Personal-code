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
		cout << "�ļ������ڣ���ʧ��" << endl;
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
		cout << "�ļ�Ϊ�գ���ʧ��" << endl;
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

	cout << "��������Ҫ���ְ��������" << endl;
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
		//���������

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dId;//����

			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl
				<< "1����ͨԱ��" << endl
				<< "2������" << endl
				<< "3���ϰ�" << endl;
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

		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		this->save();
			
	}
	else
	{
		cout << "�����������˳�" << endl;
	}


}


void wokerManager:: showMenu() {

	cout << "****************************************" << endl;
	cout << "**********��ӭʹ��ְ������ϵͳ**********" << endl;
	cout << "**********   0 �˳�����ϵͳ   **********" << endl;
	cout << "**********   1 ���ְ����Ϣ   **********" << endl;
	cout << "**********   2 ��ʾְ����Ϣ   **********" << endl;
	cout << "**********   3 ɾ����ְְ��   **********" << endl;
	cout << "**********   4 �޸�ְ����Ϣ   **********" << endl;
	cout << "**********   5 ����ְ����Ϣ   **********" << endl;
	cout << "**********   6 ���ձ������   **********" << endl;
	cout << "**********   7 ��������ĵ�   **********" << endl;
	cout << "****************************************" << endl;
}


int main()
{
	wokerManager wk;
	
	int slect = 1;

	while (slect)
	{
		
		wk.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> slect;
		
		switch (slect){
			
			//�˳�
			case 0: {
				cout << "��лʹ��,�˳��ɹ�" << endl;
				break;
			}
			//���
			case 1: {
				wk.Add_Emp();
				break;
			}
			//��ʾ
			case 2: {
				wk.showWokerManager();
				break;
			}
			//ɾ��
			case 3: {

				break;
			}
			//�޸�
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
				cout<<"ѡ�����������ѡ��"<<endl;
				break;
			}
		system("pause");
		system("cls");
	}


	return 0;
}