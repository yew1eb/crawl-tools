#include<iostream>
#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	stack<char>s;
	char a[1001],b[1001];
	int n,i,j,count,c[1001];
	while(~scanf("%d",&n))
	{
		count=0;
		j=0;
		getchar();
		while(!s.empty())//**清空栈**//
		{
			s.pop();
		}
		scanf("%s %s",a,b);
		for(i=0;i<n;i++)
		{
			s.push(a[i]);//**入栈**//
			c[count]=1;//**进行标记**//
			count++;
		    while(j<n&&!s.empty())//**i进行移动而且栈为非空**//
			{
				if(s.top()==b[j])//**栈首相同**//
				{
					s.pop();//**出栈**//
				    c[count]=0;//**标记出栈**//
				    count++;
				    j++;//**j往右移动**//
				}
			    else
				{
				    break;
				}
			}
		}
		if(s.empty())
		{
			printf("Yes.\n");
			for(i=0;i<count;i++)
			{
				if(c[i]==1) printf("in\n");
				else if(c[i]==0)
					printf("out\n");
			}
		}
		else
		{
			printf("No.\n");
		}
		printf("FINISH\n");
	}
	return 0;
}