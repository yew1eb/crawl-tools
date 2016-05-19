#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long LL;
#define rt return
#define MOD 998244353
#define eps 1e-3
#define N 30
LL n,m,x,y;
LL mapt[30][30];
LL maptt[30][30];
LL dp[100000][30];
LL tt[30];
LL sum[100000];
const LL d[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
LL multi(LL a,LL b)
{
    LL tot = 1;
    while(b)
    {
        if(b&1) tot=(tot*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return tot;
}
int sig(long double x){return (x>eps)-(x<-eps);}
struct Mat{
    LL n,m;
    long double mat[N][N];
    LL b[N];
    void clear(){memset(mat,0,sizeof mat);n = 0;m=0;}
    void output(){for(int i =0;i<n;i++){for(int j = 0;j<m;j++)cout<<mat[i][j]<<" ";cout<<endl;}}
    void setMat(LL n,LL m,LL d[30][30])
    {
        this->n = n;
        this->m = m;
        for(LL i = 0;i<n;i++)
            for(LL j = 0;j<m;j++)
                mat[i][j] = d[i][j];
    }
    long double det(LL n)//è¡åå¼æ±å¼
    {
        for(LL i = 0;i<n;i++) b[i] = i;
        for(LL k=0;k<n;k++)
        {
            LL v = k;
            long double maxx = 0.0;
            for(LL i = k+1;i<n;i++)
                if(fabs(mat[b[i]][k])>maxx){maxx=fabs(mat[b[i]][k]);v= i;}
            if(sig(maxx)==0) continue;
            swap(b[k],b[v]);
            v = b[k];
            for(LL i=k+1;i<n;i++)
            {
                LL u = b[i];
                long double f=mat[u][k] / mat[v][k];
                for(LL j = k+1;j<n;j++)mat[u][j]-=f*mat[v][j];
            }
        }
        long double ans = 1;
        for(LL i = 0;i<n;i++) ans*=mat[b[i]][i];
        return fabs(ans);
    }
}a;
LL getCount(LL k){LL cnt = 0;while(k) {cnt+=k&1;k/=2;}rt cnt;}
LL pos(LL k){LL cnt = 1;while(k%2==0){cnt++;k/=2;} rt cnt;}
void input()
{
    memset(mapt,0,sizeof mapt);
    for(LL i = 0;i<m;i++)
         {
             scanf("%lld%lld",&x,&y);
             mapt[x][y]++;
             mapt[y][x]++;
         }
}
inline void calcCircles()
{
    memset(dp,0,sizeof dp);
    memset(sum,0,sizeof sum);
    LL tot = 0;
    for(LL i = 1;i<d[n];i++)
    {
        LL cnt = getCount(i);
        LL p = pos(i);
        if(cnt == 1) dp[i][p] = 1;
            for(LL j = 1;j<=n;j++)
            if(i&d[j-1])
            {
                for(LL l=p+1;l<=n;l++)
                    if(mapt[j][l] && (d[l-1]&i) == 0)
                        dp[i+d[l-1]][l]=(dp[i+d[l-1]][l]+dp[i][j])%MOD;
                if(cnt>=3 && mapt[j][p])
                    sum[i]=(sum[i]+dp[i][j])%MOD;
            }
    }
}
inline void solve()
{
    LL ans;
    ans = 0;
    for(LL i = 1;i<d[n];i++)
    if(sum[i])
        {
            LL cnt = getCount(i);
            a.clear();
            memset(maptt,0,sizeof maptt);
            memset(tt,0,sizeof tt);
            LL p = 0;
            for(LL j =1;j<=n;j++)
                if(i&d[j-1])tt[j] = n-cnt;
                else tt[j] = p++;
            for(LL j = 1;j<=n;j++)
                for(LL l=1;l<=n;l++)
                        if(tt[j]!=tt[l] && mapt[j][l])
                            {
                                maptt[tt[j]][tt[l]]--;
                                maptt[tt[j]][tt[j]]++;
                            }
            a.setMat(n-cnt+1,n-cnt+1,maptt);
            long double t = a.det(n-cnt);
            LL tmp = (LL)(t + eps ) % MOD;
            ans = (ans + sum[i] * tmp)%MOD;
        }
        ans  = (ans * multi(2,MOD-2))%MOD;
        printf("%lld\n",ans);
}
int main()
{
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
         input();
         calcCircles();
         solve();
    }
    return 0;
}
