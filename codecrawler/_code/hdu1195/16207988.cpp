#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define BUG printf("here!\n")
using namespace std;
int q1[10005],q2[10005];
int vis[10005];
int front1,front2,tail1,tail2;
int num[5];
int num1[5];
int d[10005];
void tochar(int x)
{
    num[0]=x/1000;
    num[1]=x%1000/100;
    num[2]=x%100/10;
    num[3]=x%10;
}
int toint(int *num)
{
    return num[0]*1000+num[1]*100+num[2]*10+num[3];
}
int bfs(int start,int end)
{
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    q1[0]=start;
    q2[0]=end;
    front1=front2=0;
    tail1=tail2=1;
    vis[start]=1;
    vis[end]=2;
    while(front1<tail1||front2<tail2)
    {
        int tmp=tail1;
        for(;front1<tmp;front1++)
        {
            int x=q1[front1];
            tochar(x);
            int i;
            for(i=0;i<4;i++)
            {
                num1[0]=num[0];
                num1[1]=num[1];
                num1[2]=num[2];
                num1[3]=num[3];
                num1[i]=num[i]+1;
                if(num1[i]==10)
                    num1[i]=1;
                int ans=toint(num1);
                if(vis[ans]==0)
                {
                    vis[ans]=1;
                    d[ans]=d[x]+1;
                    q1[tail1++]=ans;
                }
                else if(vis[ans]==2)
                {
                    return d[ans]+d[x]+1;
                }
                num1[i]=num[i]-1;
                if(num1[i]==0)
                    num1[i]=9;
                ans=toint(num1);
                if(vis[ans]==0)
                {
                    vis[ans]=1;
                    d[ans]=d[x]+1;
                    q1[tail1++]=ans;
                }
                else if(vis[ans]==2)
                {
                    return d[ans]+d[x]+1;
                }
            }

            for(i=0;i<3;i++)
            {
                num1[0]=num[0];
                num1[1]=num[1];
                num1[2]=num[2];
                num1[3]=num[3];
                int o=num1[i];
                num1[i]=num1[i+1];
                num1[i+1]=o;
                int ans=toint(num1);
                if(vis[ans]==0)
                {
                    vis[ans]=1;
                    d[ans]=d[x]+1;
                    q1[tail1++]=ans;
                }
                else if(vis[ans]==2)
                {
                    return d[ans]+d[x]+1;
                }
            }
        }
        tmp=tail2;
        for(;front2<tmp;front2++)
        {
            int x=q2[front2];
            tochar(x);
            int i;
            for(i=0;i<4;i++)
            {
                num1[0]=num[0];
                num1[1]=num[1];
                num1[2]=num[2];
                num1[3]=num[3];
                num1[i]=num[i]+1;
                if(num1[i]==10)
                    num1[i]=1;
                int ans=toint(num1);
                if(vis[ans]==0)
                {
                    vis[ans]=2;
                    d[ans]=d[x]+1;
                    q2[tail2++]=ans;
                }
                else if(vis[ans]==1)
                {
                    return d[ans]+d[x]+1;
                }
                num1[i]=num[i]-1;
                if(num1[i]==0)
                    num1[i]=9;
                ans=toint(num1);
                if(vis[ans]==0)
                {
                    vis[ans]=2;
                    d[ans]=d[x]+1;
                    q2[tail2++]=ans;
                }
                else if(vis[ans]==1)
                {
                    return d[ans]+d[x]+1;
                }
            }

            for(i=0;i<3;i++)
            {
                num1[0]=num[0];
                num1[1]=num[1];
                num1[2]=num[2];
                num1[3]=num[3];
                int o=num1[i];
                num1[i]=num1[i+1];
                num1[i+1]=o;
                int ans=toint(num1);
                if(vis[ans]==0)
                {
                    vis[ans]=2;
                    d[ans]=d[x]+1;
                    q2[tail2++]=ans;
                }
                else if(vis[ans]==1)
                {
                    return d[ans]+d[x]+1;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int t1,t2;
        scanf("%d",&t1);
        scanf("%d",&t2);
        int res=bfs(t1,t2);
        printf("%d\n",res);
    }
    return 0;
}
