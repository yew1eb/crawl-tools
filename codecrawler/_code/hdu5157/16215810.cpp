#include<iostream>
#include<cstring>
#include<cstdio>
#include<ostream>
#include<istream>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define inf (1<<30)
#define eps 1e-8
#define pb push_back
using namespace std;
const int maxn=110005;
char str[maxn];
char s[maxn*2];
int p[maxn*2];
ll sum[maxn];
ll tot[maxn];
int n;
int cnt;
void pre()
{
    n=strlen(str+1);
    s[0]='$';
    s[1]='#';
    for(int i=1;i<=n;i++) {
        s[i*2]=str[i];
        s[i*2+1]='#';
    }
    cnt=n*2+2;
}
void manacher()
{
    int mx=0;
    int id;
    for(int i=1;i<cnt;i++) {
        if(mx>i)
            p[i]=min(p[2*id-i],mx-i);
        else
            p[i]=1;
        for(;s[i-p[i]]==s[i+p[i]];p[i]++){}
        if(p[i]+i>mx) {
            mx=p[i]+i;
            id=i;
        }
    }
}
int main()
{
    while(~scanf("%s",str+1)) {
        pre();
        manacher();
        memset(sum,0,sizeof(sum));
        memset(tot,0,sizeof(tot));
        for(int i=1;i<=n;i++) {
            int r=p[i*2]/2;
            sum[i]++; sum[i-r]--;
            r=p[i*2+1]/2;
            sum[i]++; sum[i-r]--;
        }
        for(int i=n;i>=1;i--)
            sum[i]=sum[i+1]+sum[i];
        for(int i=n;i>=1;i--)
            sum[i]=sum[i+1]+sum[i];
        for(int i=1;i<=n;i++) {
            int r=p[i*2]/2;
            tot[i+1]++; tot[i+r+1]--;
            r=p[i*2+1]/2;
            tot[i+2]++; tot[i+r+2]--;
        }
        ll ans=0;
        for(int i=1;i<=n;i++) {
            tot[i]=tot[i-1]+tot[i];
            ans+=tot[i]*sum[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}