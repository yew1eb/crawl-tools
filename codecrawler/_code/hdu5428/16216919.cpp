/*å¯¹äºæ¯ä¸ä¸ªæ°å­ï¼å®æç¨çé¨åå¶å®åªæå®çææè´¨å å­ï¼åæ¬ç¸ç­çï¼ã
æ±åºæææ°çææè´¨å å­ä¸­æå°çä¸¤ä¸ªï¼ç¸ä¹å°±æ¯ç­æ¡ã
å¦ææææ°å­çè´¨å å­ä¸ªæ°ä¸å°ä¸¤ä¸ªï¼é£ä¹å°±æ¯æ è§£ã
æ¶é´å¤æåº¦O(n*sqrt(a))O(n&#8727;sqrt(a))
*/
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define inf -0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
ll a[110];
ll count1[123456];

int main(){
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        scanf("%d",&n);
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            /*if(a[i]!=1)
                count1[cnt++]=a[i];
            for(int j=2;(ll)j*j<=a[i];j++){
                while(a[i]%j==0){
                    count1[cnt++]=j;
                    a[i]/=j;
                }
                if(a[i]!=1){
                    count1[cnt++]=a[i];
                }
            }*/  //è¿æ ·çè¯ç´ æ°ä¼æå¥ä¸¤æ¬¡
            for(int j=2;(ll)j*j<=a[i];j++){
                while(a[i]%j==0){
                    count1[cnt++]=j;
                    a[i]/=j;
                }
            }
            if(a[i]!=1){
                count1[cnt++]=a[i];
            }
        }
        if(cnt<2){
            printf("-1\n");
            continue;
        }
        else{
            sort(count1,count1+cnt);
            printf("%I64d\n",count1[0]*count1[1]);
        }
    }
    return 0;
}