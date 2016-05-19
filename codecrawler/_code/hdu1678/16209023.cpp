#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std; 
int a[20010];
bool cmp(int a,int b)
{
    return a>b;
}
int main(){
    int t,n,i,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++) 
            scanf("%d",&a[i]);
        sum=0;
        sort(a,a+n,cmp);
        for(i=2;i<n;i+=3)
            sum+=a[i];
        printf("%d\n",sum);
    }
    return 0;
}