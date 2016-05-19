#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
#define ll long long
ll x[100010];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%I64d",&x[i]);
        }
        sort(x,x+n);
        ll sum=0;
        for(int i=0;i<n-1;i++){
            int left=i+1;
            int right=n-1;
            int mid=(left+right)>>1;
            while(1){
                int t_mid=mid;
                if(x[mid]-x[i]>k){
                    right=mid-1;
                }
                else if(x[mid]-x[i]<k){
                    left=mid+1;
                }
                else{
                    break;
                }
                mid=(left+right)>>1;
                if(t_mid==mid){
                    break;
                }
            }
            if(x[mid]-x[i]<=k){
                sum+=(ll)mid-i;
            }
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
