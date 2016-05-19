#include<iostream>
#include<cstring>
#include<cstdio>
#define M 100+10
#define LL long long
using namespace std;
int n,m;
LL ans;
int main()
{
    int T;
    cin>>T;
    while(T--){
        ans=0;
        scanf("%d %d",&n,&m);
        if(n==1&&m==1){
            printf("1\n");
            continue;
        }
        if(n==1||m==1){
            if(n==1){
                for(int j=1;j<=m;++j){
                    if(j&1){
                        if(j==1||j==m){
                            ans+=2;
                        }
                        else ans+=4;
                    }
                }
            }
            else if(m==1){
                for(int j=1;j<=n;++j){
                    if(j&1){
                        if(j==1||j==n){
                            ans+=2;
                        }
                        else ans+=4;
                    }
                }
            }
            printf("%I64d\n",ans);
            continue;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if((i+j)%2==0){
                    if((i==1&&j==1)||(i==1&&j==m)||(i==n&&j==1)||(i==n&&j==m)){
                        ans+=4;
                    }
                    else if(i==1||j==1||i==n||j==m){
                        ans+=8;
                    }
                    else ans+=16;
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}