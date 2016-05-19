#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 50005
inline int max(int a,int b)
{
    return a>b?a:b;
}
struct multi_treap
{
    struct node
    {
        node* ch[2];
        int v, r, s,id,maxx,dp,maxxid;
        inline int cmp(int x)
        {
            if (x == v) return -1;
            return(x < v ? 0 : 1);
        }
    };
    node *root;
    inline void updata(node* o)
    {
        if (!o) return;
        o->s = 1;
        o->maxx = o->dp;
        o->maxxid = o->id;
        if (o->ch[0])
        {
            o->s += o->ch[0]->s;
            if(o->ch[0]->maxx > o->maxx)
            {
                o->maxx = o->ch[0]->maxx;
                o->maxxid = o->ch[0]->maxxid;
            }
            else if(o->ch[0]->maxx == o->maxx)
            {
                if(o->maxxid > o->ch[0]->maxxid) o->maxxid = o->ch[0]->maxxid;
            }
        }
        if (o->ch[1])
        {
            o->s += o->ch[1]->s;
            if(o->ch[1]->maxx > o->maxx)
            {
                o->maxx = o->ch[1]->maxx;
                o->maxxid = o->ch[1]->maxxid;
            }
            else if(o->ch[1]->maxx == o->maxx)
            {
                if(o->maxxid > o->ch[1]->maxxid) o->maxxid = o->ch[1]->maxxid;
            }
        }
    }
    inline void rateto(node* &o, int d)
    {
        node* k;
        k = o->ch[d ^ 1];
        o->ch[d ^ 1] = k->ch[d];
        k->ch[d] = o;
        updata(o);
        updata(k);
        o = k;
    }
    void add(node* &o, int Y,int DP,int ID)
    {
        if (!o)
        {
            o = (node*)malloc(sizeof(node));
            o->ch[0] = o->ch[1] = 0;
            o->v = Y;
            o->r = rand()*rand();
            o->s = 1;
            o->dp = DP;
            o->id = ID;
            o->maxx  = DP;
            o->maxxid = ID;
            return;
        }
        int d = o->cmp(Y);
        if (d == -1)
        {
            if(DP < o->dp) return;
            if(DP==o->dp)
            {
                if(ID < o->id) o->id=ID;
            }
            else
            {
                o->dp=DP;
                o->id=ID;
            }
            updata(o);
        }
        else
        {
            add(o->ch[d], Y,DP,ID);
            updata(o);
            if (o->r < o->ch[d]->r) rateto(o, d ^ 1);
        }
    }
    void find(node *o,int Y,int &DP,int &ID)
    {
        if(o==NULL) return;
        if(o->v < Y)
        {
            if(o->ch[1]) find(o->ch[1],Y,DP,ID);
            return;
        }
        else
        {
            if(o->dp > DP)
            {
                DP=o->dp;
                ID=o->id;
            }
            else if(o->dp == DP)
            {
                if(o->id < ID) ID = o->id;
            }
            if(o->ch[1])
            {
                if(o->ch[1]->maxx > DP)
                {
                    DP=o->ch[1]->maxx;
                    ID=o->ch[1]->maxxid;
                }
                else if(o->ch[1]->maxx == DP)
                {
                    if(o->ch[1]->maxxid < ID) ID = o->ch[1]->maxxid;
                }
            }
            if(o->ch[0]) find(o->ch[0],Y,DP,ID);
        }
    }
    void mymemory(node * &o)
    {
        if(o)
        {
            mymemory(o->ch[0]);
            mymemory(o->ch[1]);
            free(o);
            o=NULL;
        }
    }
    inline void insert(int Y,int DP,int ID)
    {
        add(root,Y,DP,ID);
    }
    inline void clear()
    {
        mymemory(root);
    }
    inline void get(int Y,int &DP,int &ID)
    {
        find(root,Y,DP,ID);
    }
    multi_treap()
    {
        root = 0;
    }
};
multi_treap s[maxn];
int sx;
void inline init()
{
    for(int i=1; i<=sx; i++) s[i].clear();
}
inline int lowbit(int X)
{
    return X&-X;
}
inline void add(int pos,int Y,int DP,int ID)
{
    while(pos<=sx)
    {
        s[pos].insert(Y,DP,ID);
        pos+=lowbit(pos);
    }
}
inline void que(int pos,int Y,int &DP,int &ID)
{
    while(pos>0)
    {
        s[pos].get(Y,DP,ID);
        pos-=lowbit(pos);
    }
}
int dp[maxn],pre[maxn],a[maxn],b[maxn],x[maxn],y[maxn];
inline int getint()
{
    int c;
    while (c = getchar(), c<'0' || '9'<c);
    int res = c - 48;
    while (c = getchar(), '0' <= c&&c <= '9') res = (res << 3) + res + res + c - 48;
    return res;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            x[i]=a[i]=getint();
        }
        for(int i=1; i<=n; i++)
        {
            y[i]=b[i]=getint();
        }
        std::sort(a+1,a+1+n);
        sx=std::unique(a+1,a+1+n)-a-1;
        std::sort(b+1,b+1+n);
        int sy=std::unique(b+1,b+1+n)-b-1;
        for(int i=1; i<=n; i++) x[i]=std::lower_bound(a+1,a+1+sx,x[i])-a;
        for(int i=1; i<=n; i++) y[i]=std::lower_bound(b+1,b+1+sy,y[i])-b;
        memset(dp,0,sizeof(dp));
        memset(pre,0x7F,sizeof(pre));
        init();
        int ans=0,id;
        for(int i=n; i>=1; i--)
        {
            int Y=y[i],ID=0x7F7F7F7F,DP=0;
            que(x[i],Y,DP,ID);
            pre[i]=ID;
            dp[i]=DP+1;
            add(x[i],Y,dp[i],i);
            if(dp[i]>=ans)
            {
                ans=dp[i];
                id=i;
            }
        }
        printf("%d\n",ans);
        while(id!=0x7F7F7F7F)
        {
            printf("%d",id);
            id=pre[id];
            if(id!=0x7F7F7F7F) putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
