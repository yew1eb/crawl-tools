#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 55
#define mod 1000000007
#define eps 1e-4
typedef long long ll;
struct node
{
    double x,y;
}p[maxn],tp[maxn];
int T,n,m,c,M[maxn][maxn],tM[maxn][maxn],id[maxn],cnt;
double x,y;
ll ans;
ll mod_pow(ll a,ll b,ll p)
{
    ll ans=1ll;
    a%=p;
    while(b)
    {
        if(b&1) ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    } 
    return ans;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&c);
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)M[i][j]=0;
        x=y=0;
        cnt=ans=1;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            x+=p[i].x,y+=p[i].y;
        }
        x/=n,y/=n;
        for(int i=0;i<n;i++)p[i].x-=x,p[i].y-=y;//å°å¾å¹³ç§»ä½¿å¾ä¸­å¿ç¹æ¯åç¹ 
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--,b--;
            M[a][b]=M[b][a]=1;
        }
        for(int i=0;i<n;i++)ans=ans*c%mod;//ä¸æè½¬ 
        for(int k=1;k<4;k++)//æè½¬k*90åº¦ 
        {
            int flag=1;
            memset(id,0,sizeof(id));
            for(int i=0;i<maxn;i++)
                for(int j=0;j<maxn;j++)tM[i][j]=0;
            //åæ è½¬æ¢ 
            if(k==1)for(int i=0;i<n;i++)tp[i].x=-p[i].y,tp[i].y=p[i].x;
            else if(k==2)for(int i=0;i<n;i++)tp[i].x=-p[i].x,tp[i].y=-p[i].y;
            else if(k==3)for(int i=0;i<n;i++)tp[i].x=p[i].y,tp[i].y=-p[i].x;
            for(int i=0;i<n&&flag;i++)//å¤æ­æè½¬åç¹çåæ ä¸ååç¹æ¯å¦è½ä¸ä¸å¯¹åº 
            {
                int temp=0;
                for(int j=0;j<n&&!temp;j++)
                    if(fabs(p[j].x-tp[i].x)<eps&&fabs(p[j].y-tp[i].y)<eps)
                        temp=1,id[j]=i;
                if(!temp)flag=0;
            }
            for(int i=0;i<n;i++)//æ±åºæè½¬åç¹çå³ç³»ç©éµ 
                for(int j=0;j<n;j++)
                    if(M[i][j])tM[id[i]][id[j]]=1;
            for(int i=0;i<n;i++)//å¤æ­ä¸¤ä¸ªå³ç³»ç©éµæ¯å¦ç¸å 
                for(int j=0;j<n;j++)
                    if(M[i][j]!=tM[i][j])flag=0;
            if(flag)//åæ³ç½®æ¢ 
            {
                int res=0;
                for(int i=0;i<n;i++)//æ±è½®æ¢æ° 
                {
                    if(id[i]==-1)continue;
                    int j=i;
                    while(id[j]!=i&&~j)
                    {
                        int temp=j;
                        j=id[j],id[temp]=-1;
                    }
                    id[j]=-1;
                    res++;
                }
                ll temp=1;
                for(int i=0;i<res;i++)temp=temp*c%mod;
                ans=(ans+temp)%mod;
                cnt++;
            }
        }
        ans=ans*mod_pow(cnt,mod-2,mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
} 