#include <queue>
#include <cstdio>
using namespace std;
struct node
{
    int pos,dis;
    bool operator <(const node t)const
    {
        if(pos!=t.pos) return pos>t.pos;
        return dis>t.dis;
    }
};
int main()
{
    priority_queue<node>q;
    int T,n;
    node t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&t.pos,&t.dis);
            q.push(t);
        }
        bool flag=true;
        while(!q.empty())
        {
            t=q.top();
            q.pop();
            if(flag)
            {
                flag=false;
                t.pos+=t.dis;
                q.push(t);
            }
            else flag=true;
        }
        printf("%d\n",t.pos);
    }
    return 0;
}