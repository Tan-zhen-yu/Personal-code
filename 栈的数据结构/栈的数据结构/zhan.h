
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define Maxsize 50//˳��ջ��С
typedef char ElemType1 ;//ElemType������
typedef double ElemType2;

typedef struct//˳��ջ�ṹ��
{
	ElemType1 data[Maxsize];
	int top;
}Sqstack;

typedef struct//˳��ջ�ṹ��
{
	ElemType2 data[Maxsize];
	int top;
}Sqstack1;

typedef struct linknode//��ջ�ṹ��
{
	ElemType1 data;
	struct linknode* next;
}LinkStNode;




void SqInitStack(Sqstack*& s);//˳��ջ��ʼ��

void SqDestoryStack(Sqstack*& s);//˳��ջ����

bool SqStackEmpty(Sqstack* s);//�ж�˳��ջ�Ƿ�Ϊ��

bool SqPush(Sqstack*& s, ElemType1 e);//��˳��ջ

bool SqPop(Sqstack*& s, ElemType1& e);//��˳��ջ

bool SqGetTop(Sqstack* s, ElemType1& e);//��˳��ջջ��Ԫ��

void SqInitStack1(Sqstack*& s);//˳��ջ��ʼ��

void SqDestoryStack1(Sqstack*& s);//˳��ջ����

bool SqStackEmpty1(Sqstack* s);//�ж�˳��ջ�Ƿ�Ϊ��

bool SqPush1(Sqstack*& s, ElemType2 e);//��˳��ջ

bool SqPop1(Sqstack*& s, ElemType2& e);//��˳��ջ

bool SqGetTop1(Sqstack* s, ElemType2& e);//��˳��ջջ��Ԫ��

bool symmetry(ElemType1 str[]);//�ж��Ƿ�Ϊ�Գƴ����㷨

void LInitStack(LinkStNode*& s);//��ջ��ʼ��

void LDestoryStack(LinkStNode*& s);//������ջ

bool LStackEmpty(LinkStNode* s);//�ж���ջ�Ƿ�Ϊ��

bool LPush(LinkStNode*& s, ElemType1 e);//Ԫ�ؽ���ջ

bool LPop(LinkStNode*& s, ElemType1& e);//����ջ;

bool Match(char exp[], int n); //�ж�����ı��ʽ�������Ƿ����,�㷨

void trans(char* exp, char postexp[]);//����ͨ���ʽת���ɺ�׺���ʽ

double compvalue(char* postexp);//��˳��ջ�����׺���ʽ��ֵ