#include<stdio.h>
#define N 10000000
int father[N],num[N];
void initial()/*åå§å*/
{
    int i;
    for(i=1;i<=N;i++)
    {
        father[i]=i;
        num[i]=1;/*å¼å§æ¶æ°éé½ä¸º1ï¼æ ¹èç¹ä¸ºèªå·±*/
    }
}
int find(int x) /*å¯»æ¾æ ¹èç¹*/
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    return father[x];
}
void merge(int a,int b)/*åå¹¶aåb*/
{
    int p=find(a);
    int q=find(b);
    if(p!=q)
    {
        father[p]=q;
        num[q]+=num[p];/*åå¹¶éåä¸­åç´ ä¸ªæ°*/
    }
}
int main()
{
    int n,a,b,i,sum,max;
    while(~scanf("%d",&n))
    {
        if(n==0)
        {
            printf("1\n");
            continue;
        }
        max=0;
        initial(); /*åå§å*/
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>max)
                max=a;
            if(b>max)
                max=b;
            merge(a,b); /*åå¹¶éå*/
        }
        int Max=0;
        for(i=1;i<=max;i++)
            if(num[i]>Max) /*æ¥æ¾æå¤§å¼*/
                Max=num[i];
        printf("%d\n",Max);
    }
    return 0;
}