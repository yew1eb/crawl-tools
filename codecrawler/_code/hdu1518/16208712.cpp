#include"stdio.h"
#include"string.h"


int n;
int len[25];
int hash[25];
int aim;
int ans;


void DFS(int k,int pre,int sum)
{
    int i;
    if(ans)    return ;
    if(k==3)    {ans=1;return ;}


    for(i=pre+1;i<n;i++)
    {
        if(hash[i])            continue;
        if(sum+len[i]>aim)    continue;
        hash[i]=1;
        if(sum+len[i]==aim)    DFS(k+1,-1,0);
        else                DFS(k,i,sum+len[i]);
        if(ans)        return ;
        hash[i]=0;
    }
}


int main()
{
    int T;
    int i;
    int max;
    scanf("%d",&T);
    while(T--)
    {
        aim=0;
        max=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&len[i]);
            aim+=len[i];
            if(len[i]>max)    max=len[i];
        }


        if(aim%4)    {printf("no\n");continue;}
        aim/=4;
        if(max>aim)    {printf("no\n");continue;}


        memset(hash,0,sizeof(hash));


        ans=0;
        DFS(0,-1,0);
        if(ans)    printf("yes\n");
        else    printf("no\n");
    }
    return 0;
}