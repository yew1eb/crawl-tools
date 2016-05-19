#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

bool cmp(int x,int y)
{
 return (x>y);
}

int main ()
{
 int n,m,a[1000];
 int i;
 while(cin>>n>>m)
 {
     for(i=0;i<m;i++)
        cin>>a[i];

     sort(a,a+m,cmp);

     int k=0;
     int sum=0;
     int flag=0;
     for(i=0;i<m;i++)
     {
         k++;
         sum+=a[i];
         if(sum>=n)
         {
            flag=1;
            break;
         }
     }
     if(!flag)
       cout<<"impossible"<<endl;
     else
       cout<<k<<endl;
 }
}
