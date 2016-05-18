#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;
int map[30][30] ;
int n ;
int ans ;
int vis[30] ;
void dfs(int d)
{
    if(d==n)
    {
        int temp=0 ;
        for(int i=0;i<n;i++)
            if(vis[i])
                for(int j=0;j<n;j++)
                    if(!vis[j])
                        temp+=map[i][j] ;
        if(ans<temp)
            ans=temp ;
        return ;
    }
    vis[d]=1 ;
    dfs(d+1) ;
    vis[d]=0 ;
    dfs(d+1) ;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&map[i][j]) ;
        memset(vis,0,sizeof(vis)) ;
        ans=0 ;
        if(n<20)
            dfs(0) ;
        else
        {
            int times=500000 ;
            srand(time(0)) ;
            while(times--)
            {
                vis[rand()%n]^=1 ;
                int temp=0 ;
                for(int i=0;i<n;i++)
                    if(vis[i])
                        for(int j=0;j<n;j++)
                            if(!vis[j])
                            temp+=map[i][j] ;
                if(ans<temp)
                    ans=temp ;
            }
        }
        printf("%d.\n",ans) ;
    }
    return 0 ;
}