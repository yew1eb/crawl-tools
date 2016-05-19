#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[20],ans[20];
int sum,n,flag;
void dfs(int x,int count,int m)
{
    int i,last;
    if(m>sum)
    return;
    if(m==sum)
    {
        flag=1;
        for(i=1;i<count;i++)
        {
            if(i==count-1)
            printf("%d\n",ans[i]);
            else
            printf("%d+",ans[i]);
        }
    }
    last=-1;
    for(i=x;i<=n;i++)
    {
        if(last!=a[i])
        {
            ans[count]=a[i];
            last=a[i];
            dfs(i+1,count+1,m+a[i]);
        }
    }
    return;
}
int main()
{
    int i;
    while(scanf("%d%d",&sum,&n),sum||n)
    {
           for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
        flag=0;
        printf("Sums of %d:\n",sum);
        dfs(1,1,0);
        if(!flag)
        printf("NONE\n");
    }
    return 0;
}
