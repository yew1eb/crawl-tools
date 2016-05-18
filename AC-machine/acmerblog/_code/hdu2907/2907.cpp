/*************************************************************************
	> File Name: main.cpp
	> Author: huangshuai
	> Mail: [email protected]/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */ 
	> Created Time: Wed 13 Mar 2013 08:45:03 AM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct point
{
	int x,y;
	int num;
};
point vex[100];
int cross(const point &a,const point &b,const point &c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dis(const point &a,const point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(const point& a,const point &b)
{
	int m=cross(vex[0],a,b);
	if(m==0)
		return dis(vex[0],a)<dis(vex[0],b)?true:false;
	if(m>0)
		return true;
	else
		return false;
}
point stackk[100];
int flag[100],top,k;
void graham_scan(int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		if(vex[i].y<vex[0].y||(vex[i].y==vex[0].y&&vex[i].x<vex[0].x))
		{
			point temp;
			temp=vex[0];
			vex[0]=vex[i];
			vex[i]=temp;
		}
	}
	sort(vex+1,vex+n,cmp);
	memset(stackk,0,sizeof(stackk));
	stackk[0]=vex[0];
	stackk[1]=vex[1];
	top=2;
	for(i=2;i<n;i++)
	{
		while(top>=2&&cross(stackk[top-2],stackk[top-1],vex[i])<0)
		{
			top--;
		}
		stackk[top++]=vex[i];
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q,p;
		scanf("%d%d%d",&p,&q,&n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&vex[i].x,&vex[i].y);
			vex[i].num=i;
		}
		graham_scan(n);
	
		int ss=0;
		memset(flag,0,sizeof(flag));
		for(i=0;i<top;i++)
		{
			flag[stackk[i].num]=1;
		}
		flag[n]=flag[0];
		for(i=0;i<n;i++)
		{
			if(flag[i]==1&&flag[i+1]==0)
				ss++;
		}
		int res=top*q-ss*p-ss*q;
		if(res<=0)
			printf("0\n");
		else
			printf("%d\n",res);
	}
}