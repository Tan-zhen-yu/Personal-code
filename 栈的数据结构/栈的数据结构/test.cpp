
#define _CRT_SECURE_NO_WARNINGS
#include"zhan.h"

void SqInitStack(Sqstack*& s)
{
	s = (Sqstack*)malloc(sizeof(Sqstack));
	s->top = -1;


}

void SqDestoryStack(Sqstack*& s)
{
	free(s);
}

bool SqStackEmpty(Sqstack* s)
{
	return(s->top == -1);
}

bool SqPush(Sqstack*& s, ElemType1 e)
{
	if (s->top == Maxsize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool SqPop(Sqstack*& s, ElemType1& e)
{
	if (SqStackEmpty(s))
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}


bool SqGetTop(Sqstack* s, ElemType1& e)
{
	if (SqStackEmpty(s))
		return false;
	else
		e = s->data[s->top];

}

//设计一个算法，利用顺序栈判断一个字符串是否为对称串
bool symmetry(ElemType1 str[])
{
	int i; char e = 0;
	Sqstack* st;
	SqInitStack(st);
	for (i = 0; str[i] != '\0'; i++)
	{
		SqPush(st, str[i]);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		SqPop(st, e);
		if (str[i] != e)
		{
			SqDestoryStack(st);
			return false;
		}


	}
	SqDestoryStack(st);
	return true;
}

//1
void SqInitStack1(Sqstack1*& s)
{
	s = (Sqstack1*)malloc(sizeof(Sqstack1));
	s->top = -1;


}

void SqDestoryStack1(Sqstack1*& s)
{
	free(s);
}

bool SqStackEmpty1(Sqstack1* s)
{
	return(s->top == -1);
}

bool SqPush1(Sqstack1*& s, ElemType2 e)
{
	if (s->top == Maxsize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool SqPop1(Sqstack1*& s, ElemType2& e)
{
	if (SqStackEmpty1(s))
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}


bool SqGetTop1(Sqstack1* s, ElemType2& e)
{
	if (SqStackEmpty1(s))
		return false;
	else
		e = s->data[s->top];

}

//设计一个算法，利用顺序栈判断一个字符串是否为对称串



//栈的链式存储




void LInitStack(LinkStNode*& s)//链栈初始化
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;

}

void LDestoryStack(LinkStNode*& s)//销毁链栈
{
	LinkStNode* pre = s, * p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

bool LStackEmpty(LinkStNode* s)//判断链栈是否为空
{
	return (s->next == NULL);
}

bool LPush(LinkStNode*& s, ElemType1 e)//元素进链栈
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}

bool LPop(LinkStNode*& s, ElemType1& e)//出链栈
{
	LinkStNode* p;
	if (LStackEmpty)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
}

bool GetTop(LinkStNode* s, ElemType1& e)//取链栈顶元素
{
	if (LStackEmpty)
		return false;
	e = s->next->data;
	return true;
}


//设计一个算法判断输入的表达式中括号是否配对



bool Match(char exp[], int n)
{
	ElemType1 e;
	LinkStNode* st;
	bool match = true;
	LInitStack(st);
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
		{
			LPush(st, exp[i]);
		}
		else if (exp[i] == ')')
		{
			LPop(st, e);
			if (e != '(')
				match = false;
		}

	}
	if (!LStackEmpty(st))
	{
		match = false;
	}
	LDestoryStack(st);
	return match;



}

//将普通表达式转换成后缀表达式

void trans(char* exp, char postexp[])
{
	char e = 0;
	char c; Sqstack* Optr;
	SqInitStack(Optr);
	int j = 0;
	while(*exp!='\0')
	{
		switch (*exp)
		{
		case'(':
			SqPush(Optr, '(');
			exp++;
			break;
		case')':
			SqPop(Optr, e);
			while (e != '(')
			{
				postexp[j++] = e;
				SqPop(Optr, e);
			}
			exp++;
			break;
		case'+':
		case'-':
			while (!SqStackEmpty(Optr))
			{
				SqGetTop(Optr, e);
				if (e != '(')
				{
					postexp[j++] = e;
					SqPop(Optr, e);
				}
				else
					break;
			}
			SqPush(Optr, *exp);
			exp++;
			break;
		case'*':
		case'/':
			while (!SqStackEmpty(Optr))
			{
				SqGetTop(Optr, e);
				if (e == '*' || e == '/')
				{
					postexp[j++] = e;
					SqPop(Optr, e);
				}
				else
					break;

			}
			SqPush(Optr, *exp);
			exp++;
			break;
		default:
			while (*exp >= '0' && *exp < '9')
			{
				postexp[j++] = *exp;
				exp++;
			}
			postexp[j++] = '#';
		}


	}
	while (!SqStackEmpty(Optr))
	{
		SqPop(Optr, e);
		postexp[j++] = e;
	}
	postexp[j] = '\0';
	SqDestoryStack(Optr);
}


//用栈计算后缀表达式的值

double compvalue(char* postexp)
{
	double d = 0, a = 0, b = 0, c = 0, e = 0;
	Sqstack1* Opnd;
	SqInitStack1(Opnd);
	int i = 0;
	while (*postexp != '\0')
	{
		switch (*postexp)
		{
		case'+':
			SqPop1(Opnd, a);
			SqPop1(Opnd, b);
			c = b + a;
			SqPush1(Opnd, c);
			break;

		case'-':
			SqPop1(Opnd, a);
			SqPop1(Opnd, b);
			c = b - a;
			SqPush1(Opnd, c);
			break;
		case'*':
			SqPop1(Opnd, a);
			SqPop1(Opnd, b);
			c = b * a;
			SqPush1(Opnd, c);
			break;
		case'/':
			SqPop1(Opnd, a);
			SqPop1(Opnd, b);
			if (a != 0)
			{
				c = b / a;
				SqPush1(Opnd, c);
				break;
			}
			else
			{
				printf("\n\t除零错误！\n");
				exit(0);
			}
			break;
		default:
			d = 0;
			while (*postexp >= '0' && *postexp <= '9')
			{
				d = 10 * d + (*postexp - '0');
				postexp++;
			}
			SqPush1(Opnd, d);
			break;
		}
		postexp++;

	}
	SqGetTop1(Opnd, e);
	SqDestoryStack1(Opnd);
	return e;
}