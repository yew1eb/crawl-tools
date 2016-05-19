#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef struct
{
    int word,fail;
    int next[26];
}Tree;

char str[1005][55];
char s[2000005];
int up;
Tree tree[1000005];
int ans[1005];
queue <int> q;

void Add(char *str,int k)
{
    int i,j,n,now;
    n=strlen(str);
    now=0;
    for (i=0;i<n;i++)
    {
        if (tree[now].next[str[i]-'A']==-1)
        {
            tree[now].next[str[i]-'A']=up;
            tree[up].word=-1;
            memset(tree[up].next,-1,sizeof(tree[up].next));
            up++;
        }
        now=tree[now].next[str[i]-'A'];
    }
    tree[now].word=k;
}

void BFS()
{
    int i,j,n,tmp,tag,t;
    q.push(0);
    while(!q.empty())
    {
        tag=q.front();
        q.pop();
        for (i=0;i<26;i++)
        {
            if (tree[tag].next[i]==-1) continue;
            t=tree[tag].next[i];
            q.push(t);
            if (tag==0)
            {
                tree[t].fail=0;
                continue;
            }
            tmp=tree[tag].fail;
            while (tree[tmp].next[i]==-1 && tmp!=0)
            {
                tmp=tree[tmp].fail;
            }
            if (tree[tmp].next[i]!=-1)
            {
                tree[t].fail=tree[tmp].next[i];
            }
            else
            {
                tree[t].fail=tmp;
            }
        }
    }
}

void Count(char *str)
{
    int n,i,j,now,tag;
    n=strlen(str);
    now=0;
    for (i=0;i<n;i++)
    {
        if (str[i]>'Z' || str[i]<'A')
        {
            now=0;
            continue;
        }
        while (tree[now].next[str[i]-'A']==-1 && now!=0)
        {
            now=tree[now].fail;
        }
        if (tree[now].next[str[i]-'A']!=-1)
        {
            now=tree[now].next[str[i]-'A'];
        }
        tag=now;
        while(tag!=0)
        {
            if (tree[tag].word!=-1) ans[tree[tag].word]++;
            tag=tree[tag].fail;
        }
    }
}

int main()
{
    int i,j,n;
    char ch;
    while(scanf("%d",&n)!=EOF)
    {
        up=1;
        tree[0].fail=0;
        tree[0].word=-1;
        memset(tree[0].next,-1,sizeof(tree[0].next));
        for (i=0;i<n;i++)
        {
            scanf("%s",str[i]);
            Add(str[i],i);
        }
        BFS();
        ch=getchar();
        gets(s);
        memset(ans,0,sizeof(ans));
        Count(s);
        for (i=0;i<n;i++)
        {
            if (ans[i]==0) continue;
            printf("%s: %d\n",str[i],ans[i]);
        }
    }
    return 0;
}
