//å¨æä¸ªéä¸­
//æ¯ä¸ªäººç¥éå®çèº«é«åå¨æå¨ä»åé¢æèåé¢ç
//äººçèº«é«çä¸ªæ°
//é®è½å¦æ¢å¤åæ¥çéå
//å¦ææå¤ç§æåµï¼è¾åºå­å¸åºæå°ç
//åå°äººä»¥èº«é«ä»å°å°å¤§æåº
//ç¶åä»ç¬¬ä¸ä¸ªäººå¼å§æå¥éå
//å¯¹äºç¬¬iä¸ªäººkå³ä¸ºå¨å¶åé¢æèåé¢éè¦çå ä¸ªä½ç½®å¨å®åé¢æèåé¢
//éæ©ä¸¤ç§æå¥æ¹å¼ä¸­ä½ç½®å°çä¸ä¸ª
//å¯ä»¥ç¨æ ç¶æ°ç»è®°å½ç©ºä½ ï¼ ç¨äºåæ¾ä½ç½®
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std ;
const int maxn = 1e5+10 ;
int tree[maxn] ;
struct node
{
    int h , k ;
    int id ;
    int ans ;
    bool operator <(node tmp)const
    {
        return h < tmp.h ;
    }
}a[maxn];
bool cmp(struct node a , struct node b)
{
    return a.ans < b.ans ;
}
int ans[maxn] ;
void update(int x , int dx)
{
    while(x < maxn)
    {
        tree[x] += dx ;
        x += x&(-x) ;
    }
}
int getsum(int x)
{
    int sum = 0 ;
    while(x)
    {
        sum += tree[x] ;
        x -= x&(-x) ;
    }
    return sum ;
}
int find(int l , int r , int v)
{
    while(l <= r)
    {
        int mid = (l + r) >> 1 ;
        int t = mid - getsum(mid) ;
        if(t < v)
        l = mid + 1 ;
        else r = mid - 1 ;
    }
    return  l ;
}
int main()
{
    //freopen("in.txt" ,"r" , stdin) ;
    int t ;
    scanf("%d" , &t) ;
    int cas = 0 ;
    while(t--)
    {
        int n ;
        scanf("%d" , &n) ;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d" , &a[i].h ,&a[i].k) ;
            a[i].id = i;
        }
        for(int i = 1;i <= n;i++)
        tree[i] = 0 ;
        sort(a+1 , a+1+n) ;
        bool flag = false;
        for(int i = 1;i <= n;i++)
        {
           int pos1 = find(0 , n , a[i].k + 1) ;
           int pos2 = find(0 , n , n - i - a[i].k + 1) ;
           if(pos1 > n && pos2 < 1)
           {
               flag = true ;
               break;
           }
           else
           {
               int t = min(pos1 , pos2);
               a[i].ans = t ;
               update(t , 1) ;
           }
        }
        sort(a+1 , a+1+n , cmp) ;
        printf("Case #%d: " , ++cas) ;
        if(flag)
        puts("impossible");
        else
        for(int i = 1;i <= n;i++)
        printf("%d%c" , a[i].h , i == n ?'\n':' ') ;
    }
    return  0 ;
}
