#pragma comment (linker,"/stack:102400000,102400000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<functional>
#include<iostream>
#include<string>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
const double PI=acos(-1.0);
#define able puts("0000000000000000000000")
template<class T_T> T_T f_max(T_T a,T_T b)
{
    return a>b?a:b;
}
template<class T_T> T_T f_min(T_T a,T_T b)
{
    return a<b?a:b;
}
template<class T_T> T_T f_abs(T_T a)
{
    return a>0?a:-a;
}
template<class T_T> T_T gcd(T_T a,T_T b)
{
    return b?gcd(b,a%b):a;
}
template<class T_T> void swap(T_T *a,T_T *b)
{
    T_T c;
    c=a;
    a=b;
    b=c;
}
const int N = 100005;
const int inf = 1000000000;
const int mod = 1000000007;
struct node
{
    int l,r,id;
    node(){}
    node(int _l,int _r,int _id):l(_l),r(_r),id(_id){}
    bool operator < (const node &a) const
    {
       return r>a.r;//æå°å¼ä¼å
    }
}s[N];
int v[N];
bool cmp(node x,node y)
{
    if(x.l!=y.l)
        return x.l<y.l;
    return x.r<y.r;
}
int main()
{
    int t,i,j,n,c,k1,k2;
    scanf("%d",&t);
    while(t--)
    {
        memset(v,false,sizeof(v));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i].l);
            s[i].id=i+1;
        }
        for(i=0;i<n;i++)
            scanf("%d",&s[i].r);
        sort(s,s+n,cmp);
        priority_queue<node> q;
        c=0;
        if(s[0].l!=0)
        {
            printf("%d\n",c);
            for(i=1;i<=n;i++)
                printf("%d%c",i,i==n?'\n':' ');
            continue;
        }
        q.push(s[0]);i=1;k1=0;k2=n-1;
        while(!q.empty())
        {
            for(;i<n&&s[i].l==c;i++)
                q.push(s[i]);//printf("%d\n",s[i].id);puts("");
            while(!q.empty())
            {

                if(q.top().r>=c)
                {//printf("q:%d %d\n",q.top().id,q.top().r);
                    v[k1++]=q.top().id;
                    c++;
                    q.pop();
                    break;
                }
                else
                    v[k2--]=q.top().id;
                q.pop();
            }
            for(;i<n&&s[i].l==c;i++)
                q.push(s[i]);//printf("%d\n",s[i].id);puts("");
        }
        for(;i<n;i++)
            v[k2--]=s[i].id;
        printf("%d\n",c);
        for(i=0;i<n;i++)
            printf("%d%c",v[i],i==n-1?'\n':' ');
    }
    return 0;
}