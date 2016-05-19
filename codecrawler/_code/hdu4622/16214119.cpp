#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

#define LS 2*i
#define RS 2*i+1
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N 2005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define rank rank1
int wa[N],wb[N],wsf[N],wv[N],sa[N];
int rank[N],height[N],s[N],a[N];
char str[N],str1[N],str2[N];
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
//sa:å­å¸åºä¸­æç¬¬iä½çèµ·å§ä½ç½®å¨strä¸­ç¬¬sa[i]
//rank:å°±æ¯strç¬¬iä¸ªä½ç½®çåç¼æ¯å¨å­å¸åºæç¬¬å 
//heightï¼å­å¸åºæiåi-1çåç¼çæé¿å¬å±åç¼
int cmp(int *r,int a,int b,int k)
{
    return r[a]==r[b]&&r[a+k]==r[b+k];
}
void getsa(int *r,int *sa,int n,int m)//nè¦åå«æ«å°¾æ·»å ç0
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++)  wsf[i]=0;
    for(i=0; i<n; i++)  wsf[x[i]=r[i]]++;
    for(i=1; i<m; i++)  wsf[i]+=wsf[i-1];
    for(i=n-1; i>=0; i--)  sa[--wsf[x[i]]]=i;
    p=1;
    j=1;
    for(; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++)  y[p++]=i;
        for(i=0; i<n; i++)  if(sa[i]>=j)  y[p++]=sa[i]-j;
        for(i=0; i<n; i++)  wv[i]=x[y[i]];
        for(i=0; i<m; i++)  wsf[i]=0;
        for(i=0; i<n; i++)  wsf[wv[i]]++;
        for(i=1; i<m; i++)  wsf[i]+=wsf[i-1];
        for(i=n-1; i>=0; i--)  sa[--wsf[wv[i]]]=y[i];
        t=x;
        x=y;
        y=t;
        x[sa[0]]=0;
        for(p=1,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)? p-1:p++;
    }
}
void getheight(int *r,int n)//nä¸ä¿å­æåç0
{
    int i,j,k=0;
    for(i=1; i<=n; i++)  rank[sa[i]]=i;
    for(i=0; i<n; i++)
    {
        if(k)
            k--;
        else
            k=0;
        j=sa[rank[i]-1];
        while(r[i+k]==r[j+k])
            k++;
        height[rank[i]]=k;
    }
}

int Log[N];
int best[30][N];

void setLog()
{
    Log[0] = -1;
    for(int i=1; i<N; i++)
    {
        Log[i]=(i&(i-1))?Log[i-1]:Log[i-1] + 1 ;
    }
}
void RMQ(int n)  //åå§åRMQ
{
    for(int i = 1; i <= n ; i ++) best[0][i] = height[i];
    for(int i = 1; i <= Log[n] ; i ++)
    {
        int limit = n - (1<<i) + 1;
        for(int j = 1; j <= limit ; j ++)
        {
            best[i][j] = min(best[i-1][j] , best[i-1][j+(1<<i>>1)]);
        }
    }
}
int LCP(int a,int b)  //è¯¢é®a,båç¼çæé¿å¬å±åç¼
{
    a ++;
    int t = Log[b - a + 1];
    return min(best[t][a] , best[t][b - (1<<t) + 1]);
}
int t,n,m;

int solve(int l,int r,int n)
{
    int ans = (r-l+1)*(r-l+2)/2;
    int last = -1;
    int cnt = r-l+1;
    for(int i = 1; i<=n; i++)
    {
        if(!cnt) break;
        if(sa[i]<l || sa[i]>r) continue;
        cnt--;
        if(last == -1)
        {
            last = i;
            continue;
        }
        int a = last;
        int b = i;
        if(a>b) swap(a,b);
        int lcp = LCP(a,b);
        int la = r-sa[last]+1;//åºé´åè¯¥ä¸²çå°¾é¨
        int lb = r-sa[i]+1;
        if(la>=lb && lcp>=lb);//laåå«lbäºï¼é£ä¹å°±ç¨laç»§ç»­å¾åæ¯è¾ï¼åæ­¤ä¿æå­å¸åºï¼æ¥æ¨¡æå¾å°è¯¥åºé´çææheight
        else last = i;
        ans-=min(lcp,min(la,lb));
    }
    return ans;
}

int main()
{
    int i,j,k,len,l,r;
    scanf("%d",&t);
    setLog();
    W(t--)
    {
        scanf("%s",str);
        scanf("%d",&m);
        len = strlen(str);
        for(i = 0; i<len; i++)
            s[i] = str[i]-'a'+1;
        s[len] = 0;
        getsa(s,sa,len+1,30);
        getheight(s,len);
        RMQ(len);
        while(m--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",solve(l-1,r-1,len));
        }
    }
    return 0;
}
