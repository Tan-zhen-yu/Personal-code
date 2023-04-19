#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define Maxsize 50//顺序栈大小
typedef double ElemType ;//ElemType的类型

typedef struct//顺序栈结构体
{
	ElemType data[Maxsize];
	int top;
}Sqstack;

typedef struct linknode//链栈结构体
{
	ElemType data;
	struct linknode* next;
}LinkStNode;




void SqInitStack(Sqstack*& s);//顺序栈初始化

void SqDestoryStack(Sqstack*& s);//顺序栈销毁

bool SqStackEmpty(Sqstack* s);//判断顺序栈是否为空

bool SqPush(Sqstack*& s, ElemType);//进顺序栈

bool SqPop(Sqstack*& s, ElemType e);//出顺序栈

bool SqGetTop(Sqstack* s, ElemType e);//求顺序栈栈顶元素

bool symmetry(ElemType str[]);//判断是否为对称串，算法

void LInitStack(LinkStNode*& s);//链栈初始化

void LDestoryStack(LinkStNode*& s);//销毁链栈

bool LStackEmpty(LinkStNode* s);//判断链栈是否为空

bool LPush(LinkStNode*& s, ElemType e);//元素进链栈

bool LPop(LinkStNode*& s, ElemType& e);//出链栈;

bool Match(char exp[], int n); //判断输入的表达式中括号是否配对,算法

void trans(char exp[], char postexp[]);//将普通表达式转换成后缀表达式

double compvalue(char postexp[]);//用顺序栈计算后缀表达式的值