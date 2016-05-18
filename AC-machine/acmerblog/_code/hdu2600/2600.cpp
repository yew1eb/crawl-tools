#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct ss
{
 int st,en;
}s[101];
int cmp(ss a,ss b)
{
  if(a.en!=b.en)
  return a.en<b.en;
  else
  a.st<b.st;

}
int main()
{
 int n,i,sum,max,st,en;
 char c[100];
 while(scanf("%d",&n)!=EOF)
 {
  max=-6000001;
   scanf("%d %d",&st,&en);
   for(i=0;i<n;i++)
   {
   scanf("%d %d%*c",&s[i].st,&s[i].en);
   gets(c);
   }
   sort(s,s+n,cmp);
   //for(i=0;i<n;i++)
   //printf("%d fggf %d\n",s[i].st,s[i].en);
   if(s[0].st-st>0)
   max=s[0].st-1;
   for(i=1;i<n;i++)
   {
    if(s[i].st-1<=s[i-1].en)
    {
        s[i].st=s[i-1].st;
    }
     else
      max=s[i].st-1;
   }
   if(s[n-1].en-en<0)
   max=en;
   if(max==-6000001) printf("Badly!\n");
   else printf("%d\n",max);
 }
}