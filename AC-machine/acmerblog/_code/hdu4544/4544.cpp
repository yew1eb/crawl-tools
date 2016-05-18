#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100005
#include<queue>
struct node
{
    int d;
    int p;
    friend bool operator<(node c,node d)
    {
        return c.p>d.p;
    }
}b[N];
int a[N];
int cmp(int a,int b)
{
    return a>b;
}
int cmp1(struct node a,struct node b)
{
    return a.d>b.d;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        priority_queue<node> q;//定义注意类型是node
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
        scanf("%d",&b[i].d);
        for(int i=1;i<=m;i++)
        scanf("%d",&b[i].p);
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+m+1,cmp1);
        int res=1;
        long long ans=0;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            while(res<=m&&b[res].d>=a[i])
            {
                q.push(b[res]);
                //printf("&&&%d\n",q.top().p);
                res++;
            }
            if(q.empty())
            {
                flag=1;
                break;
            }
            else
            {
                ans+=q.top().p;
                q.pop();
            }
        }
        if(flag==1)
        printf("No\n");
        else
        cout<<ans<<endl;
        //printf("%lld\n",ans);此题不知道为什么只能用cout输出，这样写wrong了一遍
    }
    return 0;
}
