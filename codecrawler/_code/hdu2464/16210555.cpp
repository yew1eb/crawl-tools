#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define MAXN 10
int marka[MAXN][MAXN];
int markb[MAXN][MAXN];
int cost[MAXN];
int biao[MAXN];

int min1(int a,int b){
    return a<b?a:b;
}

int main(){
    int n,ma,mb;
    int i,j,ti,tj;
    int a,b;
    int cas = 1;

    while(~scanf("%d%d%d",&n,&ma,&mb)){
        if(n==0 && ma==0 && mb==0){
            break;
        }
        memset(marka,0,sizeof(marka));
        memset(markb,0,sizeof(markb));
        memset(biao,0,sizeof(biao));
        for(i=0;i<4;i++){
            scanf("%d",&cost[i]);
        }
        for(i=0;i<ma;i++){
            scanf("%d%d",&a,&b);
            marka[a][b] = 1;
            marka[b][a] = 1;
        }
        for(i=0;i<mb;i++){
            scanf("%d%d",&a,&b);
            markb[a][b] = 1;
            markb[b][a] = 1;
        }
        int ans = -1;
        int tmp;
        for(i=0;i<n;i++){
            biao[i] = i;
        }
        do{
            tmp = 0;
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    //tj = biao[j];
                    //ti = biao[i];
                    if(j <= i){
                        continue;
                    }
                    tj = biao[j];
                    ti = biao[i];
                    if(marka[i][j]==1 && markb[ti][tj]==0){
                        tmp+=min1(cost[2],cost[1]);
                    }
                    if(marka[i][j]==0 && markb[ti][tj]==1){
                        tmp+=min1(cost[0],cost[3]);
                    }
                }
            }
            if(ans == -1){
                ans = tmp;
            }
            else{
                ans = min1(ans,tmp);
            }
        }while(next_permutation(biao,biao+n));//è¿æ ·å°±è½å¤å°ææçæåµé½èèè¿å»
        printf("Case #%d: %d\n",cas,ans);
        cas++;
    }

    return 0;
}