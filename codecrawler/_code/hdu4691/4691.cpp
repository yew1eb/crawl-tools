#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define N 100010
char s[N];
int m,n,len;
int t[N],t2[N],c[N],height[N],sa[N],rank[N],dp[N][20],cnt[N];
//sa   代表等级为i的下标
//rank  代表下标为i的等级
//height  代表字符串由最低位排序到最高位相邻两个字符串的前缀相同个数

void build_sa()
{
    m=27;
    int *x=t,*y=t2;
    for(int i=0; i<m; ++i) c[i]=0;
    for(int i=0; i<n; ++i) ++c[x[i]=cnt[i]];
    for(int i=1; i<m; ++i) c[i]+=c[i-1];
    for(int i=n-1; i>=0; –i) sa[--c[x[i]]]=i;
    for(int k=1; k<=n; k<<=1)
    {
        int p=0;
        for(int i=n-k; i<n; ++i) y[p++]=i;
        for(int i=0; i<n; ++i) if(k<=sa[i]) y[p++]=sa[i]-k;

        for(int i=0; i<m; ++i) c[i]=0;
        for(int i=0; i<n; ++i) ++c[x[y[i]]];
        for(int i=1; i<m; ++i) c[i]+=c[i-1];
        for(int i=n-1; i>=0; –i) sa[--c[x[y[i]]]]=y[i];

        swap(x,y);
        p=1,x[sa[0]]=0;
        for(int i=1; i<n; ++i)
            x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}

void get_height()
{
    for(int i=0; i<=len; ++i) rank[sa[i]]=i;
    for(int i=0,k=0; i<len; ++i)
    {
        if(k) –k;
        if(rank[i]-1<0) continue;
        int j=sa[rank[i]-1];
        while(cnt[i+k]==cnt[j+k]) ++k;
        height[rank[i]]=k;
    }
}

void rmq_init()
{
    int i,j;
    for(i=1;i<=len;i++)dp[i][0]=height[i];
    for(j=1;(1<<j)<=len;j++){
        for(i=1;i+(1<<j)-1<=len;i++){
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) ++k;
    return  min(dp[L][k],dp[R-(1<<k)+1][k]);
}

void RMQ_init()
{
    for(int i=0; i<=len; ++i)  dp[i][0]=height[i];
    for(int j=1; (1<<j)<=len; ++j)
        for(int i=1; i+(1<<j)-1<=len; ++i)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int lcp(int a,int l)
{
    if(a==l) return len-a;
    int u=rank[a],v=rank[l];
    if(u>v) return RMQ(v+1,u);
    else return RMQ(u+1,v);
}

int cal(int p)
{
    int v=p;
    for(int i=1;; ++i)
        if(v/10==0) return i;
        else v/=10;
}
int main()
{
   // freopen("in.txt","r",stdin);
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        for(int i=0; i<len; ++i) cnt[i]=s[i]-’a'+1;
        cnt[len]=0;
        n=len+1;
        build_sa();
        get_height();
        RMQ_init();
        int t,a,b,l,r;
        LL ans1,ans2;
        scanf("%d",&t);
        scanf("%d %d",&a,&b);
        ans1=b-a+1;
        ans2=b-a+3;
        –t;
        while(t–)
        {
            scanf("%d %d",&l,&r);
            ans1=ans1+r-l+1;
            int p=min(lcp(a,l),min(b-a,r-l));
            ans2=ans2+(r-l)-p+2+cal(p);
            a=l,b=r;
        }
        printf("%I64d %I64d\n",ans1,ans2);
    }
    return 0;
}