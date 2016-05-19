#include<iostream>
 #include<cstring>
 #include<cstdio>
 using namespace std;
 #define N 305
 int match[N][N];
 int mark[N];
 int visted[N];
 int n,p;
 int t ;
 int DFS(int x)
 {
     int j;
     for(j=1;j<=n;j++)
     {
         if(!visted[j]&&match[x][j]==1)
         {
             visted[j]=1;
             if(!mark[j]||DFS(mark[j]))
             {
                 mark[j]=x;
                 return 1;
             }
         }
     }
     return 0;
 }
 int main()
 {
     //freopen("input.txt","r",stdin);
       // freopen("output.txt","w",stdout);
     scanf("%d",&t);
     while(t--)
     {
 
         memset(match,0,sizeof(match));
         memset(mark,0,sizeof(mark));
         scanf("%d%d",&p,&n);
         if(p>n)
         {
             printf("NO\n");
             continue ;
         }
         int i;
         for(i=1;i<=p;i++)
         {
             int num;
             int j;
             scanf("%d",&num);
             for(j=1;j<=num;j++)
             {
                 int a;
                 scanf("%d",&a);
                 match[i][a]=1;
 
             }
         }
         int  ans=0;
         for(i=1;i<=p;i++)
         {
             memset(visted,0,sizeof(visted));
             if(DFS(i))
                 ans++;
         }
         if(ans==p)
             printf("YES\n");
         else
             printf("NO\n");
     }
     return 0;
 }