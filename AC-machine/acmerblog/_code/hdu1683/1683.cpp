#include<math.h> 
#include<stdio.h> 
#include<string.h> 
#include<vector> 
using namespace std; 
const int MAX=110; 
const double PI=acos(-1.0); 
const double EPS=1.0e-8; 
typedef __int64 lld; 
//typedef long long lld; 
    
bool dig(char x){return x>='0'&&x<='9';} 
int getval() 
{ 
    int ret=0,sign=1; 
    char c; 
    while(!dig(c=getchar())&&c!='-'); 
    if(c=='-')sign=-1; 
    else ret=c-'0'; 
    while(dig(c=getchar()))ret=ret*10+c-'0'; 
    return ret*sign; 
} 
int dblcmp(double x) 
{ 
    if(fabs(x)<EPS)return 0; 
    return x<0?-1:1; 
} 
char a[MAX];
char b[2][MAX];
bool dp[MAX][MAX];
int main() 
{ 
    int T;
    int n,m,i,j;
    scanf("%d",&T);
    while(T–) 
    { 
        scanf("%s%s%s",&a[1],&b[0][1],&b[1][1]);
        n=strlen(&a[1]);
        m=strlen(&b[0][1]);
          
        memset(dp,false,sizeof(dp));
  
        for(i=0;i<=m;i++)dp[0][i]=true;
  
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(dp[i][j-1])dp[i][j]=true;
  
                if(b[0][j]=='*'||b[0][j]==a[i]||b[1][j]==a[i])
                {
                    if(dp[i-1][j-1])dp[i][j]=true;
                }
            }
        }
  
        if(dp[n][m])puts("win");
        else puts("lose");
    } 
    return 0; 
} 