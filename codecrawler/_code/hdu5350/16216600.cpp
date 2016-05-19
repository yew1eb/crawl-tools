#include<bits/stdc++.h> 
using namespace std;
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
#define INF (2139062143)
#define F (100000007)
#define MAXN (1000000+10)
#define MAXAi (10000+10)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int n;
ll a[MAXN];
priority_queue<ll,vector<ll> , greater<ll> > q;
int main()
{
//    freopen("H.in","r",stdin);
    
    int T;cin>>T;
    while (T--) {
        cin>>n;
        For(i,n) 
        {
            scanf("%lld",&a[i]);q.push(a[i]);
        }
//        
//        if (n==1) {
//            puts("0");continue;
//        }
        ll ans=0;
        while (q.size()>=2)
        {
            ll val=q.top(); q.pop();
            val+=q.top(); q.pop();
            ans+=val;
            q.push(val);
        }
        
        cout<<ans<<endl;
        while (!q.empty()) q.pop();
        
        
    }
    
    return 0;
}
