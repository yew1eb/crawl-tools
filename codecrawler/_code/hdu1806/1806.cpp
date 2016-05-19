#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>
using namespace std;
#define MAX 110000
#define max(a,b) (a)>(b)?(a):(b)


map<int ,int> mmap;
int n,m,arr[MAX],tot,ans;
struct node {
    
    int v,beg,end,cnt;
}brr[MAX*2];
struct RMQ {
    
    int  dp[MAX][18];
    void Create();
    int  Query(int l,int r);
}rmq;
void RMQ::Create() {
    
    int i,j;
    for (i = 1; i <= tot; ++i)
        dp[i][0] = brr[i].cnt;
    for (j = 1; (1<<j) <= n; ++j)
        for (i = 1; i + (1<<j) - 1 <= n; ++i)
            dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int RMQ::Query(int l, int r){
    
    int k = (int)(log(r-l+1.0)/log(2.0));
    return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int GetHash(int x,int in) {
    
    //if (x < 0) return x + 100001;
    //else return x;
    if (mmap.find(x) == mmap.end()) {
     
        mmap[x] = ++tot;
        brr[tot].v = x;
        brr[tot].beg = in;
        brr[tot].cnt = 0;
        brr[tot-1].end = in - 1;
    }
    return mmap[x];
}


int main()
{
    int i,j,k,ta,tb,tc,a,b;

    
    while (scanf("%d",&n),n) {
        
        scanf("%d",&m);
        tot = 0,mmap.clear();
        for (i = 1; i <= n; ++i){
            
            scanf("%d",&arr[i]);
            k = GetHash(arr[i],i);
            brr[k].cnt++;
        }
        brr[tot].end = n;


        rmq.Create();
        for (i = 1; i <= m; ++i) {

            scanf("%d%d",&a,&b);
            if (arr[a] != arr[b]) {

                j = GetHash(arr[a],i);
                ta = brr[j].end - a + 1;    //获取前面一段的长度，可不进行查询
                k = GetHash(arr[b],i);
                tb = b - brr[k].beg + 1;    //获取后面一段的长度，可不进行查询
                ans = max(ta, tb);
                if (brr[j].end + 1 != brr[k].beg) {
                    //中间还有一些区间,必须查询
                    tc = rmq.Query(j + 1, k - 1);
                    ans = max(tc, ans);
                }
            }
            else ans = b - a + 1;
            printf("%d\n",ans);
        }
    }
}