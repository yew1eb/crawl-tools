#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define Maxn 30
#define inf 10000000
using namespace std;
int ans,n,m;
int c,d;
int map[Maxn][Maxn];
int lis[Maxn],node[Maxn];
int val[1<<17],sum[1<<17];
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m),n||m){
        memset(val,48,sizeof(val));
        memset(sum,0,sizeof(sum));
        c=1000000,d=1;
        for(i=1;i<=n;i++)
            scanf("%d",&node[i]);
        memset(map,0,sizeof(map));
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        int N=1<<n;
        N-=1;
        int cnt=0;
        val[0]=0;
        for(i=0;i<=n;i++)
            val[1<<i]=0;
        for(i=1;i<=N;i++){
            cnt=0;
            for(j=0;j<n;j++){
                if(i&(1<<j)) lis[++cnt]=j+1,sum[i]+=node[j+1];
            }
            if(cnt>m) continue;
            if(cnt==m)
            {
                int a=val[i],b=sum[i];
                if(a*d<c*b){
                    ans=i;
                    c=a;
                    d=b;
                }
            }
            int temp;
            for(j=0;j<n;j++){
                if(((1<<j)&i)==0){
                    temp=inf;
                    for(int k=1;k<=cnt;k++){
                        temp=min(temp,map[j+1][lis[k]]);
                    }
                    val[i|(1<<j)]=min(val[i]+temp,val[i|(1<<j)]);
                }
            }
        }
        int num=1;
        for(j=0;j<n;j++)
            if((1<<j)&ans){
                printf("%d",j+1);
                if(num!=m)
                    printf(" ");
                num++;
            }
        printf("\n");
    }
    return 0;
}