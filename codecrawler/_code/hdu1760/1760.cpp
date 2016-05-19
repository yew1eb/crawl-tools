// I'm lanjiangzhou
//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//C++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <deque>
#include <set>
using namespace std;

//*************************OUTPUT*************************
#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

//**************************CONSTANT***********************
#define INF 0x3f3f3f3f

// aply for the memory of the stack
//#pragma comment (linker, "/STACK:1024000000,1024000000")
//end

int n,m;
const int maxn =110;
char s[maxn][maxn];
int a[maxn][maxn];
int mm[maxn][maxn];

int findset(int mm[maxn][maxn]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(mm[i][j]+mm[i+1][j]+mm[i][j+1]+mm[i+1][j+1]==0){
                int tt[maxn][maxn];
                for(int x=0;x<n;x++){
                    for(int y=0;y<m;y++){
                        tt[x][y]=mm[x][y];
                    }
                }
                tt[i][j]=tt[i+1][j]=tt[i][j+1]=tt[i+1][j+1]=1;
                if(findset(tt)==0) return 1;
            }
        }
    }
    return 0;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        //getchar();
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
            for(int j=0;j<m;j++)
                a[i][j]=s[i][j]-'0';
        }
        if(findset(a)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}