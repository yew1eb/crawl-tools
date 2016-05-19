#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

const int MAX__ = 1000010;
int vis[MAX__],dis[MAX__];

void init(){
    int i;
    memset(vis,-1,sizeof(vis));
    vis[0] = 0;
    int tmp = 1;
    for(i = 1;i < MAX__;i++){
        if(vis[i]==-1){
            vis[i] = i+tmp;
            dis[tmp] = i;
            if(i+tmp < MAX__) vis[i+tmp] = i;
            tmp++;
        }
    }
}

int main(){
    //freopen("d:\\1.txt","w",stdout);
    int a,b, tmp1, tmp2;
    init();
    while(~scanf("%d%d",&a,&b),a||b){
        if(vis[a] == b || vis[b] == a){
            printf("0\n");
            continue;
        }
        printf("1\n");
        if(a == b){
            printf("0 0\n");
            if(vis[a] < b)  {
                printf("%d %d\n",min(a,vis[a]),max(a,vis[a]));
            }
            continue;
        }
        if(a == 0 || b == 0){
            printf("0 0\n");
            continue;
        }
        if((b-a == vis[dis[b-a]] - dis[b-a])
            ||(b-a == dis[b-a] - vis[dis[b-a]])){
                if(dis[b-a] < a){
                    tmp1 = min(vis[dis[b-a]],dis[b-a]);
                tmp2 = max(vis[dis[b-a]],dis[b-a]);
                printf("%d %d\n",min(vis[dis[b-a]],dis[b-a])
                       ,max(vis[dis[b-a]],dis[b-a]));
                }

            }
        if(vis[a] < b){


            if( tmp1 != min(a,vis[a]))
            printf("%d %d\n",min(a,vis[a]),max(a,vis[a]));
        }
        if(vis[b] < a){

            if( tmp1 != min(b,vis[b]))
            printf("%d %d\n",min(b,vis[b]),max(b,vis[b]));
        }
    }
    return 0;
}
