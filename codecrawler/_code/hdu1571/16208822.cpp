#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
using namespace std;
int mp[33][33],vis[33];
int pos,res,n,k,t;
int main()
{
    int n,ans;
    char ss[10];
    queue<int>q;
    vector<int>head[33];
    int u;
    while(scanf("%d",&n))
    {
        if(!n)break;
        while(!q.empty())q.pop();
        for(int i=0;i<=n;++i){head[i].clear();vis[i]=0;}
        pos=ans=res=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&mp[i][j]);
        
           scanf("%d",&k);
        
        for(int i=0;i<k;++i){
            scanf("%s",ss);
            if(ss[0]=='U'){
                scanf("%d",&t);
                if(pos==t||res==7)continue;
                    res++;
                    if(!vis[t]){
                        q.push(t);
                          vis[t]=1;
                      }
                          head[t].push_back(1);
              }
            else{
                if(res==0)continue;
                  u=q.front();
                    q.pop();
//                printf("u:%d\n",u);
                
                   res-=head[u].size();
                      head[u].clear();
                       vis[u]=0;
                      ans+=mp[pos][u];
                         pos=u;
            }
        }
        
        printf("%d\n",ans);
        
    }
    return 0;
}