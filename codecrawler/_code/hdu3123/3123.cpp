/*
一个小技巧是当n>=m时n!%m==0
所以当n>=m时直接令n==m即可
这样就不用用处理大数乘法的方式处理n!了 
*/
#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<algorithm>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#define N 10005
using namespace std;
int main()
{
#ifdef LOCAL
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
#endif

     long long t=1,ans,i,ncase,m,n,nlen,mlen;string str;
     cin>>ncase;
     while(ncase--)
     {
            //数据处理 
            cin>>str>>m;
            nlen=str.size();
            t=m;mlen=0;
            while(t){t=t/10;mlen++;}
            t=1;n=0;
            for(i=nlen-1;(i>=0&&i>=nlen-8);i--)
            {
                   n+=(str[i]-'0')*t;
                   t*=10;                
            }
            if(nlen>mlen||n>m) {n=m;n--;}
            //计算 
            ans=1;t=1;
            for(i=1;i<=n;i++)
            {
                   t=(t*i)%m;//防止数据溢出 
                   ans=(ans+t)%m;            
            }
            ans%=m;//防止出现m==1出现时n%m==1的情况 
            cout<<ans<<endl;
     } 
     return 0;
}