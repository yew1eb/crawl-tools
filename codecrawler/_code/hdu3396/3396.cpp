#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define LL long long
using namespace std;
#define mod 1000000007
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define LL long long
const LL INFL = 1e17;
const int INF = 1e9;

int n;
char g[210][210];
int s[210][210];

int main(){

  //  freopen("1.txt","r",stdin);
    int cas = 1;
    while(scanf("%d",&n)&&n){
        getchar();
        memset(g,0,sizeof(g));
        for(int i = 1; i <= n; i++)
            gets(g[i]+1);

        memset(s,0,sizeof(s));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 2*n-1; j++){
             //  printf("%c",g[i][j]);
                s[i][j] = s[i][j-1]+(g[i][j]=='-'?1:0);
            }
          // printf("\n");
        }

        int maxn = 0,tot;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 2*n-1; j++){
                if(g[i][j]=='-'){
                   // printf("i = %d j = %d\n",i,j);
                    tot = 1;
                    if((i+j)%2==0){
                        int p = j-1,q = j+1;
                        for(int k = i-1; k > 0; k--){
                          //  printf("k = %d %d %d %d\n",k,p,q,s[k][q]-s[k][p-1]);
                            if(p>=1 && q <= 2*n-1 && s[k][q]-s[k][p-1]==q-p+1){
                                tot += q-p+1;
                                q++,p--;
                            }else break;
                        }
                        maxn = max(maxn,tot);
                    }else{
                        int p = j-1,q = j+1;
                        for(int k = i+1; k <= n; k++){
                            if(p>=1 && q <= 2*n-1 && s[k][q]-s[k][p-1]==q-p+1){
                                tot += q-p+1;
                                q++,p--;
                            }else break;
                        }
                        maxn = max(maxn,tot);
                    }
                }
            }
        printf("Triangle #%d\n",cas++);
        printf("The largest triangle area is %d.\n\n",maxn);
    }
    return 0;
}