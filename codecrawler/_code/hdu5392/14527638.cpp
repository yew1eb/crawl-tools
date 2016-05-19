#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long llu;

const int maxn = 3000051;

const llu mod =  llu(3221)*1000000+225473;
llu ans;

int n, a[maxn], e[maxn];

char str[maxn*8];



int e2[maxn], b[maxn], c[maxn];
int lb;



llu calc(int x,int y)
{
    if(y==0)return 1;
    if(y<2)return x;
    llu tmp=calc(x,y>>1);
    tmp=tmp*tmp%mod;
    if(y&1)tmp=tmp*x%mod;
    return tmp;
}

void work(int x)
{
    while(x>1) {
        int i=e2[x],j=0,k=b[e2[x]];
        while(x>1 && e2[x]==i) {
            x/=k;
            ++j;
        }
        c[i]=max(c[i],j);
    }
    return;
}
void solve(int tt)
{
    scanf("%d\n", &n);
    gets(str);
    int len = strlen(str);
    a[1]=0;

    for(int i=0,j=1; i<len; ++i) {
        if(str[i]==' ') a[++j]=0;
        else a[j]=a[j]*10+str[i]-'0';
    }
    ans=1;

    memset(c,0,sizeof c );

    for(int i=1; i<=n; ++i) {
        if(e[i]<tt) {
            int tmp=1;
            e[i]=tt;
            for(int j=a[i]; j!=i; j=a[j]) {
                e[j]=tt;
                ++tmp;
            }
            work(tmp);
        }
    }

    ans=1;
    for(int i=1; i<=lb && b[i]<=n; ++i) {

        if(c[i])ans=ans*calc(b[i],c[i])%mod;

    }

    printf("%I64u\n",(ans+mod)%mod);

}
  int T;

int main()
{
    //freopen("in.txt", "r", stdin);
    for(int i=2; i<maxn; ++i) {
        if(!e2[i]) {
            b[++lb]=i;
            e2[i]=lb;
        }
        for(int j=1; j<=lb && b[j]*i<maxn; ++j) {
            e2[b[j]*i]=j;
            if(i%b[j]==0)break;
        }
    }


    scanf("%d",&T);

    for(int cas=1; cas<=T; ++cas) {


        solve(cas);
    }
    return 0;
}