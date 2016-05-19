#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MAXN (200+10)
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))
#define EPS 0
#define pb push_back
inline int sign(double a) {
    return a<-EPS?-1:a>EPS;
}
struct P
{
    ll x,y;
    P(){}
    P(ll _x,ll _y):x(_x),y(_y){}
    friend ostream& operator<<(ostream& cout,P &a)
    {
        cout<<"("<<a.x<<','<<a.y<<')'<<endl;
        return cout;
    }
    friend bool operator< (P a,P b) {return a.x<b.x|| (a.x == b.x && a.y<b.y);  }
}a[MAXN],p[MAXN];
typedef P Point; 
ll S(P A,P B,P C)
{
    return (A.x-C.x)*(B.y-C.y)-(A.y-C.y)*(B.x-C.x)  ;
}

vector<Point> qs,ps;
vector<Point> convexHull() {
    int n = ps.size();
    if (n<=1)
        return ps;
    sort(ps.begin(),ps.end());
    for (int i=0;i<n;qs.push_back(ps[i++])) {
        while (qs.size()>1 && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
            qs.pop_back();
    }
    for (int i=n-2,t=qs.size();i>=0;qs.push_back(ps[i--])) {
        while ((int)qs.size()>t && crossOp(qs[(int)qs.size()-2],qs.back(),ps[i]) <=0 )
            qs.pop_back();
    }
    qs.pop_back();
    return qs;
}
int n,st[MAXN];
ll f[MAXN][MAXN]={0};
int main()
{
    int T;cin>>T;
    For(kcase,T) {
        int k;
        scanf("%d%d",&n,&k);
        For(i,n) scanf("%lld%lld",&a[i].x,&a[i].y); //scanfè¯»å¥å¤±è´¥è¿å-1 

        ps.clear(); qs.clear();
        For(i,n) ps.pb(P(a[i].x,a[i].y));
        convexHull();

        int siz=qs.size();
        ll ans=0;

        For(i,siz) p[ i + siz ]=p[i] = qs[i-1];

        if (k>siz) {
            ll ans=0;
            For(i,siz) ans+=S(p[i],p[i+1],p[1]);
            printf("Case #%d: %lld\n",kcase,ans);
            continue;

        }

        For(t,n/k+(bool)(n%k)) {
            Fork(i,t,siz+t) {
                Fork(j,3,k+1)
                {
                    f[i][j]=-1;
                    Fork(l,t+1,i-1) 
                    { 
                        f[i][j]=max(f[i][j],f[l][j-1]+S(p[l],p[i],p[t]));
                    }
                }   
            }
            ans=max(ans,f[siz+t][k+1]);
        }
        printf("Case #%d: %lld\n",kcase,ans);

    }
    return 0;
}