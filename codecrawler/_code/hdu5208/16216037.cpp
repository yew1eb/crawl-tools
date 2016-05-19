#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define B(x) (1<<(x))
using namespace std;
typedef long long ll;
void cmax(int& a,int b){ if(b>a)a=b; }
void cmin(int& a,int b){ if(b<a)a=b; }
void cmax(ll& a,ll b){ if(b>a)a=b; }
void cmin(ll& a,ll b){ if(b<a)a=b; }
void add(int& a,int b,int mod){ a=(a+b)%mod; }
void add(ll& a,ll b,ll mod){ a=(a+b)%mod; }
const int oo=0x3f3f3f3f;
const int MOD=100007;
const int maxn=100005;
const int maxm=23336666;
int dp[40][2][2][2][2];
int L1,R1,L2,R2;

int dfs(int pos,int f1,int f2,int f3,int f4){
    if(pos<0) return 0;
    if(dp[pos][f1][f2][f3][f4]!=-1) return dp[pos][f1][f2][f3][f4];
    int x1= f1 ? ((L1>>pos)&1) : 0;
    int y1= f2 ? ((R1>>pos)&1) : 1;
    int x2= f3 ? ((L2>>pos)&1) : 0;
    int y2= f4 ? ((R2>>pos)&1) : 1;
    int res=0;
    for(int i=x1;i<=y1;i++){
        if(x2==y2){//Bobåªè½é0æ1æ¶
            cmax(res,dfs(pos-1,f1&&i==x1,f2&&i==y1,f3,f4)+(i^x2)*B(pos));
        }else{//Bob 0 1é½å¯éï¼ä½æ¯è¯å®éåAliceä¸æ ·ç
            cmax(res,dfs(pos-1,f1&&i==x1,f2&&i==y1,f3&&i==x2,f4&&i==y2));
        }
    }
    return dp[pos][f1][f2][f3][f4]=res;
}

int main(){
    //freopen("E:\\read.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d %d %d %d",&L1,&R1,&L2,&R2);
        memset(dp,-1,sizeof dp);
        printf("Case #%d: %d\n",cas,dfs(30,1,1,1,1));
    }
    return 0;
}



