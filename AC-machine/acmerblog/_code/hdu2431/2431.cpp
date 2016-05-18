/***************************************
* File Name:2431.cpp
* Created Time:2013年12月14日 10:56:21
***************************************/
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 501;
const int mod = 1000007;
int f[maxn];

void init(){
    f[0] = 1;
    for (int i=2; i<maxn; i++){
        for (int j=i; j<maxn; j++){
            f[j] += f[j-i];
            if (f[j] >= mod){
                f[j] -= mod;
            }    
        }
    }
}
int main(){
    int T;
    int n;
    init();
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        printf("%d\n",f[n]);
    }
    return 0;
}