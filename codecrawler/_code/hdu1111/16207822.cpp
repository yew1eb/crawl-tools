#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef __int64 LL;
const int maxn=110;
LL xr,xi,br,bi,num;
LL flag,t;
LL ans[maxn];//ä¿å­æä¸¾çai
void dfs(LL rr,LL ii,LL step)
{
    LL x,y,i;
    if (step>100)return;
    if(flag)return;
    if(rr==0&&ii==0)
    {
        flag=1;
        t=step;
        return;
    }
    for(i=0;i*i<num;i++)
    {
    //å¤æ°é¤æ³è¿ç®
        x=(rr-i)*br+ii*bi;
        y=ii*br-(rr-i)*bi;
        ans[step]=i;
        if(x%num==0&&y%num==0)//ä¿è¯æ´é¤
        dfs(x/num,y/num,step+1);
        if(flag)return;
    }
}
int main()
{
    LL T,i;
    scanf("%I64d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d%I64d",&xr,&xi,&br,&bi);
        num=br*br+bi*bi;
        flag=0;
        dfs(xr,xi,0);
        if(!flag)printf("The code cannot be decrypted.\n");
        else
        {
            printf("%I64d",ans[t-1]);
            for(i=t-2;i>=0;i--)
            printf(",%I64d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
/*
1
4 0 2 0
1,0,0
*/