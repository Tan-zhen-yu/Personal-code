#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct S
{
	char name[5];
	int age;
	char sex[4];
};

int main()
{
	//���ļ�
	struct S s={"����",18,"��"};
	FILE*pf=fopen("D:\\Github Desktop\\Personal-code\\test.file\\test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//д�ļ�
	fread(&s, sizeof(S), 1, pf);
	printf("%s %d %s", s.name, s.age, s.sex);



	//�ر��ļ�
	fclose(pf);




	return 0;
}