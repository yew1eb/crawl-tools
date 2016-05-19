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
#include<bitset>
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
#define ll long long
const double PI=acos(-1.0);
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
using namespace std;
//#pragma comment(linker,"/STACK:1024000000,1024000000")
int n,m;
#define N 210
#define M 100010
#define Mod 1000000000
#define p(x,y) make_pair(x,y)
struct Node{
    int num[2];
    int size;
    Node(){
        size = 0;
    }
}nd[M];
int a[1010];
int rt,tot;
void Insert(int x){     //å­å¸æ çå»ºç«
    int s = rt;
    for(int i=30;i>=0;i--){     //å°xçäºè¿å¶è¡¨ç¤ºå­å¥å­å¸æ 
        int tp;
        if(x&(1<<i)) tp=1;
        else
            tp=0;
        if(!nd[s].num[tp]) nd[s].num[tp] = ++tot;
        s = nd[s].num[tp];
        nd[s].size++;
    }
}
void Delete(int x){
    int s = rt;
    for(int i=30;i>=0;i--){     //å é¤æä¸ä¸ªæ°
        int tp;
        if (x&(1 << i))tp = 1;
        else
            tp = 0;
        s = nd[s].num[tp];
        nd[s].size--;
    }
}
int Query(int x){
    int s = rt;
    for(int i=30;i>=0;i--){
        int tp;
        if(x&(1<<i)) tp=1;
        else
            tp=0;
        if(tp == 1){        //å¦æè¯¥ä½ç½®æ¯1ï¼é£ä¹å°±æ¾æ¾å­å¸æ ä¸­æ¯å¦æä¸º0çï¼å¹¶ä¸å¾ä¸èµ°
            if(nd[s].num[0] && nd[nd[s].num[0]].size)
                s = nd[s].num[0];
            else    //å¦æè¯¥ä½ç½®åªæ1ï¼é£ä¹å°±èµ°1ï¼å¹¶ä¸æ¹åå¼æä»¥åçå¼
                s = nd[s].num[1],x^=(1<<i);
        }else{          //å¦æè¯¥ä½ç½®æ¯0ï¼é£ä¹å°±æ¾æ¾å­å¸æ ä¸­æ¯å¦æä¸º1çï¼å¹¶ä¸å¾ä¸èµ°
            if(nd[s].num[1] && nd[nd[s].num[1]].size)
                s = nd[s].num[1],x^=(1<<i);
            else        //å¦æè¯¥ä½ç½®åªæ0ï¼é£ä¹å°±èµ°0ï¼å¹¶ä¸æ¹åå¼æä»¥åçå¼
                s = nd[s].num[0];
        }
    }
    return x;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
    int t;
    sf(t);
    while(t--){
        sf(n);
        rt=tot=1;
        for(int i=0;i<n;i++){
            sf(a[i]);
            Insert(a[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            Delete(a[i]);
            for(int j=i+1;j<n;j++){
                Delete(a[j]);
                ans =  Max(ans,Query(a[i]+a[j]));
                Insert(a[j]);
            }
            Insert(a[i]);
        }
        pf(ans);
        for(int i=0;i<=tot;i++) nd[i].num[0]=0,nd[i].num[1]=0,nd[i].size=0;
    }
    return 0;
}

