/*******************************************************************************
 # Author : Neo Fung
 # Email : [email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */
 # Last modified: 2012-04-06 19:38
 # Filename: ZOJ1499 POJ1239 HDU1511 Increasing Sequences.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 100
using namespace std;

char num[MAX];
int dp[MAX],dprev[MAX];
int now[MAX],ans[MAX];

bool check( char *lhs,int n, char *rhs,int m)
{
	char *p=lhs,*q=rhs;
	while(*p=='0' && n)
	{
		++p;
		--n;
	}
	while(*q=='0' && m)
	{
		++q;
		--m;
	}
	if(n<m)
		return true;
	else if(n>m)
		return false;
	for(int i=0;i<n;++i)
		if(*p<*q)
			return true;
		else if(*p>*q)
			return false;
		else
		{
			++p;
			++q;
		}
	return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int ncase=1;
  //   scanf("%d",&ncase);

	while(gets(num+1))
  {
		int n=strlen(num+1)+1;
		if(n==2 && num[1]=='0')
			break;

		num[0]='0';
		memset(dp,0,sizeof(dp));
		memset(now,0,sizeof(now));
		dp[1]=1;
		
		for(int i=2;i<n;++i)
		{
			dp[i]=i;
			for(int j=i-1;j>0;--j)
			{
				int t=i-j;
				if(check(num+j-dp[j]+1,dp[j],num+j+1,t))
				{
					dp[i]=t;
					break;
				}
			}
		}
		int pos=n-1;
		while(pos>0)
		{
			now[pos-dp[pos]+1]=dp[pos];
			pos=pos-dp[pos];
		}

    int last=n-dp[n-1];
		dp[last]=dp[n-1];

		for(int i=last-1;i>0;--i)
		{
			dp[i]=-1;
      if(num[i]=='0')  
      {  
        dp[i]=dp[i+1]+1;  
        continue;  
      }  
			for(int j=last;j>i;--j)
				if(check(num+i,j-i,num+j,dp[j]))
				{
					dp[i]=j-i;
					break;
				}
		}

		pos=1;
		memset(ans,0,sizeof(ans));
		while(pos<n)
		{
			ans[pos]=1;
			pos=pos+dp[pos];
		}

		for(int i=1;i<n;++i)
		{
			if(ans[i]&&i>1)
				printf(",");
			printf("%c",num[i]);
		}
		printf("\n");
	}
	return 0;

}