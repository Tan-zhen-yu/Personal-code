#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

void WriteFile()
{
	ofstream ofs;

	ofs.open("SecondFile",ios::out);


	ofs << "���� ʮ����";
	ofs << "���� ��ʮ��";
	
	ofs.close();

}



void ReadFile()
{
	ifstream ifs;

	ifs.open("SecondFile", ios::in);

	char arr[2024] = { 0 };

	while (ifs >> arr)
	{
		cout << arr << endl;
	}

	
}


int main()
{
	
	

	WriteFile();
	ReadFile();



	return 0;
}