#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef unsigned long long ll;
const int maxn=(int)1e5+5;
int n;
ll a[maxn],b[maxn],c[maxn];

void merge (ll *p,ll mod) {   //å¨ç»å®çmodä¸å½å¹¶æåº
    int i,j,k,m;
    for(i=1;i<=n;i++) {
        c[i]=p[i];
        if(p[i]>=mod)
            break;
    }
    m=j=i;
    for(i=j;i<=n;i++)
        c[i]=p[i]%mod;
    i=1;c[n+1]=mod<<1;
    for(k=1;k<=n;k++) {
        if(c[i]<c[j]&&i<m) p[k]=c[i++];
        else p[k]=c[j++];
    }
}

ll bigthan (ll m) {             //å¤§äºmçæ°å¯¹å¯¹æ°
    int i,j=n;ll ans=0;
    for (i=1;i<=n;i++) {
        while ((a[i]+b[j])>=m&&j>0) j--;
        ans+=n-j;
    }
    return ans;
}

bool get (ll mod) {               //èèmodä½æ¯å¦ä¸º1
    merge (a,mod<<1);
    merge (b,mod<<1);
    ll ans = bigthan(mod) + bigthan(3*mod) - bigthan(mod<<1);
    if ( ans%2 ) return true;
    return false;
}

int main () 
{
//    freopen("aa.txt","r",stdin);
    int cas,T,i;ll mod,ans;
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++) {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%I64d",a+i);
        for(i=1;i<=n;i++) scanf("%I64d",b+i);
        sort(a+1,a+n+1);sort(b+1,b+n+1);
        ans=0;mod=(ll)1<<61;
        while(mod) {
            if (get(mod)) 
                ans+=mod;
            mod=mod>>1;
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}