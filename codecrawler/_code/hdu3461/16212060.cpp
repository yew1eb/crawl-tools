#include<stdio.h>
#include<math.h>
int set[10000005];
int count;
#define mod 1000000007
int find(int x)
{
    int r=x;
    while(r!=set[r])
    r=set[r];
    int i=x;
    while(i!=r)
    {
        int j=set[i];
        set[i]=r;
        i=j;
    }
    return r;
}
void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        set[fx]=fy;
        count++;
    }
}

long long exp(int n){
    long long sum=1, tmp=26;
    while(n){
        if(n&1){
            sum = sum*tmp;
            sum %= mod;
        }
        tmp = (tmp*tmp)%mod;
        n>>=1;
    }
    return sum;
}
int main()
{
    int n,m,l,r;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        count=0;
        for(int i=0;i<=n;i++)//i=0,éå¨i=1
        set[i]=i;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&l,&r);
            merge(l-1,r);//è¥ææ¯l-1,ä¸è¾¹åå§åå°±ä»0å¼å§ï¼å¦æç¨mergeï¼lï¼r+1ï¼,åå§åiæ¯1å°n+1
        }
        printf("%lld\n",exp(n-count)%mod);
    }
    return 0;
}
/*
1 1
1 1
2 1
1 2
*/
