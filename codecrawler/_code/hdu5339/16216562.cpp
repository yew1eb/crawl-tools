#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int n,m;
int num[25];
int v[25];
int minn ;

int cmp(const void *a,const void *b)
{
    return *(int*)b - *(int*)a;
}

void DFS(int cnt,int aa)
{
    if(aa == 0)
    {
        minn = min(minn,cnt);
    }
    if(cnt >n ||aa<num[n-1])
    {
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(v[i] == 0 && aa>=num[i])
        {
            v[i] = 1;
            DFS(cnt+1,aa%num[i]);
            v[i] = 0;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        minn = 999999;
        memset(v,0,sizeof(v));
        qsort(num,n,sizeof(num[0]),cmp);
        DFS(0,m);
        if(minn == 999999)
        {
            printf("-1\n");
        }
        else
        {
             printf("%d\n",minn);
        }

    }
    return 0;
}