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
const int maxn=1000000+10;
int a[maxn];
int ans1[8];
int f[maxn][8];                     //åiä¸ªæ°ä¸­1,2,3,4,5,6,7,8åå«åºç°å æ¬¡

int solve(){
    if(ans1[7]>=2)
        return 7;
    if(ans1[6]>=2)
        return 6;
    if(ans1[5]>=2)
        return 5;
    if(ans1[4]>=2)
        return 4;
    if(ans1[3]>=2||(ans1[3]&&ans1[6]))
        return 3;
    if(ans1[2]>=2||(ans1[2]&&ans1[6])||(ans1[2]&&ans1[4])||(ans1[4]&&ans1[6]))
        return 2;
    return 1;
}

int main(){
    //freopen("data.in.txt","r",stdin);
    mem0(a);
    mem0(f);
    for(int i=2;i<maxn;i++)                 //é¢å¤çæ¯ä¸ªiå¯ä»¥åè§£ä¸ºå¤å°ç§ä¸åçç´ æ°
        if(!a[i]){
            a[i]=1;
            for(int j=2*i;j<maxn;j+=i)
                a[j]++;
        }
    //printf("%d\n",a[510510]);
    for(int i=2;i<maxn;i++){                //åiä¸ªæ°ä¸­1,2,3,4,5,6,7,8åå«åºç°å æ¬¡
        for(int j=1;j<=7;j++){              //åç¼åçææ³
            f[i][j]=f[i-1][j];
        }
        f[i][a[i]]++;
    }
    /*for(int i=2;i<=10;i++){
        for(int j=1;j<=7;j++)
            printf("%d   ",f[i][j]);
        cout<<endl;
    }*/
    int t;
    int n,m;
    scanf("%d",&t); 
    while(t--){
        scanf("%d%d",&n,&m);
        mem0(ans1);
        for(int i=1;i<=7;i++){
            //printf("%d %d\n",f[m][i],f[n][i]);
            ans1[i]=f[m][i]-f[n-1][i];
        }
        printf("%d\n",solve());
    }
    return 0;
}
