#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include"boss.h"
using namespace std;

Boss::Boss(int id, string name, int dId) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_DpetId = dId;

}

void  Boss::showInfo() {

	cout << " ְ�����:  " << this->m_Id
		<< "\tְ������ " << this->m_Name
		<< "\t��λ " << this->getDepetName()
	<< "\t��λְ��:����˾ȫ������" << endl;


}



string Boss ::getDepetName() {

	
	return string("�ܲ�");
}