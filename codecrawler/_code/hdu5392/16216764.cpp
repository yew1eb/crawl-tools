//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<stdio.h>
#include<math.h>
#include <string>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define eps 1e-8
#define inf 0x3f3f3f3f
#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d%d",&x,&y)
#define ll long long int
//#define mod 258280327
#define maxn 3000005
#define maxm 500010
int t,n;
int f[maxn],v[maxn],num[maxn];
int maxx(int a,int b){
    return a>b?a:b;
}
int main()
{
    rd(t);
    long long mod=3221225473;
    while(t--){
        rd(n);
        for(int i=1;i<=n;i++)
        {
            rd(f[i]);
            v[i]=0;
            num[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(!v[i]){
                int l=0;
                int k=i;
                while(!v[k]){
                    l++;
                    v[k]=1;
                    k=f[k];
                }//æ±å¾ªç¯èé¿åº¦
                for(int j=2;j*j<=l;j++)//è´¨å å­åè§£
                {
                    int nn=0;
                    while(l%j==0) {nn++;l/=j;}
                    num[j]=maxx(num[j],nn);
                }
                if(l>1) num[l]=maxx(1,num[l]);
            }
        }
        ll res=1;
        for(int i=2;i<=n;i++)
        {
            while(num[i]--) res=(res*i)%mod;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
