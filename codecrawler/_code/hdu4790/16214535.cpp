#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#define MAXN 100005
using namespace std;
typedef long long LL;
LL p,m;
LL gcd(LL a,LL b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    //freopen("Input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas<=T; cas++)
    {
        LL a,b,c,d,ans = 0;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&p,&m);
        if((b-a)>(d-c))
            swap(a,c),swap(b,d);
        long long t1 = (a+c)%p;
        long long add = (m - t1 + p)%p;
        long long cnt1 = (a+c + add-m)/p;
        long long t2 = (b+c-1)%p;
        long long sub = (t2 - m + p)%p;
        long long cnt2 = (b+c-1-sub-m)/p;
        //cout<<t2<<" "<<sub<<endl;
        ans += (cnt2 - cnt1 + 1)*(1+add) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2 * p;
        t1 = (b+c)%p;
        add = (m - t1 + p)%p;
        cnt1 = (b+c+add-m)/p;
        t2 = (a+d)%p;
        sub = (t2 - m + p)%p;
        cnt2 = (a+d-sub-m)/p;
        ans += (cnt2 - cnt1 + 1)*(b-a+1);
        t1 = (a+d+1)%p;
        add = (m - t1 + p)%p;
        cnt1 = (a+d+1+add-m)/p;
        t2 = (b+d)%p;
        sub = (t2 - m + p)%p;
        cnt2 = (b+d-sub-m)/p;
        ans += (cnt2 - cnt1 + 1)*(1+sub) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2*p;
        long long tot = (b-a+1)*(d-c+1);
        long long GCD = gcd(ans,tot);
        ans /= GCD;
        tot /= GCD;
        printf("Case #%d: %I64d/%I64d\n",cas,ans,tot);
    }
    return 0;
}
