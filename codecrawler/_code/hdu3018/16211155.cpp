#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1000000007;
const int inf=0x7fffffff;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
using namespace std;
int n,m,f[110000],v[110000],num[110000];
void init()
{
    for(int i=1;i<=n;i++)
        f[i]=i;
}

int Find(int x)
{
    return x==f[x] ? x :f[x]=Find(f[x]);
}

void Merge(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(x!=y) f[x]=y;
}

int main()
{
   while(~scanf("%d %d",&n,&m)){
        init();
        memset(num,0,sizeof(num));
        memset(v,0,sizeof(v));
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            Merge(a,b);
            num[a]++,num[b]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(num[i]&&num[i]%2){
               ans++;
               if(!v[Find(i)])  v[Find(i)]=1;
            }
        }
        ans/=2;
        for(int i=1;i<=n;i++){
            if(f[i]==i&&!v[i]&&num[i]) ans++;
        }
        cout<<ans<<endl;
    }
}
