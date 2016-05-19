#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define MAXN 100 + 10
struct node{
    int l;
    int r;
    char op[5];
}a[MAXN];
int num[MAXN][MAXN];
int m,n;
int id;

bool sign(int x,int y){
    if(x>=0 && x<m && y>=0 && y<n){
        return true;
    }
    else{
        return false;
    }
}

int DFS(int x,int y,int sum){
    int i;
    int fx,fy;
    if(sum == id){
        return 1;
    }
    for(i=1;i<=a[sum].l;i++){
        if(a[sum].op[0] == 'L'){
            fx = x;
            fy = y - i;
        }
        if(a[sum].op[0] == 'R'){
            fx = x;
            fy = y + i;
        }
        if(a[sum].op[0] == 'U'){
            fx = x - i;
            fy = y;
        }
        if(a[sum].op[0] == 'D'){
            fx = x + i;
            fy = y;
        }
        if(num[fx][fy] == 1){
            return 0;
        }
        if(sign(fx,fy) == false){
            return 0;
        }
    }
    if(a[sum].op[0] == 'L'){
        for(i=a[sum].l;i<=a[sum].r;i++){
            fx = x;
            fy = y - i;
            if(num[fx][fy]==1 || sign(fx,fy)==false){
                break;
            }
            if(DFS(fx,fy,sum+1))
                return 1;
        }
    }
    if(a[sum].op[0] == 'R'){
        for(i=a[sum].l;i<=a[sum].r;i++){
            fx = x;
            fy = y + i;
            if(num[fx][fy]==1 || sign(fx,fy)==false){
                break;
            }
            if(DFS(fx,fy,sum+1)){
                return 1;
            }
        }
    }
    if(a[sum].op[0] == 'U'){
        for(i=a[sum].l;i<=a[sum].r;i++){
            fx = x - i;
            fy = y;
            if(num[fx][fy]==1 || sign(fx,fy)==false){
                break;
            }
            if(DFS(fx,fy,sum+1)){
                return 1;
            }
        }
    }
    if(a[sum].op[0] == 'D'){
        for(i=a[sum].l;i<=a[sum].r;i++){
            fx = x + i;
            fy = y;
            if(num[fx][fy]==1 || sign(fx,fy)==false){
                break;
            }
            if(DFS(fx,fy,sum+1)){
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    int T;
    int i,j;

    while(~scanf("%d",&T)){
        while(T--){
            memset(num,0,sizeof(num));
            scanf("%d%d",&m,&n);
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    scanf("%d",&num[i][j]);
                }
            }
            int idx = 0;
            while(1){
                scanf("%d%d",&a[idx].l,&a[idx].r);
                if(a[idx].l==0 && a[idx].r==0){
                    break;
                }
                scanf("%s",a[idx].op);
                idx++;
            }
            id = idx;
            int ans = 0;
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    if(num[i][j] == 0){
                        ans+=DFS(i,j,0);
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
}
