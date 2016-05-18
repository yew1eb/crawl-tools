//裸的kruskal，如果不会的多看下并查集吧，不多说了
 #include<stdio.h>
 #include<string.h>
 #include<algorithm>
 using namespace std;
 #define maxn 100
 int fa[maxn],rank[maxn];
 struct node
 {
     int st,nd,ln;
 }edge[maxn*maxn];
 int cmp(node a,node b)
 {
     return a.ln<b.ln;
 }
 void init()
 {
     int i;
     for(i=0;i<maxn;i++)
     {
         rank[i]=1;
         fa[i]=i;
     }
 }
 int findfather(int x)
 {
     if(x!=fa[x])
         fa[x]=findfather(fa[x]);
     return fa[x];
 }
 void kruskal(int n,int m)
 {
     int ans,num,i,x,y;
     ans=num=0;
     sort(edge+1,edge+1+n,cmp);
     for(i=1;i<=n;i++)
     {
         x=findfather(edge[i].st);
         y=findfather(edge[i].nd);
         if(x!=y)
         {
             ans+=edge[i].ln;
             if(rank[x]>rank[y])
             {
                 fa[y]=x;
                 rank[x]+=rank[y];
             }
             else
             {
                 fa[x]=y;
                 rank[y]+=rank[x];
             }
             if(++num==m-1)
                 break;
         }
     }
     if(num==m-1)
         printf("%d\n",ans);
     else
         printf("?\n");
 }
 int main()
 {
     int n,m,i;
     while(scanf("%d",&n)!=EOF)
     {
         init();
         scanf("%d",&m);
         if(n==0)
             break;
         for(i=1;i<=n;i++)
         {
             scanf("%d%d%d",&edge[i].st,&edge[i].nd,&edge[i].ln);
         }
         if(n<m-1)
         {
             printf("?\n");
             continue;
         }
         kruskal(n,m);
     }
     return 0;
 }