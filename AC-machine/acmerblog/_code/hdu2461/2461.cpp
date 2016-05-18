#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 21
struct node
{
    int c,x1,x2,y1,y2;//c表示是否重合，1重合，0不重合
}co[N],a[1<<N];
int fa[1<<N],b[N];
int f[N+10];
int c[N];
void in()
{
    f[0]=1;
    for(int i=1;i<=20;i++) f[i]=f[i-1]*2;
}
int zhao(int &x,int &y,int x1,int y1,int x2,int y2)
{

    if(x1>x2) swap(x1,x2),swap(y1,y2);
    if(x2>=y1) return 0;
    else
    {
        x=x2;
        y=MIN(y1,y2);
    }
    return 1;
}
void find(int t,int i,int j)
{
    int c1,c2;
    c1=zhao(a[t].x1,a[t].x2,a[i].x1,a[i].x2,co[j].x1,co[j].x2);
    c2=zhao(a[t].y1,a[t].y2,a[i].y1,a[i].y2,co[j].y1,co[j].y2);
    a[t].c=c1&c2;
    j=t;
}
void init(int n)
{
    int i,j;
    a[0].x1=a[0].y1=0;
    a[0].x2=a[0].y2=1000;
    a[0].c=1;
    for(i=1;i<f[n];i++) a[i].c=0;
    memset(fa,0,sizeof(fa));
    for(i=0;i<f[n];i++)
        if(a[i].c)
        {
            for(j=0;j<n;j++)
                if((i&f[j])==0&&fa[i+f[j]]==0)
                {
                    fa[i+f[j]]=1;
                    find(i+f[j],i,j);
                }
        }
}
void dfs(int temp,int x,int n,int num)
{
    for(int i=x;i<n;i++)
    {
        int j=temp+f[b[i]];
        if(a[j].c)
        {
            c[num]+=(a[j].x2-a[j].x1)*(a[j].y2-a[j].y1);
            dfs(j,i+1,n,num+1);
        }
    }
}
int main()
{
    in();
    int cases=1,n,m;
    while(~scanf("%d%d",&n,&m)&&n+m)
    {
        int i,j,r,index;
        for(i=0;i<n;i++)
            scanf("%d%d%d%d",&co[i].x1,&co[i].y1,&co[i].x2,&co[i].y2);
        init(n);//预处理,将所有的情况求出来
        printf("Case %d:\n",cases++);
        for(int k=1;k<=m;k++)
        {
            int sum=0;
            scanf("%d",&r);
            for(i=0;i<r;i++)
            {
                scanf("%d",&b[i]);
                b[i]--;
                sum+=(co[b[i]].x2-co[b[i]].x1)*(co[b[i]].y2-co[b[i]].y1);
            }
            memset(c,0,sizeof(c));
            dfs(0,0,r,1);
            int mul=-1;
            for(i=2;i<=r;i++)
            {
                sum+=c[i]*mul;
                mul*=-1;
            }
            printf("Query %d: %d\n",k,sum);
        }
        printf("\n");
    }
    return 0;
}