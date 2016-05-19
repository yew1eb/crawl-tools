//ç»ä¸¤ä¸ªé¡¶ç¹æ°ç¸åçå¾
//I_A , I_B, D_A , D_B ;åå«ä¸ºå¢å Aå¾ï¼Bå¾çä¸ä¸ªè¾¹ï¼å é¤Aå¾ï¼Bå¾çä¸ä¸ªè¾¹çcost
//é®æå°éè¦è±è´¹å¤å°ä½¿å¾ä¸¤å¹å¾åæ
//ç±äºnå¾å°ï¼å¯ä»¥æ´åæä¸¾Açæ¯ä¸ä¸ªç¹å¯¹åºBå¾çç¹å¯¹åºå³ç³»ï¼ç¶åå°±æ¯å¯¹åºè¾¹å¦æä¸å¹å¾æ
//å¦ä¸å¹å¾æ²¡æï¼å°±éå é¤æçæå¢å æ²¡æçå°çcost
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
const int maxn = 10 ;
const int inf = 0x7fffffff ;
int map_a[maxn][maxn] ;
int map_b[maxn][maxn] ;
int vis[maxn] ;
int a_b[maxn];
int ans ;
int n , m_a , m_b ;
int I_A , I_B, D_A , D_B ;
void dfs(int num)
{
    if(num == n + 1)
    {
        int sum = 0 ;
        for(int i = 1;i <= n;i++)
          for(int j = 1;j <= n;j++)
          {
              if(map_b[i][j] && !map_a[a_b[i]][a_b[j]])
              sum += min(I_A , D_B) ;
              if(map_a[a_b[i]][a_b[j]] && !map_b[i][j])
              sum += min(I_B , D_A) ;

          }
          ans = min(ans , sum) ;
        return  ;
    }
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])continue ;
        vis[i] = 1;
        a_b[num] = i ;
        dfs(num+1) ;
        vis[i] = 0 ;
    }
}
int main()
{
   //freopen("in.txt" ,"r" ,stdin) ;
    int cas = 0 ;
    while(scanf("%d%d%d" , &n , &m_a , &m_b) &&(n + m_a + m_b))
    {
        memset(vis ,0 , sizeof(vis)) ;
        memset(map_a , 0 , sizeof(map_a)) ;
        memset(map_b , 0 , sizeof(map_b)) ;
        scanf("%d%d%d%d" , &I_A, &I_B , &D_A , &D_B);
        for(int i = 1;i <= m_a;i++)
        {
            int u , v ;
            scanf("%d%d" , &u , &v) ;
            map_a[u + 1][v + 1] = map_a[v+1][u+1] =  1;
        }
        for(int i = 1;i <= m_b; i++)
        {
            int u , v ;
            scanf("%d%d" , &u , &v) ;
            map_b[u+1][v+1]  = map_b[v+1][u+1] =  1;
        }
        ans = inf ;
        dfs(1) ;
        printf("Case #%d: " ,++cas) ;
        printf("%d\n" , ans/2) ;
    }
    return  0 ;
}






















