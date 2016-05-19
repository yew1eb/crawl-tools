#include<iostream>
#include<stdio.h>
using namespace std;
int a[1000005],b[10005];
int nextval[10005];
void get_next(int b[],int m)
{
    int i=0;
    nextval[0]=-1;
    int j=-1;
    while(i<m)
    {
     if(j==-1||b[i]==b[j])
     {
        ++i;
        ++j;
      if(b[i]==b[j])
      nextval[i]=nextval[j];
      else
      nextval[i]=j;
    }
    else
    j=nextval[j];
   }
}
int KMP(int a[],int n,int b[],int m,int nextval[],int pos)
{
    int i=pos;
    int j=0;
    while(i<n&&j<m)
    {
    if(j==-1||a[i]==b[j])
    {
        ++i;
        ++j;
    }
    else
    j=nextval[j];
    }
   if(j>=m)
   return i-j+1;
   else
   return -1;
}
int main()
{
    int test,n,m,i,j;
    scanf("%d",&test);
    while(test--)
    {
     scanf("%d%d",&n,&m);
     for(i=0;i<n;++i)
     scanf("%d",&a[i]);
     for(j=0;j<m;++j)
     scanf("%d",&b[j]);
     get_next(b,m);
     cout<<KMP(a,n,b,m,nextval,0)<<endl;
    }
}
    
