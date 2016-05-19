#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<30
#define M 60005
#define N 20005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
using namespace std;
int pre[N],r[N];
int n,q;
int K,num[N];
char ope[1000];
vector<int>que;
void Init()
{
    for(int i=0;i<=n;i++) pre[i]=i,r[i]=0;
}
int find(int x)
{
    if(x!=pre[x])
    {
        int f=pre[x];
        pre[x]=find(pre[x]);
        r[x]^=r[f];
    }
    return pre[x];
}
bool Union(int a,int b,int c)
{
    int ra=find(a),rb=find(b);
    if(ra==rb)
    {
        if((r[a]^r[b])!=c) return false;
        else return true;
    }
    if(ra==n) swap(ra,rb);   //è¿å¥å¾éè¦ï¼å³ç³»å°Queryçé£ä¸ªå¤æ­ï¼WAäºå æ¬¡
    pre[ra]=rb;
    r[ra]=r[a]^r[b]^c;
    return true;
}
int Query()
{
    bool vis[N];mem(vis,false);
    int ans=0;
    for(int i=0;i<K;i++)
    {
        if(vis[i])continue;
        int cnt=0;
        int root=find(num[i]);
        for(int j=i;j<K;j++)
        {
            if(!vis[j]&&find(num[j])==root)
            {
                cnt++;
                vis[j]=true;
                ans^=r[num[j]];
            }
        }
        if(root!=n&&cnt&1) return -1;
    }
    return ans;
}
int main()
{
    int CAS=0;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        if(n==0&&q==0) break;
        printf("Case %d:\n",++CAS);
        Init();
        bool error=false;
        int cas=0;
        while(q--)
        {
            scanf("%s",ope);
            if(ope[0]=='I')
            {
                getchar();gets(ope);cas++;
                int space=0,u,v,w;
                for(int i=0;i<strlen(ope);i++) space=space+(ope[i]==' ');
                if(space==1) {sscanf(ope,"%d%d",&u,&w);v=n;}
                else sscanf(ope,"%d%d%d",&u,&v,&w);
                if(error) continue;
                if(!Union(u,v,w)){printf("The first %d facts are conflicting.\n",cas);error=true;}
            }
            else
            {
                scanf("%d",&K);
                for(int i=0;i<K;i++)scanf("%d",&num[i]);
                if(error) continue;
                int ans=Query();
                if(ans==-1) puts("I don't know.");
                else printf("%d\n",ans);
            }
        }
        puts("");
    }
    return 0;
}