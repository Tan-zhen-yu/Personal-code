#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define Maxsize 50//˳��ջ��С
typedef double ElemType ;//ElemType������

typedef struct//˳��ջ�ṹ��
{
	ElemType data[Maxsize];
	int top;
}Sqstack;

typedef struct linknode//��ջ�ṹ��
{
	ElemType data;
	struct linknode* next;
}LinkStNode;




void SqInitStack(Sqstack*& s);//˳��ջ��ʼ��

void SqDestoryStack(Sqstack*& s);//˳��ջ����

bool SqStackEmpty(Sqstack* s);//�ж�˳��ջ�Ƿ�Ϊ��

bool SqPush(Sqstack*& s, ElemType);//��˳��ջ

bool SqPop(Sqstack*& s, ElemType e);//��˳��ջ

bool SqGetTop(Sqstack* s, ElemType e);//��˳��ջջ��Ԫ��

bool symmetry(ElemType str[]);//�ж��Ƿ�Ϊ�Գƴ����㷨

void LInitStack(LinkStNode*& s);//��ջ��ʼ��

void LDestoryStack(LinkStNode*& s);//������ջ

bool LStackEmpty(LinkStNode* s);//�ж���ջ�Ƿ�Ϊ��

bool LPush(LinkStNode*& s, ElemType e);//Ԫ�ؽ���ջ

bool LPop(LinkStNode*& s, ElemType& e);//����ջ;

bool Match(char exp[], int n); //�ж�����ı��ʽ�������Ƿ����,�㷨

void trans(char exp[], char postexp[]);//����ͨ���ʽת���ɺ�׺���ʽ

double compvalue(char postexp[]);//��˳��ջ�����׺���ʽ��ֵ