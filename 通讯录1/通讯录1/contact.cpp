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
	//���ļ�
	
	while (fscanf(pf, "%s %s %d %s %s", pc->data[pc->sz].name, pc->data[pc->sz].sex, &pc->data[pc->sz].age, pc->data[pc->sz].tele, pc->data[pc->sz].addr) != EOF)
	{
		pc->sz++;
		CheckContact(pc);
	}

	//�ر��ļ�
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
			printf("��������������ʧ��\n");
			return;
		}
		else
		{
			printf("���ݳɹ�\n");
			pc->data = ptr;
			pc->capacity += INT_ADD;
		}
	}

}

void AddContact(Contact* pc)
{
	CheckContact(pc);
	//����һ���˵���Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("���ӳɹ�\n");
}

void PrintContact(const Contact* pc)
{
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
			return;
	}
	char name[MAX_NAME];
	printf("��������Ҫɾ���˵�����:>");
	scanf("%s", name);
	int ret = FindByname(pc, name);
	if (ret == -1)
	{
		printf("���˲�����\n");
		return;
	}
	else
	{
		while (ret < pc->sz-1)
		{
			pc->data[ret] = pc->data[ret + 1];
			ret++;
		}
		printf("ɾ���ɹ�\n");
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
	printf("��������Ҫ���ҵ�����:>");
	scanf("%s", name);
	int ret= FindByname(pc, name);
	if (ret == -1)
	{
		printf("δ�ҵ�����\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[ret].name, pc->data[ret].sex, pc->data[ret].age, pc->data[ret].tele, pc->data[ret].addr);
	}
}


void ModifyContact(Contact* pc)
{
	char name[MAX_NAME];
	printf("��������Ҫ�޸��˵�����;>");
	scanf("%s", name);
	int ret = FindByname(pc, name);
	if (ret == -1)
	{
		printf("δ�ҵ�����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->data[ret].name);
	printf("����������:>");
	scanf("%d", &pc->data[ret].age);
	printf("�������Ա�:>");
	scanf("%s", pc->data[ret].sex);
	printf("������绰:>");
	scanf("%s", pc->data[ret].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[ret].addr);
	printf("�޸ĳɹ�\n");


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
	printf("����ɹ�\n");
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
	//���ļ�
	FILE*pf=fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//д�ļ�
	for (int i = 0; i < pc->sz; i++)
	{
		fprintf(pf, "%s %s %d %s %s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].addr);
	}

	//�ر��ļ�
	fclose(pf);
}