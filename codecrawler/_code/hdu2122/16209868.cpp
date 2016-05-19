#include<stdio.h>
#include<string.h>
int v[10010],map[10010][10010];
#define inf 0xfffffff;
int main()
{
    int n,m,i,j,a,b,c;
    while(~scanf("%d%d",&n,&m))
    {
        int sum=0;
        memset(v,0,sizeof(v));
        for(i=0;i<n;i++)//åå§å 
        {
            for(j=0;j<n;j++)
            {
                map[i][j]=inf;
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<map[a][b])//å¤æ­æ¯å¦æ¯éè¾¹ï¼è¦æ¯èµ·ç¹ç»ç¹é½ç¸åçæ¶åï¼å°±å»æå¼æå°çä½ä¸ºä¸¤ä¸ªé¡¶ç¹é´çè·ç¦»å³æ¯æå¼ 
            map[a][b]=map[b][a]=c;
        }
        v[0]=1;
        int flag;
        for(i=1;i<n;i++)
        {
            int min=inf;
            flag=-1;
            for(j=0;j<n;j++)
            {
                if(!v[j]&&map[0][j]<min)
                {
                    min=map[0][j];
                    flag=j;
                }
            }
            if(flag==-1)
            break;
            v[flag]=1;
            sum+=map[0][flag];
            for(j=0;j<n;j++)
            {
                if(!v[j]&&map[0][j]>map[flag][j])
                map[0][j]=map[flag][j];
            }
        }
        if(flag==-1)
        printf("impossible\n\n");
        else
        printf("%d\n\n",sum);
    }
    return 0;
}