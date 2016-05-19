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
   if(myok())//判断是否还有反面的纸牌，若有则继续翻牌，无则计数
   {
       temp=0;
	   for(i=0;i<len;i++)
		   if(cnt[i]==1) temp++;
	   if(temp<ans)
		   ans=temp;
	   return;
   }
   if(idx>=len) return;//当搜索完最后一张必须返回
   for(cnt[idx]=0;cnt[idx]<2;)
   {
       a[idx]^=1;//翻牌
	   if(idx>0) a[idx-1]^=1;//翻左边的
	   if(idx<len) a[idx+1]^=1;//翻右边的
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