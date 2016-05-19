#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#define inf 1000000000
#define pi acos(-1.0)
#define eps 1e-8
#define seed 131
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int maxn=100005;
char s[50];
int d[50];
int n;
struct Node
{
    bool flag;
    int len;
    ll p;
    int w;
    bool operator<(const Node& u)const
    {
        if(len==u.len)
        {
            if(p==u.p)
                return w>u.w;
            return p<u.p;
        }
        return len<u.len;
    }
};
Node vec[2500000];
int num;
char t1[50],t2[50];
int w1,w2;
int len1,len2;
void dfs1(int u)
{
    if(u==n+1)
    {
        vec[num].flag=1;
        vec[num].len=len2-len1;
        vec[num].w=w1-w2;
        ll m=0;
        for(int i=len1;i<len2;i++)
        {
            if(t2[i]=='a')
                m=m*10+1;
            else
                m=m*10;
        }
        vec[num++].p=m;
        if(len1==len2)
        {
            vec[num].flag=1;
            vec[num].len=len2-len1;
            vec[num].w=w2-w1;
            vec[num++].p=m;
        }
        return;
    }
   if(len1<len2&&s[u]==t2[len1])
   {
        t1[len1++]=s[u];
        w1+=d[u];
        dfs1(u+1);
        len1--;
        w1-=d[u];
    }

    t2[len2++]=s[u];
    w2+=d[u];
    dfs1(u+1);
    len2--;
    w2-=d[u];

    if(len1==len2)
    {
        t2[len2++]=s[u];
        swap(w1,w2);
        w2+=d[u];
        dfs1(u+1);
        len2--;
        w2-=d[u];
        swap(w1,w2);
    }
}
void dfs2(int u)
{
    if(u==2*n+1)
    {
        vec[num].flag=0;
        vec[num].len=len1-len2;
        ll m=0;
        for(int i=len1-1;i>=len2;i--)
        {
            if(t1[i]=='a')
                m=m*10+1;
            else
                m=m*10;
        }
        vec[num].p=m;
        vec[num++].w=w2-w1;
        if(len1==len2)
        {
            vec[num].flag=0;
            vec[num].len=len1-len2;
            vec[num].p=m;
            vec[num++].w=w1-w2;
        }
        return;
    }
    t1[len1++]=s[u];
    w1+=d[u];
    dfs2(u+1);
    len1--;
    w1-=d[u];

    if(len1==len2)
    {
        t1[len1++]=s[u];
        swap(w1,w2);
        w1+=d[u];
        dfs2(u+1);
        len1--;
        w1-=d[u];
        swap(w1,w2);
    }

    if(len2<len1&&s[u]==t1[len2])
    {
        t2[len2++]=s[u];
        w2+=d[u];
        dfs2(u+1);
        len2--;
        w2-=d[u];
    }
}
int main()
{
    int a,b;
    while(~scanf("%d",&n)&&n)
    {
        a=0;b=0;
        scanf("%s",s+1);
        for(int i=1;i<=2*n;i++)
        {
            if(s[i]=='a')
                a++;
            if(s[i]=='b')
                b++;
        }
        for(int i=1;i<=n*2;i++)
            scanf("%d",&d[i]);
        if((a&1)||(b&1))
        {
            printf("-1\n");
            continue;
        }
        for(int i=n+1,j=2*n;i<j;i++,j--)
        {
            swap(s[i],s[j]);
            swap(d[i],d[j]);
        }
        if(a%2!=0||b%2!=0)
        {
            printf("-1\n");
            continue;
        }
        w1=w2=0;
        num=0;
        len1=len2=0;
        dfs1(1);
        w1=w2=0;
        len1=len2=0;
        dfs2(n+1);
        sort(vec,vec+num);
        int ans=inf;
        int p=-1,q=-1;
        for(int i=0;i<num;i++)
        {
            if(vec[i].flag==1)
            {
                p=i;
                if(i-1>=0&&(vec[i].p!=vec[i-1].p||vec[i].len!=vec[i-1].len))
                    q=-1;
            }
            if(vec[i].flag==0)
            {
                q=i;
                if(i-1>=0&&(vec[i].p!=vec[i-1].p||vec[i].len!=vec[i-1].len))
                    p=-1;
            }
            if(p==-1||q==-1)
                continue;
            ans=min(ans,abs(vec[p].w-vec[q].w));
        }
        if(ans==inf)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}