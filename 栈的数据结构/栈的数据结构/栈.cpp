#define _CRT_SECURE_NO_WARNINGS
#include"zhan.h"

void SqInitStack (Sqstack *& s)
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

bool SqPush(Sqstack*& s, ElemType e)
{
	if (s->top == Maxsize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool SqPop(Sqstack*& s, ElemType e)
{
	if (SqStackEmpty(s))
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}


bool SqGetTop(Sqstack* s, ElemType e)
{
	if (SqStackEmpty(s))
		return false;
	else
		e = s->data[s->top];

}

//���һ���㷨������˳��ջ�ж�һ���ַ����Ƿ�Ϊ�Գƴ�
bool symmetry(ElemType str[])
{
	int i; char e=0;
	Sqstack* st;
	SqInitStack(st);
	for (i = 0; str[i] != '\0';i++)
	{
		SqPush(st, str[i]);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		 SqPop(st,e);
		 if (str[i] != e)
		 {
			 SqDestoryStack(st);
			 return false;
		 }
			 
		 
	}
	SqDestoryStack(st);
	return true;
}


//ջ����ʽ�洢




void LInitStack(LinkStNode*& s)//��ջ��ʼ��
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;

}

void LDestoryStack(LinkStNode*& s)//������ջ
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

bool LStackEmpty(LinkStNode* s)//�ж���ջ�Ƿ�Ϊ��
{
	return (s->next == NULL);
}

bool LPush(LinkStNode*& s, ElemType e)//Ԫ�ؽ���ջ
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;
}

bool LPop(LinkStNode*&s, ElemType &e)//����ջ
{
	LinkStNode* p;
	if (LStackEmpty)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
}

bool GetTop(LinkStNode* s, ElemType& e)//ȡ��ջ��Ԫ��
{
	if (LStackEmpty)
		return false;
	e = s->next-> data;
	return true;
}


//���һ���㷨�ж�����ı��ʽ�������Ƿ����



bool Match(char exp[], int n)
{
	ElemType e;
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

//����ͨ���ʽת���ɺ�׺���ʽ

void trans( char exp[], char postexp[])
{
	char e=0;
	char c; Sqstack* Optr;
	SqInitStack(Optr);
	int j = 0;
	for (int i = 0; *exp != '\0'; exp++)
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
			while (*exp >= '0' && *exp< '9')
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


//��ջ�����׺���ʽ��ֵ

double compvalue(char postexp[])
{
	double d=0, a=0, b=0, c=0, e=0;
	Sqstack* Opnd;
	SqInitStack(Opnd);
	int i = 0;
	while (postexp[i] != '\0')
	{
		switch (postexp[i])
		{
		case'+':
			SqPop(Opnd, a);
			SqPop(Opnd, b);
			c = b + a;
			SqPush(Opnd, c);
			break;

		case'-':
			SqPop(Opnd, a);
			SqPop(Opnd, b);
			c = b - a;
			SqPush(Opnd, c);
			break;
		case'*':
			SqPop(Opnd, a);
			SqPop(Opnd, b);
			c = b * a;
			SqPush(Opnd, c);
			break;
		case'/':
			SqPop(Opnd, a);
			SqPop(Opnd, b);
			if (a != 0)
			{
				c = b / a;
				SqPush(Opnd, c);
				break;
			}
			else
			{
				printf("\n\t�������\n");
				exit(0);
			}
			break;
		default:
			d = 0;
			while (postexp[i] >= '0' && postexp[i] <= '9')
			{
				d = 10 * d + (postexp[i] - '0');
				i++;
			}
			SqPush(Opnd, d);
			break;
		}
		i++;

	}
	SqGetTop(Opnd, e);
	SqDestoryStack(Opnd);
	return e;
}