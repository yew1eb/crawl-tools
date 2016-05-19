#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<stdlib.h>

using namespace std;

int n,m;
int v[1010];
int map[1001][1001];

int main() {
    while(scanf("%d",&n)!=EOF) {
        memset(map,0,sizeof(map));
        memset(v,0,sizeof(v));
        int x,y;
        int pf;
        for(int i=0; i<n-1; i++) {
            scanf("%d%d",&x,&y);
            map[x][y] = 1;
            map[y][x] = 1;
            if(x == 1) {
                pf = y;
            } else if(y == 1) {
                pf = x;
            }
            v[x]++;
            v[y]++;
        }
        int rt = 0;
        int cnt = 0,ans = 0,pt = 0;
        for(int i=1; i<=n; i++) {
            if(v[i] == 1) {
                ans++;
            } else if(v[i] == 2) {
                cnt++;
            }else{
                rt = i;
                pt++;
            }
        }
        if(pt>=2){
            printf("NO\n");
            continue;
        }
        if(v[1]!=1) {
            if(v[1] == n-1) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }else{
            if(cnt + ans +1 >= n && v[pf] <=2){
                int flag = 0;
                if(pt>0){
                    for(int i=1;i<=n;i++){
                        if(map[rt][i] == 1 && v[i]!=1){
                            flag++;
                        }
                    }
                }
                if(flag <= 1){
                    printf("YES\n");
                }else{
                    printf("NO\n");
                }

            }else{
                if(v[pf] == n-1){
                    printf("YES\n");
                    continue;
                }
                printf("NO\n");
            }
        }

    }
    return 0;
}