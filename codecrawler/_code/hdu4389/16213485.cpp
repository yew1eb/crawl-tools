#include <iostream>
#include <cstdio>

using namespace std;
int dp[10][82][82][82];
void Pre(){
     int i,j,k,l,x;
     for(i=1; i<=81; i++) dp[0][0][i][0] = 1;

     for(l=0; l<9; l++)
     for(i=0; i<=l*9; i++)
     for(j=1; j<=81; j++)
     for(k=0; k<j; k++)
     for(x=0; x<=9; x++){
         dp[l+1][i+x][j][(k*10+x)%j] += dp[l][i][j][k];
     }
}

int Solve(int x){
    if(x == 0) return 0;
    int ret = 0;
    if(x == 1000000000) { ret++; x--; }
    int i,j,k;
    int len,sum,t,tt,power=1,bit[11];

    len = sum = 0;
    t = tt = x;
    while(t){
         bit[++len] = t % 10;
         t /= 10;
         sum += bit[len];
    }

    if(x % sum == 0) ret++; // remember
    for(i=1; i<=len; i++){
        // basic coding
        tt /= 10;   power *= 10;
        t = tt * power;
        sum -= bit[i];

        for(j=0; j<bit[i]; j++){ // basic coding
            for(k=sum+j; k<=sum+j+9*(i-1); k++){
                if(k == 0) continue;
                int dd = t % k;
                if(dd > 0) dd = k - dd;
                ret += dp[i-1][k-sum-j][k][dd];
            }
            t += power / 10;
        }
    }
    return ret;
}

int main()
{
    int ta=1,cas;
    Pre();
    scanf("%d",&cas);
    while(cas--){
         int a,b;
         scanf("%d%d",&a,&b);
         printf("Case %d: %d\n",ta++,Solve(b)-Solve(a-1));
    }
    return 0;
}
