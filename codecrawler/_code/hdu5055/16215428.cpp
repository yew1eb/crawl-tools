#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cmath>
const int INF=99999999;
#include <algorithm>
using namespace std;

int a[110];
bool cmp(int a,int b)
{
  return a>b;
}
int main()
{
    int n;
    while(cin>>n)
    {
      for(int i=1;i<=n;i++)
      {
        cin>>a[i];
      }
     if(n==1)
     {
       if(a[1]&1)
            cout<<a[1]<<endl;
       else
            cout<<-1<<endl;
       continue;
     }
     sort(a+1,a+1+n,cmp);

     int flag=INF;
     for(int i=n;i>=1;i--)
     {
       if(a[i]&1)
       {
        flag=i;
        break;
       }
     }
     if(flag==INF)
     {
       cout<<-1<<endl;
       continue;
     }
     if(flag==1&&a[2]==0)
     {
       cout<<-1<<endl;
       continue;
     }
     for(int i=1;i<=n;i++)
     {
       if(i!=flag)
            cout<<a[i];
     }
     cout<<a[flag]<<endl;
    }
    return 0;
}
