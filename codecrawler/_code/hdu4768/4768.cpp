#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=20010;
long long A[maxn],B[maxn],C[maxn];
long long cal(long long mid,int n){
    long long sum=0;
    for (int i=0;i<n;i++){
        long long up=min(mid,B[i]);
        if (up>=A[i])
        sum+=(up-A[i])/C[i]+1;
    }
//    cout<<mid<<" "<<sum<<endl;
    return sum;
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++){
            cin>>A[i]>>B[i]>>C[i];
        }
        long long L=0,R=1LL<<31;
        while (L<R){
            long long mid=(L+R)/2;
            if (cal(mid,n)%2) R=mid;
            else L=mid+1;
        }
        if (L==1LL<<31)
            cout<<"DC Qiang is unhappy."<<endl;
        else {
            while (cal(L,n)%2==0) L--;
            cout<<L<<' '<<cal(L,n)-cal(L-1,n)<<endl;
        }
    }
    return 0;
}