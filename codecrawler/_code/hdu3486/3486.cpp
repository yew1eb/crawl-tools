#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>


#define N 200020
using namespace std;
int RMQ[N][20];
int log[N];
int query(int l,int r){
    int lg=log[r-l+1];
    return max(RMQ[l][lg],RMQ[r-(1<<lg)][lg]);
}
int main(){
    for (int i=0;i<18;i++)
        for (int j=1<<i;j<(1<<(i+1))&&j<N;j++)
            log[j]=i;
    int n,k;
    while (scanf("%d%d",&n,&k)==2){
        if (n<0&&k<0) break;
        for (int i=1;i<=n;i++)
            scanf("%d",&RMQ[i][0]);
        for (int j=1;j<18;j++)
            for (int i=1;i<=n;i++){
                if (i+(1<<j)>n) break;
                RMQ[i][j]=max(RMQ[i][j-1],RMQ[i+(1<<(j-1))][j-1]);
            }
        int ans=-1;
        int sum;
        for (int i=1;i<=n;i++){
            int seg=n/i;
            int l,j;
            if (i>1&&seg==n/(i-1)){
                l=seg*(i-1)+1;
                j=i;
            }
            else {
                l=1;
                sum=0;
                j=1;
            }
            for (;j<=i;j++){
                sum=sum+query(l,l+seg-1);
                l=l+seg;
            }
            if (sum>k) {ans=i;break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}