#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<time.h>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<map>
#include<set>
//#define ONLINE_JUDGE
#define eps 1e-8
#define INF 0x7fffffff
#define FOR(i,a) for((i)=0;i<(a);(i)++)
#define MEM(a) (memset((a),0,sizeof(a)))
#define sfs(a) scanf("%s",a)
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define pf(a) printf("%d\n",a)
#define pfI(a) printf("%I64d\n",a)
#define pfs(a) printf("%s\n",a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,num) scanf("%d%d%d",&a,&b,&num)
#define for1(i,a,b) for(int i=(a);i<b;i++)
#define for2(i,a,b) for(int i=(a);i<=b;i++)
#define for3(i,a,b)for(int i=(b);i>=a;i--)
#define MEM1(a) memset(a,0,sizeof(a))
#define MEM2(a) memset(a,-1,sizeof(a))
#define ll __int64
const double PI=acos(-1.0);
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
using namespace std;
int n,m;
#define M 110
#define N 100010
#define Mod 1000000007
#define p(x,y) make_pair(x,y)
int getNum(int x){
    int num=0;
    while(x){
        num++;
        x/=10;
    }
    return num;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
    int t;
    int kas=1;
    while(sfd(n,t)!=EOF){
        if(n == -1 && t == -1) break;
        int tail = 0;        //ä¿å­æ¯æ¬¡çæçç»å°¾æ°å­
        int sum1=0,sum2=0;  //sum1ä¿å­å¥æ°ä½ä¸çåï¼sum2ä¿å­å¶æ°ä½ä¸çå
        int cur=getNum(n);  //å½åæ°å­æå ä½
        int tot=cur;        //ä¿å­ä¸å±æå ä½
        while(n){
            if(cur&1) sum1+=(n%10);
            else
                sum2 += (n%10);
            n /= 10;
            cur--;
        }
        tail += sum1+sum2;
        int sum = 0;
        while(t--){
            sum += tail;
            int tmp = sum;
            tot += getNum(tmp);
            cur = tot;
            tail=0;
            while(tmp){
                if(cur&1) sum1+=(tmp%10);
                else
                    sum2 += (tmp%10);
                tail += tmp%10;
                tmp /= 10;
                cur--;
            }
        }
        int dif = sum1-sum2;
        printf("Case #%d: ",kas++);
        if(dif%11==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
