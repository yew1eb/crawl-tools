#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;

int prim[10005],p;
//prim用来保存PHI的值
int num[10005];
int n,m;
void extend_gcd(int a,int b,int &x,int &y)
{
     if(b==0)
     {
          x=1;
          y=0;
     }
     else
     {
          int t;
          extend_gcd(b,a%b,x,y);
          t=x; x=y;
          y=t-(a/b)*y;
     }
}

void cal1(__int64 &ans,int x)  //计算（4*n-2）
{
     int i;
     //先把与因子不互质的找出来
     for(i=0;i<p;i++)
     {
          while(x%prim[i]==0)
          {
               x/=prim[i];
               num[i]++;
          }
     }

     //与m因子互质的,直接求
     ans=(ans*x)%m;
}

void cal2(__int64 &ans,int q)   //计算（n+1）
{
     int i;
     //先把与因子不互质的找出来
     for(i=0;i<p;i++)
     {
        while(q%prim[i]==0&&num[i]>0)
        {
           num[i]--;
           q/=prim[i];
        }
     }

     //与因子不互质的需要用扩展欧拉来求逆元
     if(q>1)
     {
          int x,y;
          extend_gcd(q,m,x,y);
          //q的逆元就是x
          x=(x%m+m)%m;
          ans=(ans*x)%m;
     }
}

int main()
{
     int t,i,j,k;
     while(scanf("%d%d",&n,&m))
     {
          if(n==0&&m==0)
               break;
          p=0; t=m;
          for(i=2;i*i<=t;i++)
               if(t%i==0)
               {
                    prim[p++]=i;
                    while(t%i==0)
                         t/=i;
               }
          if(t>1)
               prim[p++]=t;

          __int64 ans=1,res=1,tmp;
          //h(1)=1 h(2)=2 h(3)=5 h(4)=14
          memset(num,0,sizeof(num));
          for(i=2;i<=n;i++)
          {
               cal1(ans,4*i-2);
               cal2(ans,i+1);
               tmp=ans;
               for(j=0;j<p;j++)
                    for(k=0;k<num[j];k++)
                      tmp=(tmp*prim[j])%m;
               //tmp就是每一步的值
               res=(res+tmp)%m;
          }
          printf("%I64d\n",res);
     }
     return 0;
}