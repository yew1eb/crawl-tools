#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 250001

char text[1010101],val[N];
int P[N],qu[N],son[N][26],size,last[N],cnt[N],len=N-1;

struct Edge
{
    int v,next;
}e[N];

void addedge(int u,int v)
{
    e[++len].v=v;
    e[len].next=last[u];
    last[u]=len;
}

void build(char *s)
{
    int now=0;
    for (int i=0;s[i];i++)
    {
        if (son[now][s[i]-'a']) now=son[now][s[i]-'a'];
        else
        {
            addedge(now,++size);
            val[size]=s[i];
            son[now][s[i]-'a']=size;
            cnt[size]=0;
            now=size;
            for (int j=0;j<26;j++) son[size][j]=0;
        }
        if (s[i+1]==0) cnt[now]++;
    }
}

void kmp()
{
    int head=0,tail=0;
    for (int i=last[0];i!=-1;i=e[i].next)
    {
        P[e[i].v]=0;
        qu[tail++]=e[i].v;
    }
    while (head<tail)
    {
        int v=qu[head++];
        for (int i=last[v];i!=-1;i=e[i].next)
        {
            for (int j=P[v];;j=P[j])
                if (j==0||son[j][val[e[i].v]-'a'])
                {
                    P[e[i].v]=son[j][val[e[i].v]-'a'];
                    break;
                }
            qu[tail++]=e[i].v;
        }
    }
}

void automate()
{
    int ans=0,p=0;
    for (int i=0;text[i];i++)
    {
        p=son[p][text[i]-'a'];
        for (;p;p=P[p])
        {
            if (cnt[p])
            {
                ans+=cnt[p];
                cnt[p]=0;
            }
            if (text[i+1]&&son[p][text[i+1]-'a'])
                break;
        }
    }
    printf("%d\n",ans);
}

int main()
{
    int t,n;
    char s[55];
    scanf("%d",&t);
    while (t--)
    {
        memset(last,-1,sizeof(last[0])*(len+1));
        size=0;P[0]=0;cnt[0]=0;len=0;
        for (int i=0;i<26;i++) son[0][i]=0;
        scanf("%d",&n);gets(s);
        for (int i=1;i<=n;i++)
        {
            gets(s);
            build(s);
        }
        kmp();
        gets(text);
        automate();
    }
    return 0;
}
