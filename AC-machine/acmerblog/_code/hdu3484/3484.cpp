#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define N 110
using namespace std;
int n,m;
int map[N][N];
int a[N][N];
int b[N][N];

bool solve(){
    for (int i=2;i<=m;i++){
        int flag=0;
        for (int j=1;j<=n;j++)
            if (a[j][i]!=b[j][i]) {flag=1;break;}
        if (!flag) continue;
        int exc=0;
        for (int j=i+1;j<=m;j++){
            flag=0;
            for (int t=1;t<=n;t++)
                if (a[t][j]!=b[t][i]) {flag=1;break;}
            if (flag) continue;
            exc=1;
            for (int t=1;t<=n;t++)
                swap(a[t][j],a[t][i]);
            break;
        }
        if (!exc) return false;
    }
    return true;
}

int main(){
    while (scanf("%d%d",&n,&m)==2){
        if (n<0&&m<0) break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&b[i][j]);
        int flag=0;
        for (int i=1;i<=m;i++){

            for (int j=1;j<=n;j++)
                for (int t=1;t<=m;t++)
                    a[j][t]=map[j][t];

            for (int j=1;j<=n;j++)
                swap(a[j][1],a[j][i]);

            for (int j=1;j<=n;j++){
                if (a[j][1]!=b[j][1]){
                    for (int t=1;t<=m;t++)
                        a[j][t]=1-a[j][t];
                }
            }

            if (solve()) {flag=1;break;}
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
