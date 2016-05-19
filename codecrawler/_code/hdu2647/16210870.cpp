#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MM 10005
using namespace std;
int inde[MM];
int add[MM];  //æ¯äººè¦å çã
struct Node
{
    int data;
    Node *next;
    Node():data(0),next(0){}
}*e[MM];
void addEdage(int u,int v)
{
    Node *t =new Node;
    t->data=v;
    t->next=e[u];
    e[u]=t;
}
void init(int n)
{
    memset(e,0,sizeof(e));
    memset(inde,0,sizeof(inde));
    int i;
    for(i=0;i<=n;i++)
        add[i]=888;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,a,b;
        init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            addEdage(b,a);       //æ³¨ææ¯ååç
            inde[a]++;
        }
        queue<int> q;
        for(i=1;i<=n;i++)
        {
            if(inde[i]==0)
            {
                q.push(i);
            }
        }
        int sum=0;
        int count=0;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            count++;
            sum=sum+add[t];
            Node *hh;
            for(hh=e[t];hh;hh=hh->next)
            {
                if(--inde[hh->data]==0)
                {
                    q.push(hh->data);
                    add[hh->data]=add[t]+1;  //æ³¨æç¹
                }
            }
        }
        if(count!=n)
            printf("-1\n");
        else
            printf("%d\n",sum);
    }
    return 0;
}
