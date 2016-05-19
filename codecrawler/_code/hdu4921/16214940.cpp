#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=10010;

int vis[maxn],son[maxn],len[15],val[maxn],level[maxn],mk[maxn],list[15][1005];

double cal(int a,int b)//aè¡¨ç¤ºæä¸¾å°ç¬¬alevel bçäºè¿å¶ä½è¡¨ç¤ºlevelaå±å¯è½ååªäºé¾
{
    double n=1,sum=0;
    int cnt=0;
    for(int i=1;i<=10;i++,b>>=1)
    {
        if(b&1)
        {
            cnt++;
            n*=(len[i]-a);
            sum+=list[i][a];
        }
        else
            n*=(min(len[i],a)+1);
    }
    return sum*((cnt>1?cnt:0)+level[a])/level[a]*n;
}

int main()
{
    int icy,m,i,n,k,j,a,b;
    scanf("%d",&icy);
    while(icy--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)//æ³¨æç¹æ¯ä»0å¼å§ç¼å·çï¼ï¼ï¼
            scanf("%lld",&val[i]);
        memset(son,-1,sizeof son);
        memset(vis,0,sizeof vis);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            son[a]=b;
            vis[b]=1;
        }
        //å»ºå¾è®°å½ä»¥ä¸ï¼
        int l=1;//æ±é¾çæ»æ°
        memset(mk,0,sizeof mk);//æ¯ä¸ªlevelåºç°å¨åªäºé¾ä¸­
        memset(level,0,sizeof level);//level[i]çç¹æ° //levelæ»æ°ï¼ç¬¬ä¸ä¸ªlevel[k]==0çk
        memset(list,0,sizeof list);//list[i][j]ç¬¬iæ¡é¾çç¬¬jä½ç½®çå¼
        memset(len,0,sizeof len);//æ¯æ¡é¾çé¿åº¦
        double tot=1;//åæ¯
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                for(k=0,j=i;j!=-1;j=son[j],k++)
                {
                    list[l][k]=val[j];
                    level[k]++;
                    mk[k]+=(1<<(l-1));
                }
                len[l]=k;
                tot*=(k+1);
                l++;
            }
        }
        tot-=1;//åæ¯

        double sum=0;
        for(i=0;level[i];i++)//æä¸¾æ¯ä¸å±level
            for(j=mk[i];j>0;j=(j-1)&mk[i])//æä¸¾è¿ä¸å±ååªå æ¡é¾ä¸çææå¯è½
                    sum+=cal(i,j);
        printf("%.3lf\n",sum/tot);
    }
    return 0;
}
