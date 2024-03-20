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

void wokerManager::delete_All() {

	delete[]this->m_EmpArray;
	this->m_EmpArray = NULL;
	this->m_EmpNum = 0;
	this->m_FileIsEmpty = true;

	return;
}

void wokerManager::quicksort(int left,int right) {

	int i = left;
	int j = right;
	Woker* temp;
	Woker* Base = this->m_EmpArray[left];
	

	if (left > right)
		return;
	while (i != j)
	{
		while (this->m_EmpArray[j]->m_Id >= Base->m_Id && i < j)
		{
			j--;
		}

		while (this->m_EmpArray[i]->m_Id <= Base->m_Id && i < j)
		{
			i++;
		}

		if (i < j)
		{
			temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[j];
			this->m_EmpArray[j] = temp;
		}

	}
	this->m_EmpArray[left] = this->m_EmpArray[i];
	this->m_EmpArray[i] = Base;

	quicksort(left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ���
	quicksort(i + 1, right);


}

void wokerManager::modifyManager() {

	bool flat = false;
	cout << "���������г�Ա��Ϣ" << endl;
	this->showWokerManager();
	cout << "�����뱻�޸��˵�����:" << endl;
	int id;
	string name;
	int dId;
	cin >> name;
	Woker* woker = NULL;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name.compare(name)==0)
		{
			flat = true;

			cout << "�������±��" << endl;
			cin >> id;
			cout << "������������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl
				<< "1����ͨԱ��" << endl
				<< "2������" << endl
				<< "3���ϰ�" << endl;
			cin >> dId;
		    woker = NULL;
			switch (dId)
			{
			case 1: {
				woker = new Employee(id, name, dId);
				break;
			}
			case 2: {
				woker = new Manager(id, name, dId);
				break;
			}
			case 3: {
				woker = new Boss(id, name, dId);
				break;
			}
			}
			this->m_EmpArray[i] = woker;
		}
		
	}
	if (flat == true)
	{
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

}

void wokerManager::showWokerManager() {

	bool flat = false;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
		flat = true;
	}
	if (flat == false)
	{
		cout << "��ʾʧ�ܣ���������" << endl;
	}

}

void wokerManager::queryManager() {

	cout << "��������Ҫ���ҵ����:<" << endl;
	cout << "1�����" << endl;
	cout << "2������" << endl;
	cout << "3����λ" << endl;
	bool flat = false;
	int id;
	string name;
	int dId;
	int slect = 0;
	cin >> slect;

	switch (slect)
	{
	case 1: {
		cout << "��������Ҫ���:<" << endl;
		cin >> id;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Id == id)
			{
				flat = true;
				this->m_EmpArray[i]->showInfo();
			}
		}
		break;
	}
	case 2: {
		cout << "��������Ҫ����:<" << endl;
		cin >> name;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == name)
			{
				flat = true;
				this->m_EmpArray[i]->showInfo();
			}
		}
		break;
	}
	case 3: {
		cout << "��������Ҫ��λ:<" << endl;
		cout << "1��Ա��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
		cin >> dId;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_DpetId == dId)
			{
				flat = true;
				this->m_EmpArray[i]->showInfo();
			}
		}
		break;
	}
	default:
		cout << "����������˳�" << endl;
		break;
	}
	if (flat == false)
	{
		cout << "���޴���" << endl;
	}
}

void wokerManager::deleteManager() {

	bool flat = false;
	cout << "���������г�Ա��Ϣ" << endl;
	this->showWokerManager();
	cout << "�����뱻ɾ���˵�����:" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name.compare(name) == 0)
		{
			flat = true;
			for (int j = i; j < this->m_EmpNum - 1; j++)
			{
				this->m_EmpArray[j] = this->m_EmpArray[j + 1];
			}
			this->m_EmpNum--;
		}
	}
	if (flat == false)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "ɾ���ɹ�" << endl;
	}


}

void wokerManager::init_Emp() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	Woker* woker = NULL;

	int id;
	string name;
	int dId;
	int i = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		switch (dId)
		{
		case 1: {
			woker = new Employee(id, name, dId);
			break;
		}
		case 2: {
			woker = new Manager(id, name, dId);
			break;
		}
		case 3: {
			woker = new Boss(id, name, dId);
			break;
		}
		default:
			break;
		}
		this->m_EmpArray[i]=woker;
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

	this->save();
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
			
			cin >> dId;
			Woker* woker=NULL;
			switch (dId)
			{
			case 1: {
				woker = new Employee(id, name, dId);
				break;
			}
			case 2: {
				woker = new Manager(id, name, dId);
				break;
			}
			case 3: {
				woker = new Boss(id, name, dId);
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
				wk.deleteManager();
				
				break;
			}
			//�޸�
			case 4: {
				wk.modifyManager();
				break;
			}
			//����
			case 5: {
				wk.queryManager();
				break;
			}
			//���ձ������
			case 6: {
				wk.quicksort(0, wk.m_EmpNum - 1);
				cout << "����ɹ�" << endl;
				break;
			}
			//��������ĵ�
			case 7: {
				wk.delete_All();
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