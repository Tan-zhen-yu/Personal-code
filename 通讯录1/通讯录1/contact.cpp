#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void LoadContact(Contact*pc)
{
	FILE* pf = fopen("Contact.dat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//读文件
	
	while (fscanf(pf, "%s %s %d %s %s", pc->data[pc->sz].name, pc->data[pc->sz].sex, &pc->data[pc->sz].age, pc->data[pc->sz].tele, pc->data[pc->sz].addr) != EOF)
	{
		pc->sz++;
		CheckContact(pc);
	}

	//关闭文件
	fclose(pf);
	
}

void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(INT_CHU*sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = 3;

	LoadContact(pc);
}

void CheckContact(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INT_ADD) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("容量已满，增容失败\n");
			return;
		}
		else
		{
			printf("增容成功\n");
			pc->data = ptr;
			pc->capacity += INT_ADD;
		}
	}

}

void AddContact(Contact* pc)
{
	CheckContact(pc);
	//增加一个人的信息
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("增加成功\n");
}

void PrintContact(const Contact* pc)
{
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].addr);
	}
	printf("\n");
}

void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
			return;
	}
	char name[MAX_NAME];
	printf("请输入需要删除人的姓名:>");
	scanf("%s", name);
	int ret = FindByname(pc, name);
	if (ret == -1)
	{
		printf("此人不存在\n");
		return;
	}
	else
	{
		while (ret < pc->sz-1)
		{
			pc->data[ret] = pc->data[ret + 1];
			ret++;
		}
		printf("删除成功\n");
		pc->sz--;
	}
}

int FindByname(Contact* pc, char name[])
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void SearchContact(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入需要查找的名字:>");
	scanf("%s", name);
	int ret= FindByname(pc, name);
	if (ret == -1)
	{
		printf("未找到此人\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[ret].name, pc->data[ret].sex, pc->data[ret].age, pc->data[ret].tele, pc->data[ret].addr);
	}
}


void ModifyContact(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入需要修改人的姓名;>");
	scanf("%s", name);
	int ret = FindByname(pc, name);
	if (ret == -1)
	{
		printf("未找到此人\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", pc->data[ret].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[ret].age);
	printf("请输入性别:>");
	scanf("%s", pc->data[ret].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[ret].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[ret].addr);
	printf("修改成功\n");


}

void SortContact(Contact* pc)
{
	int ret = 0;
	PeoInfo temp ;
	for (int j = 0; j < pc->sz - 1; j++)
	{
		for (int i = 0; i < pc->sz - 1; i++)
		{
			ret = strcmp(pc->data[i].name, pc->data[i + 1].name);
			if (ret > 0)
			{
				temp = pc->data[i];
				pc->data[i] = pc->data[i + 1];
				pc->data[i + 1] = temp;
			}
		}
	}
	printf("排序成功\n");
}

void ExitContact(Contact* pc)
{

	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

void SaveContact(Contact* pc)
{
	//打开文件
	FILE*pf=fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写文件
	for (int i = 0; i < pc->sz; i++)
	{
		fprintf(pf, "%s %s %d %s %s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].addr);
	}

	//关闭文件
	fclose(pf);
}