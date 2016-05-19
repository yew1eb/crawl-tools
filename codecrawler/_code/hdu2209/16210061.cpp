#include<stdio.h>
#include<string.h>
#define INF 1<<30
int a[25],cnt[25];
int ans,temp,len;
bool myok()
{
   int i;
   for(i=0;i<len;i++)
     if(a[i]) return false;
   return true;
}
void dfs(int idx)
{
    int i;
   if(myok())//å¤æ­æ¯å¦è¿æåé¢ççº¸çï¼è¥æåç»§ç»­ç¿»çï¼æ åè®¡æ°
   {
       temp=0;
       for(i=0;i<len;i++)
           if(cnt[i]==1) temp++;
       if(temp<ans)
           ans=temp;
       return;
   }
   if(idx>=len) return;//å½æç´¢å®æåä¸å¼ å¿é¡»è¿å
   for(cnt[idx]=0;cnt[idx]<2;)
   {
       a[idx]^=1;//ç¿»ç
       if(idx>0) a[idx-1]^=1;//ç¿»å·¦è¾¹ç
       if(idx<len) a[idx+1]^=1;//ç¿»å³è¾¹ç
       cnt[idx]++;
       dfs(idx+1);
   }
}
int main()
{
   int i;
   char ch[25];
   while(~scanf("%s",ch))
   {
     len=strlen(ch);
     for(i=0;i<len;i++)
        a[i]=ch[i]-'0';
     ans=INF;
     memset(cnt,0,sizeof(cnt));
     dfs(0);
     if(ans!=INF) printf("%d\n",ans);
     else printf("NO\n");
   }
   return 0;
}