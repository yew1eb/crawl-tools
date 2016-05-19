#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
int n;
ll W,H;
int a[200010];
ll max(ll t1,ll t2){
    if(t1>=t2){
        return t1;
    }
    return t2;
}
ll min(ll t1,ll t2){
    if(t1<=t2){
        return t1;
    }
    return t2;
}
int main(){
    while(scanf("%d%lld%lld",&n,&W,&H)!=EOF){
        ll s=W*H;
        ll ans=s;
        for(int i=0;i<W;i++){
            a[i]=0;
        }
        int len=W+n;
        for(int i=W;i<len;i++){
            scanf("%d",&a[i]);
            s-=a[i];
        }
        len+=W;
        for(int i=W+n;i<len;i++){
            a[i]=0;
        }
        if(s>0){
            printf("-1\n");
        }
        else{
            ll mn,mx;
            mn=ans;
            mx=0;
            for(int i=W;i<len;i++){
                int j=i-W;
                if(a[j]<=H){
                    mn-=H-a[j];
                }
                else{
                    mx-=a[j]-H;
                }

                if(a[i]<=H){
                    mn+=H-a[i];
                }
                else{
                    mx+=a[i]-H;
                }
                ans=min(ans,max(mx,mn));
            }
            printf("%lld\n",ans);
        }

    }
    return 0;
}
