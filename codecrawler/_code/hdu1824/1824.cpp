#include<iostream>
 #include<vector>
 #include<cstdio>
 #include<cstring>
 using namespace std;
 const int MAX = 20010;
 int n,m,T;
 vector<int>mp[MAX];
 int st[MAX];
 int dfn[MAX],low[MAX];
 int top,btype,tdfn;//btype:连通块的个数
 int belong[MAX];//点属于哪个连通块
 bool ins[MAX];
 void dfs(int s)
 {
     ins[s]=1;
     dfn[s]=low[s]=++tdfn;
     st[++top]=s;
     for(int i=0;i<mp[s].size();i++)
     {
         int t=mp[s][i];
         if(!dfn[t])
         {
             dfs(t);
             if(low[t]<low[s]) low[s]=low[t];
         }
         else if(ins[t]&&dfn[t]<low[s]) low[s]=dfn[t];
     }
     if(dfn[s]==low[s])
     {
         btype++;int t;
         do
         {
             t=st[top--];
             ins[t]=0;
             belong[t]=btype;
         }while(t!=s);
     }
 }
 void scc(int n)
 {
     top=btype=tdfn=0;
     memset(ins,false,sizeof(ins));
     memset(dfn,0,sizeof(dfn));
     for(int i=1;i<=n;i++)
         if(!dfn[i])
             dfs(i);
 }
 int main()
 {
     int x,y,z,a,b;
     while(scanf("%d%d",&T,&m)!=EOF)
     {
         n=3*T;
         for(int i=0;i<=2*n;i++)
             mp[i].clear();
         for(int i=0;i<T;i++)
         {
             scanf("%d%d%d",&x,&y,&z);x++;y++;z++;
             mp[x+n].push_back(y);
             mp[x+n].push_back(z);
             mp[y+n].push_back(x);
             mp[z+n].push_back(x);
         }
         for(int i=0;i<m;i++)
         {
             scanf("%d%d",&a,&b);
             a++;b++;
             mp[a].push_back(b+n);
             mp[b].push_back(a+n);
         }
         scc(2*n);
         int flag=1;
         for(int i=1;i<=n;i++)
         {
             if(belong[i]==belong[i+n])
             {
                 flag=0;
                 break;
             }
         }
         if(flag) printf("yes\n");
         else printf("no\n");
     }
     return 0;
 }