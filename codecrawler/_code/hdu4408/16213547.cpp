/*
 *ç®æ³å¼å¥ï¼
 *ç»å®ä¸ä¸ªå«æNä¸ªç»ç¹Mæ¡è¾¹çæ åå¾,æ±å®æå°çææ çä¸ªæ°t(G);
 *
 *ç®æ³ææ³ï¼
 *æå¼âæå°âçéå¶ä¸ç,å¦æåªè¦æ±æ±åºææçææ çä¸ªæ°,æ¯å¯ä»¥å©ç¨Matrix-Treeå®çè§£å³ç;
 *Matrix-Treeå®çæ­¤å®çå©ç¨å¾çKirchhoffç©éµ,å¯ä»¥å¨O(N3)æ¶é´åæ±åºçææ çä¸ªæ°;
 *
 *kruskalç®æ³ï¼
 *å°å¾G={V,E}ä¸­çææè¾¹æç§é¿åº¦ç±å°å°å¤§è¿è¡æåº,ç­é¿çè¾¹å¯ä»¥æç§ä»»æé¡ºåº;
 *åå§åå¾Gâä¸º{V,Ã},ä»åååæ«ææåºåçè¾¹,å¦ææ«æå°çè¾¹eå¨Gâä¸­è¿æ¥äºä¸¤ä¸ªç¸å¼çè¿éå,åå°å®æå¥Gâä¸­;
 *æåå¾å°çå¾Gâå°±æ¯å¾Gçæå°çææ ;
 *
 *ç±äºkruskalæç§ä»»æé¡ºåºå¯¹ç­é¿çè¾¹è¿è¡æåº,ååºè¯¥å°ææé¿åº¦ä¸ºL0çè¾¹çå¤çå½ä½ä¸ä¸ªé¶æ®µæ¥æ´ä½çå¾;
 *ä»¤kruskalå¤çå®è¿ä¸ä¸ªé¶æ®µåå¾å°çå¾ä¸ºG0,å¦ææç§ä¸åçé¡ºåºå¯¹ç­é¿çè¾¹è¿è¡æåº,å¾å°çG0ä¹æ¯ä¸å;
 *è½ç¶G0å¯ä»¥éæåºæ¹å¼çä¸åèä¸å,ä½å®ä»¬çè¿éæ§é½æ¯ä¸æ ·ç,é½åF0çè¿éæ§ç¸å(F0è¡¨ç¤ºæå¥ææé¿åº¦ä¸ºL0çè¾¹åå½¢æçå¾);
 *
 *å¨kruskalç®æ³ä¸­çä»»ææ¶å»,å¹¶ä¸éè¦å³æ³¨Gâçå·ä½å½¢æ,èåªè¦å³æ³¨åä¸ªç¹çè¿éæ§å¦ä½(ä¸è¬æ¯ç¨å¹¶æ¥éè¡¨ç¤º);
 *æä»¥åªè¦å¨æ«æè¿è¡å®ç¬¬ä¸é¶æ®µåç¹çè¿éæ§åF0ç¸å,ä¸æ¯éè¿æå°ä»£ä»·å°è¾¾è¿ä¸ç¶æç,æ¥ä¸å»é½è½æ¾å°æå°çææ ;
 *
 *ç»è¿ä¸é¢çåæ,å¯ä»¥çåºç¬¬ä¸ä¸ªé¶æ®µååé¢çå·¥ä½æ¯å®å¨ç¬ç«ç;
 *ç¬¬ä¸é¶æ®µéè¦å®æçä»»å¡æ¯ä½¿G0çè¿éæ§åF0ä¸æ ·,ä¸åªè½ä½¿ç¨æå°çä»£ä»·;
 *è®¡ç®åºè¿ä¸é¶æ®µçæ¹æ¡æ°,åä¹ä¸å®æåç»­äºæçæ¹æ¡æ°,å°±æ¯æç»ç­æ¡;
 *
 *ç±äºå¨ç¬¬ä¸ä¸ªé¶æ®µä¸­,éåºçè¾¹æ°æ¯ä¸å®ç,ææè¾¹çé¿åé½ä¸ºL0;
 *æä»¥æ è®ºç¬¬ä¸ä¸ªé¶æ®µå¦ä½è¿è¡ä»£ä»·é½æ¯ä¸æ ·ç,é£ä¹åªéè¦è®¡ç®æ¹æ¡æ°å°±è¡äº;
 *æ­¤æ¶Matrix-Treeå®çå°±å¯ä»¥æ´¾ä¸ç¨åºäº,åªéå¯¹F0ä¸­çæ¯ä¸ä¸ªè¿éåæ±çææ ä¸ªæ°åç¸ä¹å³å¯;
 *
 *Matrix-Treeå®ç:
 *Gçææä¸åççææ çä¸ªæ°ç­äºå¶Kirchhoffç©éµC[G]ä»»ä½ä¸ä¸ªn-1é¶ä¸»å­å¼çè¡åå¼çç»å¯¹å¼ï¼
 *n-1é¶ä¸»å­å¼å°±æ¯å¯¹äºr(1â¤râ¤n),å°C[G]çç¬¬rè¡,ç¬¬rååæ¶å»æåå¾å°çæ°ç©éµ,ç¨Cr[G]è¡¨ç¤º;
 *
 *ç®æ³ä¸¾ä¾ï¼
 *HDU4408(Minimum Spanning Tree)
 *
 *é¢ç®å°åï¼
 *http://acm.hdu.edu.cn/showproblem.php?pid=4408
 *
 *é¢ç®å¤§æï¼
 *ç»å®ä¸ä¸ªå«æNä¸ªç»ç¹Mæ¡è¾¹çæ åå¾,æ±å®æå°çææ çä¸ªæ°,æå¾ç»æå¯¹påæ¨¡;
**/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

const int N=111;
const int M=1111;

typedef __int64 LL;

struct Edges
{
    int a,b,c;
    bool operator<(const Edges & x)const
    {
        return c<x.c;
    }
} edge[M];

int n,m;
int mod;
LL f[N],U[N],vist[N];//f,Ué½æ¯å¹¶æ¥éï¼Uæ¯æ¯ç»è¾¹ä¸´æ¶ä½¿ç¨
LL G[N][N],C[N][N];//Gé¡¶ç¹ä¹é´çå³ç³»ï¼Cä¸ºçææ è®¡æ°ç¨çKirchhoffç©éµ

vector<int>V[N];//è®°å½æ¯ä¸ªè¿éåé

int Find(int x,LL f[])
{
    if(x==f[x])
        return x;
    else
        return Find(f[x],f);
}

LL det(LL a[][N],int n)//çææ è®¡æ°:Matrix-Treeå®ç
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j]%=mod;
    int ret=1;
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
            while(a[j][i])
            {
                int t=a[i][i]/a[j][i];
                for(int k=i; k<n; k++)
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;
                for(int k=i; k<n; k++)
                    swap(a[i][k],a[j][k]);
                ret=-ret;
            }
        if(a[i][i]==0)
            return 0;
        ret=ret*a[i][i]%mod;
    }
    return (ret+mod)%mod;
}

void Solve()
{
    sort(edge,edge+m);//ææå¼æåº
    for(int i=1; i<=n; i++)//åå§åå¹¶æ¥é
    {
        f[i]=i;
        vist[i]=0;
    }

    LL Edge=-1;//è®°å½ç¸åçæå¼çè¾¹
    LL ans=1;
    for(int k=0; k<=m; k++)
    {
        if(edge[k].c!=Edge||k==m)//ä¸ç»ç¸ç­çè¾¹,å³æå¼é½ä¸ºEdgeçè¾¹å å®
        {
            for(int i=1; i<=n; i++)
            {
                if(vist[i])
                {
                    LL u=Find(i,U);
                    V[u].push_back(i);
                    vist[i]=0;
                }
            }
            for(int i=1; i<=n; i++) //æä¸¾æ¯ä¸ªè¿éåé
            {
                if(V[i].size()>1)
                {
                    for(int a=1; a<=n; a++)
                        for(int b=1; b<=n; b++)
                            C[a][b]=0;
                    int len=V[i].size();
                    for(int a=0; a<len; a++) //æå»ºKirchhoffç©éµC
                        for(int b=a+1; b<len; b++)
                        {
                            int a1=V[i][a];
                            int b1=V[i][b];
                            C[a][b]=(C[b][a]-=G[a1][b1]);
                            C[a][a]+=G[a1][b1];//è¿éåéçåº¦
                            C[b][b]+=G[a1][b1];
                        }
                    LL ret=(LL)det(C,len);
                    ans=(ans*ret)%mod;//å¯¹Vä¸­çæ¯ä¸ä¸ªè¿éåæ±çææ ä¸ªæ°åç¸ä¹
                    for(int a=0; a<len; a++)
                        f[V[i][a]]=i;
                }
            }
            for(int i=1; i<=n; i++)
            {
                U[i]=f[i]=Find(i,f);
                V[i].clear();
            }
            if(k==m)
                break;
            Edge=edge[k].c;
        }

        int a=edge[k].a;
        int b=edge[k].b;
        int a1=Find(a,f);
        int b1=Find(b,f);
        if(a1==b1)
            continue;
        vist[a1]=vist[b1]=1;
        U[Find(a1,U)]=Find(b1,U);//å¹¶æ¥éæä½
        G[a1][b1]++;
        G[b1][a1]++;
    }

    int flag=0;
    for(int i=2; i<=n&&!flag; i++)
        if(U[i]!=U[i-1])
            flag=1;
    if(m==0)
        flag=1;
    printf("%I64d\n",flag?0:ans%mod);

}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&mod),n+m+mod)
    {
        memset(G,0,sizeof(G));
        for(int i=1; i<=n; i++)
            V[i].clear();
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
        Solve();
    }
    return 0;
}
