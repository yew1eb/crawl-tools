#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100010;

int K,n;
char str[MAX];
int r[MAX];
long long sum[MAX];
int limit[MAX];

    const int maxn =1000100;
    int rk[maxn],sa[maxn],height[maxn];
    int a[maxn],b[maxn],cnt[200000];
    //å¾æåºå­ç¬¦ä¸²ä¸ºr,é¿åº¦ä¸ºn,èå´r[0] - r[n-1],å¼é¢èå´0 - n-1.
    //å­ç¬¦éä¸ºmï¼èå´1 - m;

    void radix_sort(int * r, int *a, int *b, int n, int m){//å°aæç§rè¿è¡åºæ°æåºï¼å¨å­å°b,é¿åº¦ä¸ºnï¼å­ç¬¦éä¸ºm
        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i < n; ++i) ++cnt[r[a[i]]];
        for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
        for(int i = n -1; i >= 0; --i) b[--cnt[r[a[i]]]] = a[i];
    }

    void calc_sa(int*r, int n, int m){
        for(int i = 0; i < n; ++i) rk[i] =i;
        radix_sort(r,rk,sa,n,m);

        rk[sa[0]] = 0;
        for(int i = 1; i < n; ++i)
            rk[sa[i]]= rk[sa[i-1]] +(r[sa[i]]!=r[sa[i-1]]);
        for(int i = 0; 1<<i< n; ++i){
            for(int j = 0; j < n; ++j){
                a[j] = rk[j]+1;
                b[j] = j + (1<<i) >=n? 0: rk[j + (1<<i)] + 1;
                sa[j] = j;
            }
            radix_sort(b,sa,rk,n,n);
            radix_sort(a,rk,sa,n,n);
            rk[sa[0]] = 0;
            for(int j = 1; j < n; ++j){
                rk[sa[j]] = rk[sa[j-1]] + (a[sa[j-1]] != a[sa[j]] || b[sa[j-1]] != b[sa[j]]);
            }
        }
    }

    void calc_height(int * r,int n) {//è®¡ç®height
        for(int i = 0 ; i < n; ++i) rk[sa[i]] = i;
        int h = 0;
        for(int i = 0; i < n; ++i){
            h = h == 0?0: h - 1;
            if(rk[i]!= 0)
                while(r[i + h] == r[sa[rk[i]-1] + h]) h++;
            height[rk[i]] = h;
        }
    }

bool judge(long long mid)
{
    int pos = lower_bound(sum + 1, sum + 1 + n,mid) - sum - 1;
    int len = mid - sum[pos] + height[pos];

    for(int i = 0 ; i < pos; ++i)
        limit[sa[i]] = n;
    limit[sa[pos]] = sa[pos] + len;
    int mii = height[pos+1];
    for(int i = pos + 1; i < n; ++i){
        mii = min(mii,height[i]);
        limit[sa[i]] = sa[i] + min(mii,len);
    }

    int need = 1;
    mii = n;
    for(int i = 0; i < n; ++i){
        if(i == limit[i]) return false;
        if(i >= mii){
            if(++need > K) return false;
            mii = n;
        }
        mii = min(mii,limit[i]);
    }
    return true;
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&K), K){
        scanf("%s",str);
        n = 0;
        for(;str[n];n++)
            r[n] = str[n];
        calc_sa(r,n,256);
        calc_height(r,n);
        sum[0] = 0;
        for(int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + n - sa[i-1] - height[i-1];
        long long lb = 0,ub = sum[n];
        while(lb + 1 < ub){
            long long  mid = (lb + ub) >> 1;
            if(judge(mid)) ub = mid;
            else lb = mid;
        }
        int pos = lower_bound(sum + 1, sum + 1 + n,ub) - sum - 1;
        int len = ub - sum[pos] + height[pos];
        pos = sa[pos];
        str[pos + len] = 0;
        printf("%s\n",str + pos);
    }
    return 0;
}
