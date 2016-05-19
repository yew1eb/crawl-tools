//ä»£ç æ¯éååç
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 20;
const int INF = 1e9;
const int N = 10;
int vis[maxn];
int val[maxn], have[maxn], f[maxn], p,allnum, allval;
int ans;

int gao(int p, int f[], int ans)
{
    for(int i = N-1;i>=0;i--)
    {
        int t = f[i];
        t = min(t, p/val[i]);
        if(i==4 || i==7)
        {
            if(t%2==1)
                t--;
        }
        p -= t*val[i];
        ans += t;
    }
    if(p!=0)
        return -1;
    return ans;
}

void solve()
{
    int result = -1;
    allnum = 0;
    allval = 0;
    for(int i = 0; i<N; i++)
    {
        allnum += have[i];
        allval += have[i]*val[i];
    }
    p = allval - p;
    if(p<0)
    {
        printf("-1\n");
        return;
    }
    for(int sta = 0;sta<(1<<2);sta++)
    {
        int pp = p, tmp=0;
        for(int i = 0;i<N;i++)
            f[i] = have[i];
        if(((1<<0)&sta)&&have[4]>=1&&pp>=50)
        {
            pp -= 50;
            f[4]--;
            tmp++;
        }
        if(((1<<1)&sta)&&have[7]>=1&&pp>=500)
        {
            pp -= 500;
            f[7]--;
            tmp++;
        }
        int t = gao(pp, f, tmp);
        if(t!=-1)
            result = max(result, allnum - t);
    }
    printf("%d\n", result);
}

int main()
{
   // freopen("Ain.txt", "r" ,stdin);
    val[0] = 1;
    val[1] = 5;
    val[2] = 10;
    val[3] = 20;
    val[4] = 50;
    val[5] = 100;
    val[6] = 200;
    val[7] = 500;
    val[8] = 1000;
    val[9] = 2000;
    int ncase;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &p);
        for(int i = 0; i<N; i++)
            scanf("%d", &have[i]);
        solve();
    }
    return 0;
}