#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxx=105;
//degree[]	每个结点的入度
//f[]	每个结点所在的层
int degree[maxx];
int f[maxx];
int map[maxx][maxx];
int top;
int n,m;
bool Toplogical_sort()
{
    int i,j;
    bool p=true;
    top=0;
    int tmp=0;
    while(p)
    {

        p=false;
        top++;
        tmp=-1;
        for(i=0; i<=n-1; i++)
            if(degree[i]==0)
            {
                p=true;
                f[i]=top;
                tmp=i;
                break;
            }
        if(tmp==-1)
            continue;
        for(j=0; j<n; j++)
        {
            if(map[tmp][j])
                degree[j]--;
            degree[tmp]=-1;
        }
    }
    top--;
    if(top<n)
        return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m))
    {
        if(n==0)
        break;
        memset(map,0,sizeof(map));
        memset(f,0,sizeof(f));
        memset(degree,0,sizeof(degree));
        int a,b;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            if(!map[a][b])
            {
                map[a][b]=1;
                degree[b]++;
            }
        }
        if(Toplogical_sort())
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}