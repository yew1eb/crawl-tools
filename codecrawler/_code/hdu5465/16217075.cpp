#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 505
int a[N][N];
int sum[N][N];
int n,m,q;
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y,int k)
{
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            sum[i][j]^=k;
        }
    }
}
int query(int x,int y)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ans^=sum[i][j];
        }
    }
    return ans;
}
int main()
{
    int T,x1,x2,y1,y2,k;
    scanf("%d",&T);
    while(T--){
        memset(sum,0,sizeof(sum));
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                update(i,j,a[i][j]);
            }
        }
        while(q--){
            scanf("%d",&k);
            if(k==1){
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int ans = 0;
               ans ^= query(x2, y2);
               if(y1 > 1) ans ^= query(x2, y1 - 1);
                if(x1 > 1) ans ^= query(x1 - 1, y2);
               if(x1 > 1 && y1 > 1) ans ^= query(x1 - 1, y1 - 1);
                if(ans == 0) {
                    printf("No\n");
                } else {
                    printf("Yes\n");
                }

            }
            else{
                scanf("%d%d%d",&x1,&y1,&x2);
                update(x1,y1,a[x1][y1]^x2);
                a[x1][y1]=x2;
            }
        }
    }
    return 0;
}
