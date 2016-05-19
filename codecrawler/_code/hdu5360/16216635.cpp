//nä¸ªäººæ¥åéè¯·çæ¡ä»¶æ¯å·²ç»æ¥åéè¯·çäººæ°åºé´å¨l[i] , r[i] 
//é®ææ ·è®¾ç½®éè¯·é¡ºåºè½ä½¿å¾æ¥åéè¯·çäººæ°æå¤
//åå¯¹å¶å¯¹ä»å°å°å¤§æåº
//ç¶åç»´æ¤ä¸ä¸ªsetï¼setä¸­å­å¥å·¦è¾¹æ»¡è¶³æ¡ä»¶çææäººï¼
//ç¶åè´ªå¿ç­ç¥æ¯æ¯æ¬¡åå·¦è¾¹æ»¡è¶³æ¡ä»¶çå³è¾¹æå°çäºº
//æ¯æ¬¡å¤éè¯·ä¸ä¸ªäººåå é¤å³è¾¹ä¸æ»¡è¶³æ¡ä»¶çäºº
#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std ;
const int maxn = 100010 ;
int a[maxn] ;   int t  ;int n ;
int vis[maxn] ;
struct node
{
    int l ,r ,id ;
    bool operator < (const struct node tmp) const
    {
        if(l == tmp.l)
        return r < tmp.r ;
        return l<tmp.l ;
    }
} p[maxn];
multiset<pair<int, int> > s ;
multiset<pair<int , int> >::iterator it ;
int main()
{
   // freopen("in.txt" ,"r" , stdin) ;
    scanf("%d" , &t) ;
    memset(vis , 0 , sizeof(vis)) ;
    while(t--)
    {
        scanf("%d" , &n) ;
        for(int i = 1;i <= n;i++)
        scanf("%d"  ,&p[i].l) ,p[i].id = i ;
        for(int i = 1;i <= n;i++)
        scanf("%d" , &p[i].r) ;
        sort(p + 1 , p + 1 + n) ;
        int ans = 0 ;
        int i = 1;
        s.clear() ;
        while(1)
        {
            while(ans >= p[i].l && i <= n)
            {
                s.insert(make_pair(p[i].r , p[i].id)) ;
                i++;
            }
            if(!s.size())break;
            while(s.size())
            {
                it = s.begin() ;
                if(it->first >= ans)
                break;
                s.erase(s.begin()) ;
            }
            if(s.size())
            {
                it = s.begin();
                a[++ans] = it->second ;
                vis[it->second] = 1;
                s.erase(s.begin()) ;
            }
        }
        printf("%d\n"  ,ans) ;
        for(int i = 1;i <= n;i++)
        if(!vis[i])
        a[++ans] = i ;
        else vis[i] = 0 ;
        for(int i = 1;i <= ans ;i++)
        printf("%d%c" , a[i] , i == ans ? '\n':' ') ;
    }
    return 0 ;
}





