#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include"employee.h"
using namespace std;

Employee::Employee(int id, string name, int dId) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_DpetId = dId;

}

void  Employee::showInfo() {

	cout << " ְ�����:  " << this->m_Id
		<< "\tְ������ " << this->m_Name
		<< "\t��λ " << this->getDepetName()
	<< "\t��λְ��:��ɾ�����������" << endl;

}



string Employee::getDepetName() {

	return string("��ͨԱ��");
}