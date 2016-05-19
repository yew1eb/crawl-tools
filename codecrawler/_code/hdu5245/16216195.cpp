#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define IFOR(i,h,l,v) for(int i=(h);i<=(l);i+=(v))
#define CLR(vis) memset(vis,0,sizeof(vis))
#define MST(vis,pos) memset(vis,pos,sizeof(vis))
#define MAX3(a,b,c) max(a,max(b,c))
#define MAX4(a,b,c,d) max(max(a,b),max(c,d))
#define MIN3(a,b,c) min(a,min(b,c))
#define MIN4(a,b,c,d) min(min(a,b),min(c,d))
#define PI acos(-1.0)
#define INF 1000000000
#define LINF 1000000000000000000LL
#define eps 1e-8
#define LL long long
using namespace std;

const int maxn = 510;

LL num[maxn][maxn];
LL cnt[maxn][maxn];

int main()
{
    int t,cas=1,k;
    LL n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%d",&n,&m,&k);
        //CLR(num);
        //CLR(cnt);
        /*FOR(i,1,n){
            FOR(j,1,m){
                FOR(p,1,n){
                    FOR(q,1,m){
                        FOR(s,min(i,p),max(i,p))
                            FOR(d,min(j,q),max(j,q))
                                num[s][d]++;
                    }
                }
            }
        }*/
        FOR(i,1,n){
            FOR(j,1,m)
                cnt[i][j]=2*(2*(i*j*(n-i+1)*(m-j+1))-(i*(n-i+1)+j*(m-j+1))+1)-1;
        }
        /*FOR(i,1,n){
            FOR(j,1,m)
                cout<<num[i][j]<<" ";
            cout<<endl;
        }
        FOR(i,1,n){
            FOR(j,1,m)
               if(cnt[i][j]>(LL)n*n*m*m) cout<<cnt[i][j]<<" ";
            cout<<endl;
        }*/
        double ans = 0;
        FOR(i,1,n){
            FOR(j,1,m){
                double p =1.0 - cnt[i][j]*1.0/n/n/m/m;
                ans=ans+1-pow(p,k*1.0);
            }
        }
        //cout<<"ans: "<<ans<<endl;
        printf("Case #%d: %d\n",cas++,(int)(ans+0.5));
    }
    return 0;
}
