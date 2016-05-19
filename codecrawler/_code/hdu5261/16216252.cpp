#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e5+10;
typedef long long ll;

int n;
ll q[N*5],qs[N*5],h[N*2],r;

int main(){
    int T,cas=0;
    cin >> T;
    ll ans=0;
    int ax,ay;
    while(T--){
        scanf("%d%I64d",&n,&r);
        ll ans=0;
        int ax=n,ay=n;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&h[i]);
            h[i+n] = h[i];
        }
        int front=0, rear = 0;
        for(int i=1;i<=2*n;i++){
            while(front<rear && (i-q[front])*2>n) front++;

            if(front<rear &&(i-q[front])*2<=n && h[i]+(ll)r*i+qs[front]>=ans){
                if(h[i]+(ll)r*i+qs[front]>ans){
                    int tx,ty;
                    ans = h[i]+(ll)r*i+qs[front];
                    tx = q[front]; ty = i;
                    if(tx>n) tx-=n;
                    if(ty>n) ty-=n;
                    if(tx>ty) ax=ty , ay=tx;
                    else ax=tx , ay=ty;
                }
                else if(h[i]+(ll)r*i+qs[front]==ans){
                    int tx,ty;
                    tx = q[front]; ty = i;
                    if(tx>n) tx-=n;
                    if(ty>n) ty-=n;
                    if(tx>ty) swap(tx,ty);
                    if((tx<ax)||(tx==ax&&ty<ay)){
                        ax = tx , ay = ty;
                    }
                }
            }

            while(front<rear && h[i]-(ll)r*i>qs[rear-1]) rear--;
            q[rear]=i;
            qs[rear] = h[i]-(ll)r*i;
            rear++;
        }
        printf("Case #%d:\n",++cas);
        printf("%d %d\n",ax,ay);
    }
    return 0;
}
