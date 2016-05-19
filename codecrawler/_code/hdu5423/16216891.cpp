#include<stdio.h>
#include<string.h>
#include<algorithm>
#define M 1005
using namespace std;
struct node{
    int to,next;
}edge[M*100];
int head[M*2];
int n,tot,ans[1005],q,vis[1005];
void add(int a,int b)
{
    edge[tot].to=b;
    edge[tot].next=head[a];
    head[a]=tot++;
}
int t=0;
void dfs(int x,int deep)
{
    int i,j;
    vis[x]=1;
    for(i=head[x];i!=-1;i=edge[i].next)
    {    
    
    j=edge[i].to;
    if(vis[j])continue;
    vis[j]=1;
    dfs(j,deep+1);
    }
    ans[q++]=deep;
    return;
}
int main()
{
  int i,j,u,v;
  while(scanf("%d",&n)!=EOF)
  {
      q=0;
      memset(vis,0,sizeof(vis));
      memset(head,-1,sizeof(head));
      tot=0;
      for(i=1;i<n;i++)
      {
          scanf("%d%d",&u,&v);
          add(u,v);
          add(v,u);   //å»ºæ 
      }
      int deep=0,f;
      f=0;
    dfs(1,0);
    int as=0,mark=0;
    sort(ans,ans+q-1);
    for(i=1;i<q-1;i++)
    {
    if(ans[i]==ans[i-1]){mark=1; as=ans[i];}   //å¤æ­æ¯å¦æä¸¤ä¸ªä¸æ ·çæ·±åº¦ãå³å¤æ­æ¯å¦æåæ¯ã
     if(ans[i]>as&&mark)f=1;     //å¨åæ¯ä¸å¦æè¿æç¹ï¼å°±æ¯NOäºã
  }
    
     if(f)printf("NO\n");
     else printf("YES\n");
  }    
  return 0;
}