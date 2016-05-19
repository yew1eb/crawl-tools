#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<algorithm>
#define MAXN 512345
#define mt(a,b) memset(a,b,sizeof(a))
using namespace std;

bool vis[30][30][30][30];
int ts[MAXN];
int len;

void init() {
    mt(vis,false);
    len = 0;
    for(int j=0; j<26; j++) {
        ts[len] = j;
        ts[len+1] = j;
        ts[len+2] = j;
        ts[len+3] = j;
        len += 4;
    }
    for(int i=0; i<len-3; i++) {
        vis[ts[i]][ts[i+1]][ts[i+2]][ts[i+3]] = true;
    }

//    for(int i=0;i<len;i++){
//        printf("%c",ts[i]+'a');
//    }
//    puts("");

    while(len<MAXN) {
        int num = 0;
        for(int i=0; i<26; i++) {
            if(!vis[ts[len-3]][ts[len-2]][ts[len-1]][i]) {
                vis[ts[len-3]][ts[len-2]][ts[len-1]][i] = true;
                ts[len] = i;
                len++;
            } else {
                num++;
            }
        }
        if(num == 26) break;
    }

//    cout<<"**********"<<endl;

}

int main() {
    init();
    int n;
    while(~scanf("%d",&n)) {
        if(n > len) {
            puts("Impossible");
        } else {
            for(int i=0; i<n; i++) {
                printf("%c",ts[i]+'a');
            }
            puts("");
        }
    }
    return 0;
}