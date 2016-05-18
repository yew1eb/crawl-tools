#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 100005;
int a[11], b[11], c[11];

int main()
{
 //freopen("a.in","r",stdin); freopen("a.out","w",stdout);
 int N, cas = 0;
 while(scanf("%d", &N) == 1 && N)
 {
 int be = 100;
 for(int i = 1; i <= N; i++)
 scanf("%d%d%d", &a[i], &b[i], &c[i]);
 int ans = 1, cnt;
 for(; ans < MAX; ans++)
 {
 cnt = 0;
 for(int i = 1; i <= N; i++)
 if(c[i] <= a[i]) cnt++;
 if(cnt == N) break;
 for(int i = 1; i <= N; i++)
 {
 if(c[i] == a[i]+b[i] || c[i] == a[i] && cnt > N-cnt) c[i] = 0;
 c[i]++;
 }
 }
 if(ans == MAX) ans = -1;

 printf("Case %d: %d\n", ++cas, ans);
 }
 return 0;
}