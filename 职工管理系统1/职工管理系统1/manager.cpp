#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include"manager.h"
using namespace std;

Manager::Manager(int id, string name, int dId) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_DpetId = dId;

}

void Manager::showInfo() {

	cout << " ְ�����:  " << this->m_Id
		<< "\tְ������ " << this->m_Name
		<< "\t��λ " << this->getDepetName()
		<< "\t��λְ��:����ܲõ�����" << endl;


}



string Manager::getDepetName() {

	return "����";
}