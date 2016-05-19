#include<cstdio>
#include<cstring>

int sg[55][55];
char s[55][55];

int dfs(int p,int q)
{
 if(~sg[p][q]) return sg[p][q];
 bool vis[3333];memset(vis,0,sizeof(vis));
 if(!p) for(int v=0;v<q;v++) vis[dfs(p,v)]=1;
 if(!q) for(int u=0;u<p;u++) vis[dfs(u,q)]=1;
 for(int u=0;u<p;u++) for(int v=0;v<q;v++) vis[dfs(u,q)^dfs(p,v)]=1;
 int i=0;while(vis[i]) i++;
 return sg[p][q]=i;
}
int main()
{
 memset(sg,-1,sizeof(sg));
 int n,m;
 while(scanf("%d%d",&n,&m),n||m)
 {
 int g=0;
 for(int i=0;i<n;i++) scanf("%s",s[i]);
 for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='#') g^=dfs(i,j);
 puts(g?"John":"Jack");
 }
 return 0;
}