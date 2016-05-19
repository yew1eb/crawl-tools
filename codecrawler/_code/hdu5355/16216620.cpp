#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
#define ll __int64
using namespace std;
const int N = 100005;
const int inf = 1000000000;
const int mod = 1000000007;
int solve()
{
    __int64 n,m;
    int i,j,k,c,s,d,r,w[32];
    set<int> v;
    set<int>::iterator it;
    scanf("%I64d%I64d",&n,&m);
    if(((n+1)*n/2)%m||m*2-1>n)
        return puts("NO");
    c=(n-m*2+1)%(m*2)+m*2-1,//èç³çåéæ¹å¼å¯ä»¥åæä¸¤é¨åï¼åä¸é¨åè³å°æ2*m-1ä¸ªï¼
    s=c*(c+1)/(m*2),        //èåé¢å¿é¡»è¦ækä¸ª2*mï¼é£å¤åºæ¥çé¨åå°±å½å°åä¸é¨åå»
    d=(n-c)/(m*2);          //å³(n-m*2+1)%(m*2)+m*2-1
    puts("YES");
    for(i=1; i<=c; i++)
        v.insert(i);
    for(j=0,k=c+1;j<m;j++,putchar('\n'))
    {
        for(c=r=0;r<s;)//sä¸ºæ¯ä»½èç³åä¸é¨åçå
        {
            it=v.upper_bound(s-r);//éè¿äºåæ¾ä½¿æ»åææ¥è¿sçèç³å¤§å°
            r+=w[c++]=*--it;
            v.erase(it);
        }
        printf("%d",c+d*2);//c+d*2è¡¨ç¤ºæ¯ç»èç³çä¸ªæ°ï¼då³æ¯é¢è§£ä¸­æå°çkä¸ª2*mçk
        for(i=0;i<c;i++)
            printf(" %d",w[i]);
        for(i=0;i<d;i++)
            printf(" %d %d",k++,n--);//å¶å®ä»£ç è§£éèµ·æ¥æ¯è¾éº»ç¦ï¼è¿å¾æ ¹æ®ä¸è¿°ä¸¾çä¾å­æ¥å æ·±çè§£
    }
}
int main()
{
    int t;
    for(scanf("%d",&t);t--;solve());
}