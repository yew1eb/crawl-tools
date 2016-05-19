#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int n;
int num[50005];
int tree[50005][11][11];
int lowbit(int x)
{
    return x&(-x);
}
int update(int mod,int ans,int last,int add)
{
    while(last>0)
    {
        tree[last][mod][ans]+=add;
        last-=lowbit(last);
    }
    //printf("last==%d\n",sign);
    //for(int i=1;i<=10;i++)
    //printf("%d ",tree[i][mod][ans]);
   // printf("~~\n");
}
int solve(int x)
{
    int sum=0;
    int signs=x;
        for(int i=1;i<=10;i++)
        {
            int x=signs;
            while(x<=n)
            {
                sum+=tree[x][i][signs%i];
                x+=lowbit(x);
            }
        }
    return sum;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
        int query;
        scanf("%d",&query);
        while(query--)
        {
            int q;
            scanf("%d",&q);
            if(q==1)
            {
                int left,right,mod,add;
                scanf("%d%d%d%d",&left,&right,&mod,&add);
                update(mod,left%mod,right,add);
                update(mod,left%mod,left-1,-add);
            }
            else
            {
                int x;
                scanf("%d",&x);
                printf("%d\n",solve(x)+num[x]);
            }
        }
    }
}
