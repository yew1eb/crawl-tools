#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define maxn 100005
#define ll __int64
#define cnm c[nu][m]
using namespace std;
int v[15][maxn];
ll m,n;
//funå½æ°å®ä¹å°1-numå¹³ååç»l-rä¸ªäºº
int a[15][50];
int si[15];
bool b[50];
int dp[50][10]={0};
int c[50][10][15][50]={0};
ll ave,nu;
bool dfs(int sum,int g,int s){
    if(sum==ave){g++;sum=0;s=1;}
    if(g==m-1){
        for(int i=1;i<=nu;i++)
            if(!b[i])a[g][++a[g][0]]=i;
        return true;
    }
    for(int i=s;i<=nu;i++){
        if(sum+i>ave) return false;
        if(!b[i]){
            b[i]=true;
            a[g][++a[g][0]]=i;
            if(dfs(sum+i,g,i+1)) return true;
            b[i]=false;
            a[g][0]--;
        }
    }
    return false;
}

bool fun(ll num){
    if(num>=4*m-1){
        for(int i=0,j=0;i<m;i++,j++){
            v[i][si[i]++]=num-j;
            v[i][si[i]++]=num-2*m+1+j;
        }
        return fun(num-2*m);
    }
    else {
        nu=num;
        ave=(num+1)*num/2/m;
        int b;
        if(dp[num][m]==0){
            if(dfs(0,0,1)){
                dp[num][m]=1;
                for(int i=0;i<m;i++)
                    for(int j=0;j<=a[i][0];j++)
                        cnm[i][j]=a[i][j];
            }
            else dp[num][m]=-1;
        }
        if(dp[nu][m]==1) return true;
        return false;
    }
}
void out(int n){
    printf("YES\n");
    for(int i=0;i<n;i++){
        printf("%d",si[i]+cnm[i][0]);
        for(int j=0;j<si[i];j++) printf(" %d",v[i][j]);
        for(int j=0;j<cnm[i][0];j++) printf(" %d",cnm[i][j+1]);
        printf("\n");
    }
}
void Init(){
    memset(si,0,sizeof(si));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d",&n,&m);
        ll su=n*(n+1)/2;
        ll av=su/m;
        if(su%m||av<n)printf("NO\n");
        else{
            Init();
            bool ok=fun(n);
            if(ok)out(m);
            else printf("NO\n");
        }
    }
    return 0;
}
