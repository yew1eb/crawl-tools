#include<stdio.h>
#include<math.h>
#include <queue>
#include<algorithm>
#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int pi,mi;
    bool operator <(const node a)const
    {
        return pi<a.pi;//è¡¨æä¼åçº§é«çå¨æé¡¶ç«¯top
    }
};
int main()
{
    int v;
    while(~scanf("%d",&v)&&v)
    {
        priority_queue <node ,vector<node>,less<node> >q;
        int n;
        scanf("%d",&n);
        while(n--)
        {
            int pi,mi;
            node no;
            scanf("%d%d",&pi,&mi);
            no.pi=pi;no.mi=mi;
            q.push(no);
        }
        int ans=0;
        while(!q.empty()&&v)
        {
            if(q.top().mi<=v)
            {
                ans+=q.top().mi*q.top().pi;
                v-=q.top().mi;
                node no;
                no=q.top();
                q.pop();
            }
            else
            {
                ans+=v*q.top().pi;
                v=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
