#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=2005;
char str[maxn];
int dp[maxn][maxn], len;
int match(int x, int y){
    return (str[x]=='}') + (str[y]=='{');
}

int solve(int x, int y){
    if(x>y)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    int i, tmp=maxn;
    for(i=x+1; i<y-1; i+=2){
        if(solve(x, i)+solve(i+1, y)<tmp){
            tmp=solve(x, i)+solve(i+1, y);
        }
    }
    if(match(x, y)+solve(x+1, y-1)<tmp){
        tmp=match(x, y)+solve(x+1, y-1);
    }
    dp[x][y]=tmp;
    return tmp;
}

int main(){
    int cas=1;
    while(scanf("%s", str)&&str[0]!='-'){
        memset(dp, -1, sizeof(dp));
        len=strlen(str);
        printf("%d. %d\n", cas++, solve(0, len-1));
    }
    return 0;
}