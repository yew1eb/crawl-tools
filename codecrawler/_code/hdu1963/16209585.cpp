#include<stdio.h>
#define N 1000005
struct nnn
{
    int use,w;
}bond[15];
int dp[N],V;
void complexepack(int use,int w)
{
    for(int v=use;v<=V;v++)
    if(dp[v]<dp[v-use]+w)
    dp[v]=dp[v-use]+w;
}
int main()
{
    int t,y,typ,Max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&Max,&y);
        scanf("%d",&typ);
        for(int i=0;i<typ;i++)
        {
            scanf("%d%d",&bond[i].use,&bond[i].w);
            bond[i].use/=1000;
        }
        while(y--)
        {
            V=Max/1000;
            for(int i=0;i<=V;i++)
                dp[i]=0;
            for(int i=0;i<typ;i++)
            complexepack(bond[i].use,bond[i].w);
            Max=Max+dp[V];
        }
    printf("%d\n",Max);
    }
}
