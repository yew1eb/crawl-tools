#include<iostream>
#include<set>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
int d[301];
int c[50001];
int e[50001];

bool cmp(const int x,const int y)
{
    return x<y;
}

set<int> s;
int main()
{
int t;
scanf("%d",&t);
for(int l=1;l<=t;l++)
{   
    int a[101];
    int p,k;
    memset(c,0,sizeof(c));
    memset(e,0,sizeof(e));
    scanf("%d %d",&p,&k);
    for(int i=1;i<=p;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a+1,a+p+1,cmp);

    s.clear();
    for(int i=1;i<=p;i++)
    {
       if(i!=p) {
           s.insert(a[i]);
        s.insert(a[i]*2);
        s.insert(a[i]*3);
        }
        else
        {
            s.insert(a[i]);
    s.insert(a[i]*2);
        }
    }

    set<int>::iterator it,iy;
    int i=0;
    for(it=s.begin();it!=s.end();it++)
    {
         d[++i]=*it;
    }
    int ans=i;

   e[0]=1;
   c[0]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=d[ans]*k;j++)
         for(int h=1;h<=ans;h++)
         {
             if(e[j]==1)
             c[j+d[h]]=1;
         }
        for(int j=0;j<=d[ans]*k;j++)
        {
            e[j]=c[j];
        }
    }
    int sum=0;
    for(int j=0;j<=d[ans]*k;j++)
     if(e[j]==1)
     {
         sum++;
    }
     printf("Scenario #%d:\n",l);
    cout<<sum<<endl<<endl;

}
return 0;
}