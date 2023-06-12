#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define INT_CHU  3
#define INT_ADD  2

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼
typedef struct Contact
{
	PeoInfo* data;//�����ӽ������˵���Ϣ
	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;
}con;

void InitContact(Contact* pc);

void AddContact(Contact* pc);

void PrintContact(const Contact* pc);

void DelContact(Contact* pc);

int FindByname(Contact* pc, char name[]);

void SearchContact(Contact* pc);

void ModifyContact(Contact* pc);

void SortContact(Contact* pc);

void ExitContact(Contact* pc);

void SaveContact(Contact* pc);

void LoadContact(Contact* pc);

void CheckContact(Contact*pc);
