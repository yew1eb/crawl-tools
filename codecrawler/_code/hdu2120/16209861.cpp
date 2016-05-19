#include <stdio.h>
int fa[1005];
int find(int x)
{
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
bool comb(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)//å¦ææ ¹ç¸ç­å°±æ¯åºç°äºç¯
    return true;
    else
    {
        fa[a]=b;
        return false;
    }
}
void init(int n)
{
    for(int i=0;i<n;i++)
    fa[i]=i;
}
int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        init(n);
        int sum=0;
        for(int i=0;i<k;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if(comb(a,b))
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}