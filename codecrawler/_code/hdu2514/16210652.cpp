#include<stdio.h>
#include<math.h>
#include<string.h>
int a[10],vis[10],ans[10],anscnt;
int abs(int q)
{
    if(q<0) return -q;
    return q;
}
int ok()
{
    if(abs(a[2]-a[1])!=1&&
        abs(a[3]-a[1])!=1&&
        abs(a[4]-a[1])!=1&&
        
        abs(a[2]-a[3])!=1&&
        abs(a[2]-a[5])!=1&&
        abs(a[2]-a[6])!=1&&
        
        abs(a[3]-a[4])!=1&&
        abs(a[3]-a[5])!=1&&
        abs(a[3]-a[6])!=1&&
        abs(a[3]-a[7])!=1&&
        
        abs(a[4]-a[6])!=1&&
        abs(a[4]-a[7])!=1&&
        
        abs(a[5]-a[6])!=1&&
        abs(a[5]-a[8])!=1&&
        
        abs(a[6]-a[7])!=1&&
        abs(a[6]-a[8])!=1&&
        
        abs(a[7]-a[8])!=1
        )
        return 1;
    else return 0;
}
void DFS(int k)
{
    int i,cnt=0;
    if(k==9)
//æ³¨æè¿éæ¯k==9 èä¸æ¯æè®©å®ç­äº8ä¹åæ¾å¨è°ç¨å½æ°çæåé¢ é£æ ·çè¯ æåä¸æ¬¡çèµå¼å°±ä¼è¢«è¿åä¸º0
        {
            if(ok())
            {
                anscnt++;
                if(anscnt==1)
                {
                    for(i=1;i<=8;i++)
                        ans[i]=a[i];
                }
            }
            return;
        }
    if(anscnt>=2) return;
    if(a[k]!=0) DFS(k+1);
    else
        for(i=1;i<=8;i++)
        {
            if(!vis[i])
            {
                a[k]=i;
                vis[i]=1;
                DFS(k+1);
                a[k]=0;
                vis[i]=0;
            }
        }
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        anscnt=0;
        int i;
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        scanf("%d %d %d %d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8]);
        for(i=1;i<=8;i++) vis[a[i]]=1;
        DFS(1);
        printf("Case %d: ",++cas);
        if(anscnt==1)
        {
            for(i=1;i<8;i++)  printf("%d ",ans[i]);
            printf("%d\n",ans[i]);
        }
        else if(anscnt==0) printf("No answer\n");
        else printf("Not unique\n");
    }
    return 0;
}
