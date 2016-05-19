#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
#define INF 1e9
#define maxn 100005
#define maxm 100005+10
const ll mod = 1e10+7;
#define eps 1e-7
#define PI acos(-1.0)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(n) scanf("%d",&n)
#define scan2(n,m) scanf("%d%d",&n,&m)
#define scans(s) scanf("%s",s);
#define ini(a) memset(a,0,sizeof(a))
#define out(n) printf("%d\n",n)
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
ll a[2][maxn];  
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //  freopen("out.txt","w",stdout);
#endif
    int T;
    int n;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        ini(a);
        rep1(i,n) scanf("%I64d",&a[0][i]);
        int s = 0,start = 1,end = n;
        bool finish = 1;
        rep(i,n)
        {
            while(start < end && a[s][start] == 0) start++; //ç¼©ç¹
            start = max(1 ,start-1);
            while(end > start && a[s][end] == 0) end--;
            end = min(end + 1,n - i);
            if(start >= end) break;
            int inc = 1, dec = 1;
            for(int j = start;j < end; j++)
            {
                if(a[s][j] > a[s][j+1]) inc = 0;
                else if(a[s][j] < a[s][j+1]) dec = 0;
            }

            finish = inc | dec;
            if(!finish)
            {
                if(i == 0) puts("ugly series");
                else printf("%d\n",i - 1);
                break;
            }
            
            for(int j = start;j < end; j++)
            {
                a[s^1][j] = a[s][j+1] - a[s][j];
            }
            s ^= 1;
        }
        if(finish)
            puts("nice series");
    }
    return 0;
}