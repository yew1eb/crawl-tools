#include<stdio.h>
#include<iostream>
#include<map>
#include<stack>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std ;
#define LEN   sizeof(struct node)
#define pret(a,b) memset(a,b,sizeof(a))
#define lld __int64
const double PI = 3.1415926 ;
const double INF = 999999999 ;
const double esp = 1e-4 ;
const lld  md= 2810778 ;
const int MX = 20 ;
int n ;
char s[MX] ;
bool vis[1<<16] ;
struct node
{
    int key,step ; // key 表状态 step 记录步数
} ;
int bfs()
{
    queue<node>q ;
    node curt,next ;
    while(!q.empty()) q.pop() ;
    memset(vis,false,sizeof(vis)) ;
    curt.key=curt.step=0 ;
    vis[0]=true ;
    q.push(curt) ;
    while(!q.empty())
    {
        curt=q.front() ;
        q.pop() ;
        for(int i=0 ;i<(n<<1) ;i++) // 遍历每一个点
        {
            int key=curt.key,ky=0 ;
            next.step=curt.step+1 ; // 步数加一
            if(key&(1<<i))      continue ;
            //   先单行左右扩展
            for(int j=i ;j<(i/n+1)*n ;j++)// 从当前节点向右扩展
            {
                if(key&(1<<j)) break ;// 遇到已经染色的就结束
                if(s[i]==s[j]) ky=ky|(1<<j) ; // 与起始颜色一样 ~> 染色
            }
            for(int j=i-1 ;j>=(i/n)*n ;j--) // 从当前节点向左扩展
            {
                if(key&(1<<j)) break ;
                if(s[i]==s[j]) ky=ky|(1<<j) ;
            }
            if((key|ky)==(1<<(n*2))-1) return next.step ; // 放在这可以减少时间
            for(int j=ky ;j ;j=key&(j-1))
            {
               if(!vis[key|j])
               {
                   vis[key|j]=true ;
                   next.key=key|j ;
                   q.push(next) ;
               }
            }
            // 以上为单行双向扩展
            if(i/n)  continue ;
            key=curt.key ; ky=0 ;
            if(key&(1<<(i+n))) continue ;
            for(int j=i ;j<n ;j++)
            {
                if((key&(1<<j))||(key&(1<<(j+n)))) break ;
                if(s[i]==s[j]) ky=ky|(1<<j) ;
                if(s[i]==s[j+n])ky=ky|(1<<(j+n)) ;
            }
            for(int j=i-1 ;j>=0 ;j--)
            {
                if((key&(1<<j))||(key&(1<<(j+n)))) break ;
                if(s[i]==s[j])  ky=ky|(1<<j) ;
                if(s[i]==s[j+n]) ky=ky|(1<<(j+n)) ;
            }
            if((key|ky)==(1<<(n*2))-1) return next.step ; 
            for(int j=ky ;j ;j=ky&(j-1)) // 切记要枚举子集：因为并不一定需要涂最大区域，如果涂了最大区域
            {                           //别的地方就没法连续涂了。
                if(!vis[key|j])
                {
                    vis[key|j]=true ;
                    next.key=key|j ;
                    q.push(next) ;
                }
            }
        }
    }
    return 0 ;
}
int main()
{
    int Tx,q=1 ;
    scanf("%d",&Tx) ;
    while(Tx--)
    {
        scanf("%d",&n) ;
        scanf("%s",s) ; // 用一维存储
        scanf("%s",s+n) ;
        printf("Case #%d: %d\n",q++,bfs()) ;
    }
    return 0 ;
}
