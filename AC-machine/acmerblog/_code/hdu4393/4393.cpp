#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
struct node
{
    int f,id;
    bool operator<(const node& b)const
    {
        return (f<b.f)||(f==b.f && id>b.id);
    }
};
priority_queue<node> s[120];
int sec,n;
int main()
{
    scanf("%d",&sec);
    for(int z=1;z<=sec;z++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            node t;int f,d;
            scanf("%d%d",&f,&d);
            t.f=f;
            t.id=i;
            s[d].push(t);
        }

        printf("Case #%d:\n",z);
        for(int i=1;i<=n;i++)
        {
            int maxx=-1,minid=1<<28;int re;
            for(int j=1;j<=100;j++)
            if(!s[j].empty())
            {
                node t=s[j].top();
                if((i-1)*j+t.f>maxx || ((i-1)*j+t.f==maxx && t.id<minid))
                {
                    maxx=(i-1)*j+t.f;
                    re=j;
                    minid=t.id;
                }
            }
            int tem=s[re].top().id;
            if(i==n)printf("%d\n",tem);else printf("%d ",tem);
            s[re].pop();
        }
    }
    return 0;
}
