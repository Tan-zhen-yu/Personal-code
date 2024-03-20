#pragma once
#include"woker.h"
#include<iostream>
#include<fstream>
#include"boss.h"
#include"manager.h"
#include"employee.h"
#include"woker.h"
#define FILENAME "empfile.txt"

class wokerManager {

public:
	wokerManager();

	~wokerManager();

	void showMenu();

	void Add_Emp();

	void save();

	int get_EmpNum();

	void init_Emp();

	void showWokerManager();

	bool m_FileIsEmpty;

	Woker** m_EmpArray;

	int m_EmpNum;
};