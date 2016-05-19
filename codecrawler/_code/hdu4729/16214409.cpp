#pragma comment(linker,"/STACK:124000000,124000000")
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<climits>
#include<map>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define repf(i,n,m) for(int i=(n); i<=(m); ++i)
#define repd(i,n,m) for(int i=(n); i>=(m); --i) 
#define ll __int64
#define arc(a) ((a)*(a))
#define inf 100000
#define exp 0.000001
#define N  200005

class match{
public:
    int n,m,len,topw;
    int fa[N],size[N],son[N],w[N],top[N],dep[N];
    int pre[N],lit[N];
    int value[N];
    int p[N];
    int cont;
    struct node{ int y,pre,v;};
    node a[N];
    struct no{int l,r,Min;};
    no aa[N*4];
    void init()
    {
        len=0; topw=1;value[1]=0;
        memset(pre,-1,sizeof(pre));
        memset(son,-1,sizeof(son));
    }
    void addpage(int x,int y,int z)
    {
        a[len].pre=pre[x];
        a[len].v=z;
        a[len].y=y;
        pre[x]=len++;
    }
    void dfs(int s,int faa,int h)
    {
        dep[s]=h;
        size[s]=1;
        int Max=0,sign;
        for(int i=pre[s]; i!=-1; i=a[i].pre)
        {
            int y=a[i].y;
            if(y==faa) continue;
            fa[y]=s;
            value[y]=a[i].v;//jilu shangyi ge 
            dfs(y,s,h+1);
            if(size[y]>Max) Max=size[y],sign=y;
            size[s]+=size[y];
        }
        if(Max!=0) son[s]=sign;
    }
    void dfs2(int s,int faa,int tp)
    {
        p[topw]=s;
        w[s]=topw++; top[s]=tp;
        if(son[s]!=-1) dfs2(son[s],s,tp);
        for(int i=pre[s]; i!=-1; i=a[i].pre)
        {
            int y=a[i].y;
            if(y==faa || y==son[s]) continue;
            dfs2(y,s,y);
        }
        lit[s]=topw-1;
    }
    void bulidtree(int s,int l,int r)
    {
         aa[s].l=l, aa[s].r=r;
        if(l==r) 
        {
            aa[s].Min=value[p[l]];
            return;
        }
        int mid=(l+r)/2;
        bulidtree(2*s,l,mid);
        bulidtree(2*s+1,mid+1,r);
        aa[s].Min=min(aa[2*s].Min,aa[2*s+1].Min);
    }
    int refresh(int s,int l,int r)
    {
        if(aa[s].l>=l && aa[s].r<=r)
            return aa[s].Min;
        int mid=(aa[s].l+aa[s].r)/2;
        if(r<=mid)
            return refresh(2*s,l,r);
        else if(l>mid) 
            return refresh(2*s+1,l,r);
        else return min(refresh(2*s,l,r),refresh(2*s+1,l,r));
    }
    int deal(int s,int x,int y)
    {
        int fx=top[x],fy=top[y];
        int Min=INT_MAX;
        while(fx!=fy)
        {
            if(dep[fx]>dep[fy])
                swap(fx,fy),swap(x,y);
            Min=min(Min,refresh(1,w[fy],w[y]));
            y=fa[fy],fy=top[y];
        }
        if(dep[x]>dep[y])
            swap(x,y);
        if(x!=y)
        Min=min(Min,refresh(1,w[x]+1,w[y]));
        if(Min==INT_MAX)
            Min=9999;
        return Min;
    }
    bool True(int s,int l,int r,ll mid)
    {
//        cout<<s<<" "<<l<<" "<<r<<" "<<mid<<" "<<cont<<endl;
        if(aa[s].l>=l && aa[s].r<=r && aa[s].Min>=mid)
            return true;
        if(aa[s].l==aa[s].r)
        {
            if(aa[s].Min>=mid) return true;
            cont-=(mid-aa[s].Min);
            if(cont<0) return false;
            return true;
        }
        int mi=(aa[s].l+aa[s].r)/2;
        if(r<=mi) return True(2*s,l,r,mid);
        else if(l>mi) return True(2*s+1,l,r,mid);
        if(True(2*s,l,r,mid) && True(2*s+1,l,r,mid))
            return true;
        return false;
    }
    bool fun(int s,int x,int y,ll mid)
    {
        int fx=top[x],fy=top[y];
        while(fx!=fy)
        {
            if(dep[fx]>dep[fy])
                swap(fx,fy),swap(x,y);
            if(!True(1,w[fy],w[y],mid))
                return false;
            y=fa[fy]; fy=top[y];
        }
        if(dep[x]>dep[y]) swap(x,y);
        if(x!=y)
        if(!True(1,w[x]+1,w[y],mid))
            return false;
        return true;
    }
};
match sa;
int n,m;

int main()
{
//    freopen("in","r",stdin);
    int test;
    scanf("%d",&test);
    repf(ror,1,test)
    {
        scanf("%d%d",&n,&m);
        sa.n=n;
        sa.init();
        int x,y,z,k,c1,c2;
        rep(i,n-1)
        {
            scanf("%d%d%d",&x,&y,&z);
            sa.addpage(x,y,z);
            sa.addpage(y,x,z);
        }
        sa.dfs(1,-1,1);
        sa.dfs2(1,-1,1);
        sa.bulidtree(1,1,n);
        printf("Case #%d:\n",ror);
        repf(i,1,m)
        {
            scanf("%d%d%d%d%d",&x,&y,&k,&c1,&c2);
            ll rr=sa.deal(1,x,y);
            ll an=rr+k/c1;
            ll ans;
            if(c1<=c2)
                ans=an;
            else
            {
            if(k>=c1) an=max(an,rr+1+(k-c1)/c2);
            ll l=an,r=10000+max(k/c2,k/c1);
            ans=an;
            int cont=k/c2;
            sa.cont=cont;
            while(l<=r)
            {
                ll mid=(l+r)/2;
                sa.cont=cont;
                if(sa.fun(1,x,y,mid))
                    ans=mid,l=mid+1;
                else r=mid-1;
            }
            }
            printf("%I64d\n",ans);
        //    cout<<ans<<endl;
        }
    }
   return 0;
}
  