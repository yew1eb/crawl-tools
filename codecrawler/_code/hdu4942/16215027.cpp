#pragma comment (linker,"/STACK:102400000,102400000")
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 100005
#define LL __int64
#define MOD 1000000007
#define inf 0x7ffffff
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
struct node
{
    int son[2],lr[2];//son[0-1]å·¦å³å¿å­ãlr[0-1]å¨çº¿æ®µæ ä¸­çå·¦å³åºé´
    int w,fa;
    LL val;//æè¶£å¼
}s[N];
int real[N],idx[N];//idx[i] = x è¡¨ç¤ºç¬¬iä¸ªèç¹å¨çº¿æ®µæ ä¸­çä½ç½®ï¼real[i] = xè¡¨ç¤ºçº¿æ®µæ ä¸­çièç¹å¨æ ä¸­çç¼å·  ä¸å®è¦çè§£æ¸æ¥
int temp;
struct node1
{
    int l,r;
    LL mul;
}tree[N<<2];
void mid_dfs(int o)//ä¸­åºéå
{
    s[o].val = s[o].w;
    if(s[o].son[0])
    {
        mid_dfs(s[o].son[0]);
        s[o].val += s[ s[o].son[0] ].val;
        s[o].lr[0] = s[ s[o].son[0] ].lr[0];
    }
    else s[o].lr[0] = temp;
    idx[o] = temp;// ç¬¬oä¸ªæ°å¨çº¿æ®µæ ä¸­æ¯ç¬¬tempä¸ªæ°
    real[temp] = o;
    temp++;
    if(s[o].son[1])
    {
        mid_dfs(s[o].son[1]);
        s[o].val += s[ s[o].son[1] ].val;
        s[o].lr[1] = s[ s[o].son[1] ].lr[1];
    }
    else s[o].lr[1] = temp-1;
    s[o].val %= MOD;
}
void pushUp(int o)
{
    tree[o].mul = tree[2*o].mul*tree[2*o+1].mul%MOD;
}
void build(int o,int l,int r)
{
    tree[o].l = l;
    tree[o].r = r;
    if(l == r)
    {
        tree[o].mul = s[real[l]].val;
        return;
    }
    int m = (l+r)/2;
    build(2*o,l,m);
    build(2*o+1,m+1,r);
    pushUp(o);
}
void update(int o,int pos,LL v)
{
    if(tree[o].l == tree[o].r)
    {
        tree[o].mul = v;
        return;
    }
    int m = (tree[o].l + tree[o].r)/2;
    if(pos <= m) update(2*o,pos,v);
    else update(2*o+1,pos,v);
    pushUp(o);
}
LL query(int o,int x,int y)
{
    if(x <= tree[o].l && tree[o].r <= y)
        return tree[o].mul%MOD;
    LL ans = 1;
    int m = (tree[o].l+tree[o].r)/2;
    if(x <= m) ans = ans*query(2*o,x,y)%MOD;
    if(y > m) ans = ans*query(2*o+1,x,y)%MOD;
    return ans%MOD;
}
void rotation(int op,int o)//op = 0,ä»£è¡¨å³æï¼è¿éæå¾å¤ç»èï¼æ¯æ¬¡æè½¬é½è¦ç»´æ¤æ çä¿¡æ¯ï¼åæ¬å¶å¿å­/ç¶äº²èç¹ï¼å¨çº¿æ®µæ ä¸­å¯¹åºçå·¦å³åºé´ï¼æè¶£å¼
{
    int ss = s[o].son[op];
    if(ss == 0) return;
    int t = s[ss].son[1^op];
    int fa = s[o].fa;
    if(s[fa].son[1] == o) s[fa].son[1] = ss;
    else s[fa].son[0] = ss;
    s[ss].fa = fa;

    s[o].fa = ss;
    s[ss].son[1^op] = o;

    if(t)
    {
         s[t].fa = o;
         s[o].son[op] = t;
         s[o].lr[op] = s[t].lr[op];
    }
    else
    {
        s[o].son[op] = 0;
        s[o].lr[op] = idx[o];
    }
    s[ss].lr[1^op] = s[o].lr[1^op];

    s[ss].val = s[o].val;
    s[o].val = s[o].w;
    if(s[o].son[0]) s[o].val += s[ s[o].son[0] ].val;
    if(s[o].son[1]) s[o].val += s[ s[o].son[1] ].val;
    s[o].val %= MOD;

    update(1,idx[o],s[o].val);
    update(1,idx[ss],s[ss].val);
}
int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int t,ca = 1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        s[1].fa = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d%d",&s[i].w,&s[i].son[0],&s[i].son[1]);
            s[ s[i].son[0] ].fa = s[ s[i].son[1] ].fa = i;
        }
        temp = 1;
        mid_dfs(1);
        build(1,1,n);
        printf("Case #%d:\n",ca++);
        while(m--)
        {
            int p,v;
            scanf("%d%d",&p,&v);
            if(p == 2)
                printf("%I64d\n",query(1,s[v].lr[0],s[v].lr[1]) );
            else rotation(p,v);
        }

    }
    return 0;
}