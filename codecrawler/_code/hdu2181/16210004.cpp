#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int > map[25];
bool vis[25];
int pre[25];
int m,num;
void print_ans(int cur){
     if(cur!=m){
        print_ans(pre[cur]);
        printf(" %d",cur);
     }

}
void dfs(int cur,int cnt){
     if(cnt<20&&vis[m]) return;

     if(cnt==20&&cur==m){
         printf("%d:  %d",num++,m);

         print_ans(pre[m]);
         printf(" %d\n",m);
       //  cout<<4342<<endl;
         return ;
     }
     for(int i=0;i<=2;i++){
         int temp=map[cur][i];
         if(!vis[temp]){
             vis[temp]=true;
             pre[temp]=cur;
             dfs(temp,cnt+1);
             vis[temp]=false;
         }
     }

}
int main()
{
    int a,b,c;
    for(int i=1; i<=20; i++)   map[i].clear();
    for(int i=1; i<=20; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        map[i].push_back(a);map[i].push_back(b);map[i].push_back(c);
    }

    while( scanf("%d",&m),m){
        memset(vis,false,sizeof(vis));
        memset(pre,0,sizeof(pre));
        num=1;
   //     cout<<m<<endl;
        dfs(m,0);
    }
}
