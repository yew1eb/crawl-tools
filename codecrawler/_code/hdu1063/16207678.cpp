#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int maxn=2e4+10;
char a[10],c[1000];
int b[1000],t,k;
void mul(int m)//å¤§æ°ä¹æ³
{
    int i,j;
    for(i=0;i<t;i++)
        b[i]=b[i]*m;
    int temp=0,x;
    for(i=0;i<t;i++)
    {
        x=b[i]+temp;
        b[i]=x%10;
        temp=x/10;
    }
    while(temp)
    {
        b[t++]=temp%10;
        temp=temp/10;
    }
}
void pows(int m,int n)//æ±m^nï¼å¹¶è¾åºç»æ
{
    int i,j,num=0;
    for(i=2;i<=n;i++)
        mul(m);
    k=k*n;
    //å¤æ­å°æ°ç¹çä½ç½®
    if(k>=t)
    {
        c[num++]='.';
        for(i=k-1;i>=t;i--)c[num++]='0';
        for(i=t-1;i>=0;i--)c[num++]='0'+b[i];
    }
    else
    {
        for(i=t-1;i>=0;i--)
        {
            c[num++]='0'+b[i];
            if(i==k)c[num++]='.';
        }
    }
    //å é¤å°æ°é¨ååç¼é¶åå¤ä½çå°æ°ç¹
    while(c[num-1]=='0')num--;
    if(c[num-1]=='.')num--;
    c[num]='\0';
    printf("%s\n",c)
;}
int main()
{
    int n;
    while(scanf("%s%d",a,&n)!=EOF)
    {
        //if(n==0){printf("1\n");continue;}
        int i,j,m=0;
        for(i=0,k=0;i<6;i++)
        {
            if(a[i]=='.')
            {
                k=5-i;
                continue;
            }
            m=m*10+(a[i]-'0');
        }
        t=0;
        i=m;
        //if(m==0){printf("0\n");continue;}
        //printf("%d\n",m);
        while(i!=0)
        {
            b[t++]=i%10;
            i=i/10;
        }
        pows(m,n);
    }
    return 0;
 }
