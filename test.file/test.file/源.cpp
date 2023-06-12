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
	//打开文件
	struct S s={"张三",18,"男"};
	FILE*pf=fopen("D:\\Github Desktop\\Personal-code\\test.file\\test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//写文件
	fread(&s, sizeof(S), 1, pf);
	printf("%s %d %s", s.name, s.age, s.sex);



	//关闭文件
	fclose(pf);




	return 0;
}