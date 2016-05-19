#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        if(n<k){
            printf("0\n");
            continue;
        }
        int r=n%k;
        if(r<=k/2){
            int ans=n*n-r*r;
            printf("%d\n",ans);
        }
        else{
            int ans=n*n-(k-r)*(k-r);
            printf("%d\n",ans);
        }
    }
    return 0;
}
