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
int a[500000],b[500000],cnt;
void Search1(int n,int m){
    int low=0,high=cnt,mid;
    while(low<=high){
        mid=(high+low)>>1;
        if(n==a[mid]){
            if(m>b[mid])
                printf("%d %d\n",a[mid],b[mid]);
            return;
        }
        if(a[mid]<n)
            low=mid+1;
        else
            high=mid-1;
    }
}
void Search2(int n,int m){
    int low=0,high=cnt,mid;
    while(low<=high){
        mid=(high+low)>>1;
        if(n==b[mid]){
            if(m>a[mid])
                printf("%d %d\n",a[mid],b[mid]);
            return;
        }
        if(b[mid]<n)
            low=mid+1;
        else
            high=mid-1;
    }
}
int main(){
    for(int i=0;i<500000;i++){
        a[i]=(int)(i*(sqrt(5.0)+1)/2);
        b[i]=a[i]+i;
        if(b[i]>=1000000){
            cnt=i;
            break;
        }
    }
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        if(n>m)
            swap(n,m);
        if(n==(int)((sqrt(5.0)+1)*(m-n)/2))
            printf("0\n");
        else{
            printf("1\n");
            if(m-n<cnt&&n-a[m-n]==m-b[m-n])
                printf("%d %d\n",a[m-n],b[m-n]);
            Search1(n,m);
            if(n!=m)
                Search1(m,n);
            Search2(n,m);
            if(n!=m)
                Search2(m,n);
        }
    }

    return 0;
}