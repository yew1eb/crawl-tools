#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstring> 
using namespace std;
#define LL long long
const int maxn =60;
int a[maxn];
LL to[maxn];
int num[maxn];
LL ans;
bool gcd(int a,int b){
    return b==0?a!=1:gcd(b,a%b);
}
LL DFS(int n,LL p){
    if(n==-1) return 1;
    LL res=DFS(n-1,p);
    if(p&(1LL<<n)) return res;
    if((p|to[n])==p) return res*num[n];
    else return res+DFS(n-1,(p|to[n]))*(num[n]-1);
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        int m=0;
        num[0]=2;
        for(int i=1;i<n;i++){
            if(a[i]==a[m]) num[m]++;
            else { a[++m]=a[i]; num[m]=2; }
        }
        memset(to,0,sizeof(to));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<i;j++)
                if(gcd(a[j],a[i]))
                to[i]|=1LL<<j;
        }
        ans=0;
        printf("%I64d\n",DFS(m,0));
    }
    return 0;
}
