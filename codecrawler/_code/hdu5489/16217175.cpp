//ç»ä¸ä¸ªé¿åº¦ä¸ºnçåºå
//å¨å¶ä¸­å»é¤é¿åº¦ä¸ºlçè¿ç»­çåºå
//å©ä¸çåºåçæé¿éå¢å­åºåçæé¿çé¿åº¦ä¸ºå¤å°
//ç»´æ¤ä¸¤ä¸ªæ°ç»,åé¢ä¸ä¸ªæ°ç»
//æ°ç»a[i] è¡¨ç¤ºä»åå°å,é¿åº¦ä¸ºiçæåä¸ä¸ªæ°çæå°å¼
//æ°ç»b[i] è¡¨ç¤ºä»åå¾åï¼é¿åº¦ä¸ºiçæå¤§å¾ä¸ä¸ªæ°
//ç¶åä»åå°åéåï¼
//ç±äºæ¯åè¿ä¸ä½ï¼a[i] , åb[i]åªæ¹åä¸ä¸ªæ°
//æä»¥åªéè¦å¯¹äºé£ä¸ªæ´æ°çæ°å¨å¦ä¸è¾¹ç¨äºåæ¾ä¸ä¸å°±è¡
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std ;
const int maxn = 1e5+10 ;
int a[maxn] , b[maxn] ;
int c[maxn] ;
pair<int , int> pre[maxn] ;
int len_b = 0 ;
int len_a = 0 ;
int find_b(int l , int r , int v) //æ¾ç¬¬ä¸ä¸ªå°äºå®çæ°
{
    while(l<=r)                   //å¨ä¸ä¸ªéååºåä¸­
    {
        int mid = (l+r)>> 1 ;
        if(b[mid] > v)
        l = mid+1 ;
        else r = mid - 1 ;
    }
    return l;
}
int find_a(int l , int r ,int v) //æ¾ç¬¬ä¸ä¸ªå¤§äºå®çæ°
{                                 //å¨ä¸ä¸ªéå¢åºåä¸­
    while(l<=r)
    {
        int mid = (l + r) >> 1 ;
        if(a[mid] < v)
        l = mid+1 ;
        else r = mid - 1 ;
    }
    return l ;
}
int find_ans_a(int l , int r , int v) //å¨ä¸ä¸ªéå¢åºåæ¾ç¬¬ä¸ä¸ªå°äºå®çæ°
{
    while(l<=r)
    {
        int mid = (l+r)>>1 ;
        if(a[mid] < v)
        l = mid + 1 ;
        else r = mid - 1 ;
    }
    return r ;
}
int find_ans_b(int l , int r , int v)//å¨ä¸ä¸ªéååºåä¸­æ¾ç¬¬ä¸ä¸ªå¤§äºå®çæ°
{
    while(l<=r)
    {
        int mid = (l+r) >> 1 ;
        if(b[mid] > v)
        l = mid + 1 ;
        else r = mid - 1 ;
    }
    return r ;
}
int main()
{
    //freopen("in.txt" , "r" , stdin) ;
    int t ;
    scanf("%d" , &t) ;
    int cas = 0 ;
    while(t--)
    {
        int n , l ;
        scanf("%d%d" , &n , &l) ;
        for(int i = 1;i <= n;i++)
        a[i] = b[i] = 0 ;
        for(int i = 1;i <= n;i++)
        scanf("%d" , &c[i]) ;
        len_a = len_b  = 0 ;
        for(int j = n;j > l;j--)
        {
            int pos = find_b(1 , len_b , c[j]) ;
            pre[j] = make_pair(pos , b[pos]) ;
            if(!b[pos])len_b++ ;
            b[pos] = c[j] ;
        }
        int ans = len_b ;
        for(int i = 1;i <= n-l;i++)
        {
            int pos = find_a(1 , len_a , c[i]) ;
            if(a[pos] == 0)len_a++ ;
            a[pos] = c[i] ;
            pair<int , int> tmp = pre[i+l] ;
            if(tmp.second == 0)len_b--;
            else b[tmp.first] = tmp.second ;
            int pos_1 = find_ans_b(1  , len_b , c[i]) ;
            ans = max(pos+pos_1 , ans) ;
            if(tmp.second != 0)
            {
                int pos_2 = find_ans_a(1 , len_a , tmp.second) ;
                ans = max(ans , pos_2 + tmp.first) ;
            }
        }
        printf("Case #%d: " , ++cas) ;
        printf("%d\n" , ans) ;
    }
    return  0 ;
}
