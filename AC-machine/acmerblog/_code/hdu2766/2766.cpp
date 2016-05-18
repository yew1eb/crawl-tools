#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define maxn 1000100
#define ll long long
using namespace std;
char str[maxn];
ll a[maxn];
int main()
{
 // freopen("dd.txt","r",stdin);
 int ncase;
 scanf("%d",&ncase);
 while(ncase--)
 {
 scanf("%s",str);
 int len=strlen(str);
 ll tmp=0;
 int num=0,deep=0,i,ans=1;
 for(i=0;i<len;i++)
 {
 if(str[i]=='[')
 deep++;
 else if(str[i]==',')
 {
 if(tmp)
 {
 a[num++]=tmp*(1<<deep);
 }
 tmp=0;
 }
 else if(str[i]==']')
 {
 if(tmp)
 {
 a[num++]=tmp*(1<<deep);
 }
 tmp=0;
 deep--;
 }
 else
 {
 tmp=tmp*10+str[i]-'0';
 }
 }
 if(tmp)
 {
 a[num++]=tmp<<deep;
 }
 sort(a,a+num);
 tmp=1;
 for(i=1;i<num;i++)
 {
 if(a[i]==a[i-1])
 {
 tmp++;
 if(tmp>ans)ans=tmp;
 }
 else
 tmp=1;
 }
 printf("%d\n",num-ans);
 }
 return 0;
}