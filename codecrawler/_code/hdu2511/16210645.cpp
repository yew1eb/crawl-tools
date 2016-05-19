#include <stdio.h>

__int64 bit[64] = {1};
int flag ;
void dfs(int a,int b,int c,int n,__int64 m)
{
    if(flag)
        return ;
    if(!n)
        return ;
    if(m > bit[n - 1])
        dfs(b,a,c,n-1,m-bit[n-1]);
    else if(m == bit[n-1])
    {
        printf("%d %d %d\n",n,a,c);
        flag = 1;
        return ;
    }
    else
        dfs(a,c,b,n-1,m);
}
int main()
{
    for(int i = 1; i < 64; ++i)
        bit[i] = bit[i - 1] << 1;
    int n,t;
    __int64 m;
    scanf("%d",&t);
    int a = 1, b = 2, c = 3;
    while(t--)
    {

        scanf("%d%I64d",&n,&m);
        flag  = 0;
        dfs(a,b,c,n,m);
    }
    return 0;
}
