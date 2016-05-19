#include<iostream>
#include<cstdlib>
#include<stdio.h>
#define ll __int64
using namespace std;
int mm[5];
int uu[55];
int yy[55][5];
int n;
int res[55];
char cc[4];
ll x,y,ti;
void zhuanhuan()
{
    for(int i=1;i<=n;i++)
    for(int j=4;j>=1;j--)
    {
        yy[i][j]=uu[i]%100;
        uu[i]/=100;
    }
}
void change()
{

    for(int i=1;i<=n;i++)
    {
        int d=0;
        for(int j=1;j<=3;j++)
       {
        int oo=res[i]%100;
        res[i]/=100;
        if(oo==27)
        {
            cc[d++]=' ';
        }
        else
        {
        oo--;
        cc[d++]=char(oo+'A');
        }
       }
       for(int k=d-1;k>=0;k--)
       {
           if(i==n)
           {
               if(cc[k]==' ')
               break;
               else
               putchar(cc[k]);
           }
           else
           putchar(cc[k]);
       }
    }
    printf("\n");
}
ll egcd(ll a,ll b)
{
    if(b==0){x=1;y=0;return a;}
    else{ll e=egcd(b,a%b);ti=x;x=y;y=ti-a/b*y;return e;}
}
void solve()
{
    ll d,c,t;
    for(int i=1;i<=n;i++)
    {
        int m1=mm[1];
        int r1=yy[i][1];
        for(int j=2;j<=4;j++)
       {
        d=egcd(m1,mm[j]);
        c=yy[i][j]-r1;
        t=mm[j]/d;
        x=(c/d*x%t+t)%t;
        r1=m1*x+r1;
        m1=m1*mm[j]/d;
       }
       res[i]=r1;
    }
    /*for(int i=1;i<=n;i++)
    cout<<res[i]<<" ";
    cout<<endl;*/
}
int main()
{

   int t;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       for(int i=1;i<=4;i++)
       scanf("%d",&mm[i]);
       for(int i=1;i<=n;i++)
       scanf("%d",&uu[i]);
       zhuanhuan();
       solve();
       change();
   }
}
