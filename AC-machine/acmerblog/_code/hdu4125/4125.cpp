#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
const int maxn = 600002;
const int maxm = 7002;
struct P
{
    int k,a;
    bool operator < (const P &other) const
    {
        return k < other.k;
    }
}mole[maxn];
struct T
{
    int l,r,fa;
}tree[maxn];
int next[maxm],stack[maxn],state[maxn];
char str[maxm],list[maxn * 3];
int n,tot,top;

void init()
{
    memset(tree,0,sizeof(tree));
    memset(state,0,sizeof(state));
    tot = top = 0;
    return;
}

void read()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&mole[i].k);
        mole[i].a = i;
    }
    sort(mole + 1 , mole + n + 1);
    scanf("%s",str);
    return;
}

void rotate(int x)
{
    int p = tree[x].fa;
    int l = tree[x].l;
    if(p == tree[tree[p].fa].l)
    {
        tree[tree[p].fa].l = x;
    }
    else
    {
        tree[tree[p].fa].r = x;
    }
    tree[x].fa = tree[p].fa;
    tree[x].l = p;
    tree[p].fa = x;
    tree[p].r = l;
    if(l) tree[l].fa = p;
    return;
}

void dfs(int st)
{
    stack[top++] = st;
    while(top)
    {
        int cur = stack[top-1];
        list[tot++] = (mole[cur].k & 1) + '0';
        if(++state[cur] == 3)
        {
            top--;
            continue;
        }
        if(state[cur] == 1)
        {
            if(tree[cur].l) stack[top++] = tree[cur].l;
            else state[cur]++;
        }
        if(state[cur] == 2)
        {
            if(tree[cur].r) stack[top++] = tree[cur].r;
            else state[cur]++;
        }
        if(state[cur] == 3) top--;
    }
    return;
}

void make()
{
    tree[0].r = 1;
    int rightmost = 1;
    for(int i=2;i<=n;i++)
    {
        tree[rightmost].r = i;
        tree[i].fa = rightmost;
        rightmost = i;
        while(tree[i].fa && mole[i].a < mole[tree[i].fa].a) rotate(i);
    }
    dfs(tree[0].r);
    list[tot] = '\0';
    return;
}

void getnext(char *s)
{
    int len=strlen(s);
    for(int i=0;i<=len;i++)
    {
        next[i] = 0;
    }
    next[0] = -1;
    int j=-1;
    for(int i=0;i<len;)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
    return;
}

int kmp(char a[],char b[])
{
    int count=0;
    getnext(b);
    int lena = strlen(a);
    int lenb = strlen(b);
    int j=0,i=0;
    while(i<lena && j<lenb)
    {
        if(j==-1 || b[j]==a[i])
        {
            j++;
            i++;
        }
        else j=next[j];
        if(j == lenb)
        {
            count++;
            j = next[j];
        }
    }
    return count;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=1;i<=cas;i++)
    {
        printf("Case #%d: ",i);
        init();
        read();
        make();
        printf("%d\n",kmp(list,str));
    }
    return 0;
}