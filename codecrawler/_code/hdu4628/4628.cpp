 #include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = (1<<16)+10;

char str[20];
bool check[MAXN];
int f[MAXN];
int maxSta;

bool isPalind(int st, int len){
    char sub[20];
    int idx = 0;
    for(int i=0; i<len; ++i){
        if( (st>>i)&1 )  
            sub[idx++] = str[i];
    }
    for(int i=0; i<idx/2; ++i){
        if(sub[i] != sub[idx-1-i]) 
            return false;
    }
    return true;
}

int main(){

    int T;
    scanf("%d", &T);
    check[0] = false;
    while(T--){
     
        scanf("%s", str);
        int len = strlen(str);
        maxSta = (1<<len)-1;
        for(int i=1; i<=maxSta; ++i){
            check[i] = isPalind(i, len);                       
        }

        memset(f, 0x7f, sizeof(f));
        f[0] = 0;
        for(int i=1; i<=maxSta; ++i){
            for(int s=i; s; s=(s-1)&i)
                if(check[s])
                    f[i] = min(f[i], f[i^s]+1);
        }
        printf("%d\n", f[maxSta]);

    }
    return 0;
}