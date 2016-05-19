#include "iostream"
#include "stdio.h"
#include "math.h"
#include "vector"
#include "stack"
#include "queue"
#include "memory.h"
#include "algorithm"
#include "string"
using namespace std;

char e[250],post[250];
stack<char>Op;

bool Isnum(char c)
{
	if(c>='0'&&c<='9')
		return true;
	return false;
}

int OPMode(char c)
{
	if(c=='+')		return 1;
	if(c=='-')		return 2;
	if(c=='*')		return 3;
	if(c=='/')		return 4;
	return -1;
}

void SplitExp(char* s)
{
	int i,j=0;
	memset(post,'\0',sizeof(post));
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==' ')
			continue;
		post[j++]=' ';
		while(Isnum(s[i]))
			post[j++]=s[i++];
		int curop=OPMode(s[i]);
		if(curop!=-1)
		{
			if(curop<=2)
				while(!Op.empty())
				{
					post[j++]=Op.top();
					Op.pop();
				}
			else
			{
				while(!Op.empty()&&OPMode(Op.top())>2)
				{
					post[j++]=Op.top();
					Op.pop();
				}
			}
			Op.push(s[i])	;
		}
	}
	while(!Op.empty())
	{
		post[j++]=Op.top();
		Op.pop();
	}
}

stack<double>Num;
double Cal()
{
	while(!Num.empty())
		Num.pop();
	int i=0,j;
	int len=strlen(post);
	while (i++<len)
	{
		if(post[i]==' ')
			continue;
		double cur=0;
		bool hasnum=false;
		while (Isnum(post[i]))
		{
			cur*=10;
			cur+=post[i++]-'0';
			hasnum=true;
		}
		if(hasnum)
			Num.push(cur);
		if(OPMode(post[i])!=-1)
		{
			double num1=Num.top();
			Num.pop();
			double num2=Num.top();
			Num.pop();
			switch(post[i])
			{
			case '+':		Num.push(num2+num1);break;
			case '-':		Num.push(num2-num1);break;
			case '*':		Num.push(num2*num1);break;
			case '/':		Num.push(num2/num1);break;
			}
		}
	}
	return Num.top();
}

int main()
{
	while(gets(e))
	{
		if(strcmp(e,"0")==0)
			break;
		SplitExp(e);
		printf("%.2f\n",Cal());
	}
}