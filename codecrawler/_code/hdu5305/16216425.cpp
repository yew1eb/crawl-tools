#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int d1[10],d2[10],sum[10];  //d1è¡¨ç¤ºonline,d2è¡¨ç¤ºoffline
int n,m;
int ans=0,a[30],b[30];
int judge()     //å¤æ­onlineåofflineç¸ç­
{
    for(int i=1;i<=n;i++)
    {
        if(d1[i]!=d2[i])
            return 0;
    }
    return 1;
}
void dfs(int num)     //numè¡¨ç¤ºç¬¬å ç»å³ç³»
{
    if(num==m+1)
    {
        if(judge())
            ans++;
        return ;
    }
    int x=a[num],y=b[num];
    if((d1[x]<sum[x]/2)&&(d1[y]<sum[y]/2))   //åè®¾è¯¥è¾¹ä¸ºonline
    {
        d1[x]++;
        d1[y]++;
        dfs(num+1);
        d1[x]--;        //è®°å¾ä¿®æ¹çè¾¹è¦åæ¶ä¿®æ¹åæ¥
        d1[y]--;
    }
    if((d2[x]<sum[x]/2)&&(d2[y]<sum[y]/2))
    {
        d2[x]++;
        d2[y]++;
        dfs(num+1);
        d2[x]--;
        d2[y]--;
    }
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            memset(d1,0,sizeof(d1));
            memset(d2,0,sizeof(d2));
            memset(sum,0,sizeof(sum));
            scanf("%d%d",&n,&m);
            for(int i=1;i<=m;i++)
            {
                scanf("%d%d",&a[i],&b[i]);
                sum[a[i]]++;
                sum[b[i]]++;
            }
            ans=0;
            int ok=1;
            for(int i=1;i<=n;i++)    //ä¸ºå¥æ°æ¶è¯´æä¸æç«
            {
                if(sum[i]&1)
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                dfs(1);
                printf("%d\n",ans);
            }
            else
                printf("0\n");
        }
    }
    return 0;
}