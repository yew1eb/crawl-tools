#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 #include<cmath>
 #include<vector>
 using namespace std;
 #define MAXN 10000+10
 struct Node{
    int v,len;
 };
 vector<Node>vet[MAXN];
 int n;
 double dp[MAXN];
 int sum[MAXN];
 
 void dfs(int root,int father){
    sum[root]=1;
    for(int i=0;i<vet[root].size();i++){
       int son=vet[root][i].v;
       int len=vet[root][i].len;
       if(son==father)continue;
       dfs(son,root);
       sum[root]+=sum[son];
       dp[root]+=dp[son]+(sum[son]*(n-sum[son]))*(double)len;
    }
 }
 
 int main(){
  //  freopen("1.txt","r",stdin);
    int _case,u,v,len;
    scanf("%d",&_case);
    while(_case--){
       scanf("%d",&n);
       for(int i=0;i<=n;i++)vet[i].clear();
       for(int i=1;i<=n-1;i++){
          scanf("%d%d%d",&u,&v,&len);
          Node p1,p2;
          p1.v=v,p2.v=u;
          p1.len=p2.len=len;
          vet[u].push_back(p1);
          vet[v].push_back(p2);
       }
       memset(sum,0,sizeof(sum));
       memset(dp,0,sizeof(dp));
       dfs(0,-1);
       int s=(n*(n-1)/2);
       printf("%1lf\n",(double)dp[0]/s);
    }
    return 0;
 }