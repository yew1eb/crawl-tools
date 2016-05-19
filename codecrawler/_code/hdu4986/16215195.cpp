#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define INF 1000000000
#define maxn
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define mset(x) memset(x,0,sizeof(x))
#define C 0.577215664901
typedef __int64 ll;

double f[10020];
ll n;
int main(){
//    freopen("a.txt","r",stdin);
//    freopen(".out","w",stdout);
    f[1]=1;
    for(int i=2;i<=10010;i++){
        f[i] = f[i-1]+ (1/(double)i);
    }
    while(cin>>n){
        if(n>10000){
            printf("%.4lf\n",log((double)n)+C);
        }
        else{
            printf("%.4lf\n",f[n]);
        }
    }
//    printf("%.4lf\n%.4lf",f[10000], log((double)10000)+C);
    return 0;
}

/*
DESCRIPTION:
nä¸ªæ°æn!ä¸ªæåï¼æææåçå¾ªç¯æ°ä¹åè®¾ä¸ºp(n)
æä»¥Nä¸ªæ°çææçå¾ªç¯æ°æ¯ f(n) = p(n)/n! 
ä»æ°æ®çï¼å°±ç®O(n)ä¹ä¼ç
æ¾ç¶è¿æ¯æ°å­¦é¢
æä»¥ä¸å¼å§è§å¾O(n)éæ¨ä¸è¡
åæ¥æ³æ³ï¼è¦æ¯æä¸ªéé¡¹å¬å¼è½ç´æ¥æ¨åºf(n)ä¹æªå°ä¸å¯
p(n)æ¾ç¶æ¯æ¨ä¸åºæ¥çï¼æ°æ®å¤ªå¤§ï¼
f(n)åªè½ä»f(n-1)æ¨
f(1)=1
f(2)=1.5
f(3)=1.833
f(4)=2.083
f(5)=2.283
æ¾ç¶åï¼f[i] = f[i-1]+1/i
f[n] = 1/1 + 1/2 +... + 1/n
f(n)å¨næå¤§çæ¶åè¶äºln(n) + C
C=0.577215664901
*/