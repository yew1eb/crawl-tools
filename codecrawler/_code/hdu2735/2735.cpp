/* Author : yan
 * Question : POJ 3095 Linear Pachinko
 * Data && Time : Wednesday, January 12 2011 07:49 PM
 * Compiler : gcc (Ubuntu 4.4.3-4ubuntu5) 4.4.3
*/
#include<stdio.h>
#define bool _Bool
#define false 0
#define true 1
char value[85];
int len;

bool rightmove(int index)
{
	int i;
	for(i=index+1;i<len;i++)
	{
		if(value[i]=='/' || value[i]=='|') return false;
		if(value[i]=='.') return true;
	}
	return true;
}
bool leftmove(int index)
{
	int i;
	for(i=index-1;i>=0;i--)
	{
		if(value[i]=='//' || value[i]=='|') return false;
		if(value[i]=='.') return true;
	}
	return true;
}
int main()
{
	//freopen("input","r",stdin);
	int ans,i;
	float tmp;
	for(;;)
	{
		gets(value);
		ans=0;
		tmp=0.0;
		if(value[0]=='#') break;
		len=strlen(value);
		for(i=0;i<len;i++)
		{
			if( (i==0 && value[i]=='/') || (i==len-1 && value[i]=='//') ) ans+=100;
			else if(value[i]=='_') ans+=0;
			else if(value[i]=='.') ans+=100;
			else if(value[i]=='|')
			{
				//考虑墙的左面
				if(i==0) ans+=50;
				else if( leftmove(i) ) ans+=50;
				//考虑墙的右面
				if(i==len-1) ans+=50;
				else if( rightmove(i) ) ans+=50;
			}
			else if(value[i]=='/')
			{
				if( leftmove(i) ) ans+=100;

			}
			else if(value[i]=='//')
			{
				if( rightmove(i) ) ans+=100;
			}
			//printf("%d/n",ans);
		}
		printf("%d/n",ans/len);
	}
	return 0;
}