#include"stdio.h"
struct A
{
    int num;
    int pre;
}set[10000011];   


void build(int n)
{
    int i;
    for(i=1;i<=n;i++)    {set[i].num=1;set[i].pre=i;}
}


int find(int k)
{
    if(set[k].pre==k)    return k;
    set[k].pre=find(set[k].pre);
    return set[k].pre;
}


void Union(int f1,int f2)
{
    set[f1].pre=f2;
    set[f2].num+=set[f1].num;
}


int main()
{
    int n;
    int max;
    int ans;
    int i;
    int x[100011];
    int y[100011];
    int f1,f2;


    while(scanf("%d",&n)!=-1)
    {
        if(n==0)    {printf("1\n");continue;}


        max=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]>max)    max=x[i];
            if(y[i]>max)    max=y[i];
        }


        build(max);


        for(i=1;i<=n;i++)
        {
            f1=find(x[i]);
            f2=find(y[i]);
            if(f1!=f2)    Union(f1,f2);
        }
        
        ans=0;
        for(i=1;i<=max;i++)    if(set[i].num>ans)    ans=set[i].num;


        printf("%d\n",ans);
    }
    return 0;
}