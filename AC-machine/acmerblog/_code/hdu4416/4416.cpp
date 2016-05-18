#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
typedef long long LL;
const int N=550005;

struct State
{
    State *pre,*go[26];
    int step,deep;
    void clear()
    {
        pre=0;
        deep=0;
        step=0;
        memset(go,0,sizeof(go));
    }
}*root,*last;

State statePool[N*2],*b[2*N],*cur;

void init()
{
    cur=statePool;
    root=last=cur++;
    root->clear();
}

void Insert(int w)
{
    State *p=last;
    State *np=cur++;
    np->clear();
    np->step=p->step+1;
    while(p&&!p->go[w])
        p->go[w]=np,p=p->pre;
    if(p==0)
        np->pre=root;
    else
    {
        State *q=p->go[w];
        if(p->step+1==q->step)
            np->pre=q;
        else
        {
            State *nq=cur++;
            nq->clear();
            memcpy(nq->go,q->go,sizeof(q->go));
            nq->step=p->step+1;
            nq->pre=q->pre;
            q->pre=nq;
            np->pre=nq;
            while(p&&p->go[w]==q)
                p->go[w]=nq, p=p->pre;
        }
    }
    last=np;
}

char str[N];
int cnt[N];

void Solve(int Q,int n)
{
    memset(cnt,0,sizeof(cnt));
    for(State *p=statePool; p!=cur; p++)
        cnt[p->step]++;
    for(int i=1; i<=n; i++)
        cnt[i]+=cnt[i-1];
    for(State *p=statePool; p!=cur; p++)
        b[--cnt[p->step]]=p;
    while(Q--)
    {
        scanf("%s",str);
        int len=0;
        int m=strlen(str);
        State *p=root;
        for(int i=0; i<m; i++)
        {
            int x=str[i]-'a';
            if(p->go[x])
            {
                len++;
                p=p->go[x];
                p->deep=max(p->deep,len);
            }
            else
            {
                while(p&&!p->go[x]) p=p->pre;
                if(!p) p=root,len=0;
                else
                {
                    len=p->step+1;
                    p=p->go[x];
                    p->deep=max(p->deep,len);
                }
            }
        }
    }
    LL sum=0;
    int num=cur-statePool;
    for(int i=num-1; i>0; i--)
    {
        State *q=b[i];
        if(q->deep>0)
        {
            q->pre->deep=max(q->pre->deep,q->deep);
            if(q->deep<q->step) sum+=q->step-q->deep;
        }
        else sum+=q->step-q->pre->step;
    }
    printf("%I64d\n",sum);
}

int main()
{
    int t,k=1,Q;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",k++);
        scanf("%d",&Q);
        scanf("%s",str);
        int n=strlen(str);
        init();
        for(int i=0; i<n; i++)
            Insert(str[i]-'a');
        Solve(Q,n);
    }
    return 0;
}
