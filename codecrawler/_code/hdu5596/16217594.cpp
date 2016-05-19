#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
#define LL long long
const int maxn=50002;
int n,t;
struct point
{
    int id,v;
}a[maxn];
int add[maxn];
int main()
{
    int m;
    cin>>t;
    int c;
    while(t--){
        memset(add,0,sizeof(add));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].id,&a[i].v);
        for(int i=0;i<m;i++){
            scanf("%d",&c);
            add[c]++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
           // if(add[i+1]){
                a[i].v+=m-cnt;
                cnt+=add[i+1];
            //}
        }
        //  for(int i=0;i<n;i++)cout<<a[i].v<<endl;
        int max1=-100000000,max0=-100000000;
        for(int i=n-1;i>=0;i--){
            if(a[i].id){
                if(a[i].v<max0)n--;
                max1=max(a[i].v,max1);
            }
            else{
                if(a[i].v<max1)n--;
                max0=max(a[i].v,max0);
            }
        }
        printf("%d\n",n);
    }
    return 0;
}