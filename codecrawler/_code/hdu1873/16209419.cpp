#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"queue"
using namespace std;
int tot;
struct node
{
    int pri;
    int num;
    friend bool operator<(node n1,node n2)
    {
        if(n1.pri==n2.pri)    return n2.num<n1.num;
        else                return n1.pri<n2.pri;
    }
};
int main()
{
    int n;
    node now;
    int a,b;
    char str[20];
    while(scanf("%d",&n)!=-1)
    {
        priority_queue<node>q[4];
        tot=0;
        while(n--)
        {
            scanf("%s",str);
            if(strcmp(str,"OUT")==0)
            {
                scanf("%d",&a);
                if(q[a].empty())    printf("EMPTY\n");
                else
                {
                    now=q[a].top();
                    q[a].pop();
                    printf("%d\n",now.num);
                }
            }
            else if(strcmp(str,"IN")==0)
            {
                scanf("%d%d",&a,&b);
                now.num=++tot;
                now.pri=b;
                q[a].push(now);
            }
        }
    }
    return 0;
}