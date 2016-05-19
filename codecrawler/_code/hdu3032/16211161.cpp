#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#define LL long long
#define N 1000000
#define inf 1<<20
using namespace std;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int k,ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&k);
            if(k%4==1||k%4==2)
                ans^=k;
            else if(k%4==0)
                ans^=(k-1);
            else
                ans^=(k+1);
        }
        if(ans)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}
