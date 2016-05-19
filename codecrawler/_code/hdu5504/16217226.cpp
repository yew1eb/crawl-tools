#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 70
typedef __int64 ll;
ll a[maxn],res;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
        sort(a+1,a+1+n);
        if(n==1){
            printf("%d\n",a[1]);
            continue;
        }
        if(a[1]==0&&a[n]==0){
            printf("0\n");
            continue;
        }
        int num1=0;    //å¥æ°çä¸ªæ°ï¼ 
        for(int i=1;i<=n;i++){
            if(a[i]<0) num1++;
        }
        ll t1=1;
        if(num1%2==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) continue;
                else t1=t1*a[i];
            }
            printf("%I64d\n",t1);
        }
        else{    //æå¥æ°ä¸ªè´æ°ï¼ 
            int tx=0;
            bool ff=false;
            res=0;
            ll t2=1;
            int num1=0,num2=0;
            for(int i=1;i<=n;i++){
                if(a[i]<0) num1++;
                else if(a[i]==0) num2++;
            }
            for(int i=1;i<=n;i++){
                if(a[i]<0){
                    t1=t1*a[i];
                    if(a[i]>res||res==0) res=a[i];
                }
                else if(a[i]>0){
                    t2=t2*a[i];
                }
            }
            if(t1<0) t1=t1/res;
            ll ans=0;
            if(num1+num2==n){
                ans=0;
                if(num1>1){
                    ans=t1;
                }
            }
            else {
                ans=t1*t2;
            }
            printf("%I64d\n",ans);
            
        }
    }
}
/*
1
3
0 -1 0

*/