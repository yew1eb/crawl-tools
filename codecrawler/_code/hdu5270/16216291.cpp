
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll __int64
#define maxn 110000
using namespace std;

vector<ll>q[2];
ll x[maxn],y[maxn];
ll bit[100];
int n;

ll solve()//ææ¦ããè¿ä¸ªå½å¹¶å¤ªåäº
{
    ll ans=0;
    for(ll i=0;i<62;i++)
    {
        ll tot=0;
        q[0].clear();q[1].clear();
        for(ll j=1;j<=n;j++)
            q[(x[j]>>i)&1].push_back(x[j]);
        for(ll j=0;j<q[0].size();j++)
            x[++tot]=q[0][j];
        for(ll j=0;j<q[1].size();j++)
            x[++tot]=q[1][j];
        tot=0;
        q[0].clear();q[1].clear();
        for(ll j=1;j<=n;j++)
            q[(y[j]>>i)&1].push_back(y[j]);
        for(ll j=0;j<q[0].size();j++)
            y[++tot]=q[0][j];
        for(ll j=0;j<q[1].size();j++)
            y[++tot]=q[1][j];
        ll len1=1,len2=1,len3=1;
        ll limit1=1ll<<i;
        ll limit2=1ll<<(i+1);
        ll all=(1ll<<(i+1))-1;///è¿éå 1LL
//        cout<<all<<" all"<<endl;
        ll sum=0;
//        for(int i=1;i<=tot;i++) cout<<x[i]<<" ";
//        cout<<endl;
//        for(int i=1;i<=tot;i++) cout<<(x[i]&all)<<" ";
//        cout<<endl;
//        for(int i=1;i<=tot;i++) cout<<y[i]<<" ";
//        cout<<endl;
        for(ll i=n;i>=1;i--)
        {
            while((((x[i]&all)+(y[len1]&all))<limit1) && (len1<=n)) len1++;//è¿éå¤å å ä¸ªï¼ï¼
            while((((x[i]&all)+(y[len2]&all))<limit2) && (len2<=n)) len2++;
            while(((x[i]&all)+(y[len3]&all)<limit1+limit2) && (len3<=n)) len3++;//cout<<(x[i]&all)<<" "<<(y[len3]&all)<<" "<<len3<<" "<<y[len3]<<" "<<(limit1+limit2)<<endl;
            sum+=n-(len1-1-len2+1+len3-1);
//            cout<<len1<<" "<<len2<<" "<<len3<<endl;
//            cout<<n-(len1-1-len2+1+len3-1)<<endl;
        }
//        cout<<sum<<" sum   "<<i<<endl;
        if(sum&1) ans+=bit[i];
    }
    return ans;
}

int main()
{
//    freopen("1003.txt","r",stdin);
    int cas;
    scanf("%I64d",&cas);
    bit[0]=1;
    for(ll i=1;i<=61;i++)
    bit[i]=bit[i-1]*2;
    for(ll ca=1;ca<=cas;ca++)
    {
        scanf("%I64d",&n);
        for(ll i=1;i<=n;i++)
            scanf("%I64d",&x[i]);
        for(ll i=1;i<=n;i++)
            scanf("%I64d",&y[i]);
//        cout<<solve()<<endl;
       printf("Case #%I64d: %I64d\n",ca,solve()) ;
    }
}
