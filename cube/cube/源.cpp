#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

class Cube {

private:

	float C_X=0;
	float C_Y=0;
	float C_Z=0;

public:

	Cube(float x, float y, float z)
	{
		C_X = x;
		C_Y = y;
		C_Z = z;
	};

	float GetX()
	{
		return C_X;
	};

	float SetX(float X)
	{
		C_X = X;
	};

	float GetY()
	{
		return C_Y;
	};

	float SetY(float Y)
	{
		C_Y = Y;
	};

	float GetZ()
	{
		return C_Z;
	};

	float SetZ(float Z)
	{
		C_Z = Z;
	};

	float GetS()
	{
		return 2 * (C_X * C_Y + C_X * C_Z + C_Y * C_Z);
	}

	float GetV()
	{
		return C_X * C_Y * C_Z;
	}





};

Cube Initcube()
{
	float x, y, z;
	float S;
	float V;
	cout << "������cube������ĳ����xyz" << endl;
	cin >> x;
	cin >> y;
	cin >> z;
	Cube cube(x, y, z);
	return cube;
}

bool Issame(Cube c1, Cube c2)
{
	if (c1.GetX() == c2.GetX() && c1.GetY() == c2.GetY() && c1.GetZ() == c2.GetZ())
		return true;

		return false;


}

void test()
{

	cout << "������������ȵ�������" << endl;
	bool flag=false;
	while (!flag)
	{
		Cube c1 = Initcube();
		Cube c2 = Initcube();
		flag =Issame(c1, c2);
		if (!flag)
			cout << "����ʧ�ܣ��������岻��ȣ�����������" << endl;

	}
	cout << "����ɹ�������" << endl;


}

int main()
{
	/*float S;
	float V;
	
	Cube cube=Initcube();

	S=cube.GetS();
	V = cube.GetV();
	cout <<"��������ı����="<<S << endl;
	cout << "������������=="<<V << endl;*/

	test();



	return 0;
}