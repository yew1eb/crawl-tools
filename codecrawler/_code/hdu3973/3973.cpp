/**
hdu 3973  线段树单点更新区间求值+字符串hash
题目大意：给定多个字符串，然后给定一个大串，对该串进行单点更新和区间查询，查询的区间子串是不是在已知的字符串中出现
解题思路：对字符串进行hash处理采用线段树来进行更新，用set存放字符串的哈希值。至于怎么哈希和大白书上的思路差不多只是这里是表示的前缀
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
using namespace std;

const int maxn=100010;
const int seed=31;
typedef unsigned long long LL;

struct note
{
    int l,r;
    LL hashes;
}tree[maxn*4];
char str[2000100];
LL Hash[maxn];
int n;

void init()
{
    Hash[0]=1;
    for(int i=1;i<maxn;i++)
    {
        Hash[i]=Hash[i-1]*seed;
    }
}
LL get_hash()
{
    int len=strlen(str);
    LL sum=0;
    for(int i=0;i<len;i++)
         sum=sum*seed+str[i]-'a'+1;
    return sum;
}

void build(int l,int r,int root)
{
    tree[root].l=l;
    tree[root].r=r;
    if(l==r)
    {
        tree[root].hashes=str[l]-'a'+1;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,root<<1);
    build(mid+1,r,root<<1|1);
    tree[root].hashes=tree[root<<1].hashes*Hash[r-mid]+tree[root<<1|1].hashes;
}

void update(int l,int root)
{
    if(tree[root].l==tree[root].r)
    {
        tree[root].hashes=str[l]-'a'+1;
        return;
    }
    int mid=(tree[root].l+tree[root].r)>>1;
    if(l<=mid) update(l,root<<1);
    else  update(l,root<<1|1);
    tree[root].hashes=tree[root<<1].hashes*Hash[tree[root].r-mid]+tree[root<<1|1].hashes;
}

LL query(int l,int r,int root)
{
  //  printf("**\n");
    if(tree[root].l==l&&tree[root].r==r)
        return tree[root].hashes;
    int mid=(tree[root].r+tree[root].l)>>1;
    if(r<=mid)return query(l,r,root<<1);
    else if(l>mid)return query(l,r,root<<1|1);
    return query(l,mid,root<<1)*Hash[r-mid]+query(mid+1,r,root<<1|1);
}
int main()
{
    int T,tt=0;
    init();
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d:\n",++tt);
        scanf("%d",&n);
        set<LL>mp;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            mp.insert(get_hash());
        }
        scanf("%s",str);
        int len=strlen(str);
        build(0,len-1,1);
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            char c[5];
            scanf("%s",c);
            if(c[0]=='C')
            {
                int a;
                char b[10];
                scanf("%d%s",&a,b);
                str[a]=b[0];
                update(a,1);
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                if(mp.find(query(l,r,1))!=mp.end())
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
    }
    return 0;
}
