#include <bits/stdc++.h>
#define lson num<<1
#define rson num<<1|1
#define gl l,m,lson
#define gr m+1,r,rson
#define PARA int l=1,int r=n,int num=1
using namespace std;
const int MAXN = 2e5+100;

template <class T>
inline bool scan_d(T &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'||c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}

int n;
struct SegTree
{
    struct Node
    {
        long long v,vl,vr;
        int add;
        void mark(long long l,long long r,long long x)
        {
            add+=x;
            v+=(r-l+1)*x;
            vl+=(((l+r)*(r-l+1))/2)*x;
            r=n-r+1;
            l=n-l+1;
            swap(l,r);
            vr+=(((l+r)*(r-l+1))/2)*x;
        }
    }st[MAXN<<3];

    void init()
    {
        memset(st,0,sizeof(st));
    }

    void pushUp(int num)
    {
        st[num].v=st[lson].v+st[rson].v;
        st[num].vl=st[lson].vl+st[rson].vl;
        st[num].vr=st[lson].vr+st[rson].vr;
    }

    void pushDown(int l,int r,int num)
    {
        int &v=st[num].add;
        int m=l+r>>1;
        if(l!=r)
        {
            st[lson].mark(l,m,v);
            st[rson].mark(m+1,r,v);
            pushUp(num);
        }
        v=0;
    }
    void update(int a,int b,PARA)
    {
        int m=l+r>>1;
        pushDown(l,r,num);
        if(a<=l&&r<=b)
            st[num].mark(l,r,1);
        else
        {
            if(b<=m)
                update(a,b,gl);
            else if(a>m)
                update(a,b,gr);
            else
                update(a,b,gl),update(a,b,gr);
            pushUp(num);
        }
    }
    long long ret[3];
    void query(int a,int b,PARA)
    {
        int m=l+r>>1;
        pushDown(l,r,num);
        if(a<=l&&r<=b)
            ret[0]+=st[num].v,ret[1]+=st[num].vl,ret[2]+=st[num].vr;
        else
        {
            if(b<=m)
                query(a,b,gl);
            else if(a>m)
                query(a,b,gr);
            else
                query(a,b,gl),query(a,b,gr);
            pushUp(num);
        }
    }

    long long count(long long d,long long len,long long s)
    {
        /**
        æ¨åºçå¬å¼
        */
        long long v=0;
        memset(ret,0,sizeof(ret));
        query(s,s+d);
        v+=ret[1]-ret[0]*(s-1);

        memset(ret,0,sizeof(ret));
        query(s+len-d-1,s+len-1);
        v+=ret[2]-ret[0]*(n-s-len+1);

        memset(ret,0,sizeof(ret));
        query(s+len-d-1,s+d);
        v-=ret[0]*(d+1);
        return v;
    }
}soul[2];
/**
0: /
1: \
*/

int main()
{
    int T,m,on,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scan_d(on);
        scan_d(m);
        n=2*on-1;
        soul[0].init();
        soul[1].init();
        printf("Case #%d:\n",cas++);
        while(m--)
        {
            int a,x1,x2,y1,y2;
            scan_d(a);
            scan_d(x1);
            scan_d(x2);
            if(a==1)
                soul[0].update(x1-1,x2-1);
            else if(a==2)
                soul[1].update(x1+on,x2+on);
            else
            {
                scan_d(y1);
                scan_d(y2);
                int d=max(x2-x1,y2-y1);
                int len=x2-x1+y2-y1+1;
                printf("%lld\n",soul[0].count(d,len,x1+y1-1)+soul[1].count(d,len,x1-y2+on));
            }
        }
    }
    return 0;
}
