#include"stdio.h"
#include"string.h"
int set[1011];
int indegree[1011];
struct A
{
    int s,e;
}E[10011];


void build(int n)
{
    int i;
    for(i=1;i<=n;i++)    set[i]=i;
}
int find(int k)
{
    if(set[k]==k)    return k;
    set[k]=find(set[k]);
    return set[k];
}
void Union(int f1,int f2)
{
    set[f2]=f1;
}


int main()
{
    int Case=1;
    int max;
    int k;
    int i;
    int f1,f2;
    int flag,flag2;
    int num;
    int hash[1011];


    while(scanf("%d%d",&E[0].s,&E[0].e),E[0].s>=0||E[0].e>=0)
    {
        if(E[0].s==0&&E[0].e==0)    {printf("Case %d is a tree.\n",Case++);continue;}


        memset(hash,0,sizeof(hash));
        memset(indegree,0,sizeof(indegree));
        indegree[E[0].e]=1;
        hash[E[0].s]=hash[E[0].e]=1;


        max=0;
        if(E[0].s>max)    max=E[0].s;
        if(E[0].e>max)    max=E[0].e;
        k=1;
        while(scanf("%d%d",&E[k].s,&E[k].e),E[k].s!=0||E[k].e!=0)
        {
            if(E[k].s>max)    max=E[k].s;
            if(E[k].e>max)    max=E[k].e;
            indegree[E[k].e]++;
            hash[E[k].s]=hash[E[k].e]=1;
            k++;
        }


        flag=flag2=0;
        for(i=1;i<=max;i++)    if(hash[i]&&indegree[i]>1)    {flag=1;break;}
        for(i=1;i<=max;i++)    if(hash[i]&&indegree[i]==0)    flag2++;
        if(flag||flag2!=1)        {printf("Case %d is not a tree.\n",Case++);continue;}


        build(max);


        for(i=0;i<k;i++)
        {
            f1=find(E[i].s);
            f2=find(E[i].e);
            if(f1!=f2)    Union(f1,f2);
        }


        num=0;
        for(i=1;i<=max;i++)    if(hash[i]==1&&set[i]==i)    num++;
        if(num!=1)    printf("Case %d is not a tree.\n",Case++);
        else        printf("Case %d is a tree.\n",Case++);
    }
    return 0;
}