#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 111111;

//filter prim
int prim[maxn],isprim[maxn];
int primnum=0;
void initprim(){
    memset(isprim,-1,sizeof isprim);
    isprim[0]=isprim[1]=0;
    prim[primnum++] = 2;
    for(int i=4;i<maxn;i+=2){
        isprim[i]=0;
    }
    for(int i=3;i<maxn;i+=2){
        if(isprim[i]){
            prim[primnum++]=i;
            for(int j=i+i;j<maxn;j+=i){
                isprim[j]=0;
            }
        }
    }
}

//get factor
int has[maxn];
int factor[maxn][6];
int factornum[maxn];
void getfactor(){
    for(int num=2;num<maxn;num++){
        int n=num,cnt = 0;
        for(int i=0;i<primnum;i++){
            if(isprim[n]) {
                factor[num][cnt++]=n;
                break;
            }
            if(n%prim[i]==0){
                factor[num][cnt++]=prim[i];
                while(n%prim[i]==0){
                    n/=prim[i];
                }
            }
        }
        factornum[num]=cnt;
    }
}

// count the number of factors of every number
int num[maxn],cntExtend[maxn];
void factorExtend(int len){
    memset(cntExtend,0,sizeof cntExtend);
    for(int i=1; i<maxn; i++){
        for(int j=i; j<maxn; j+=i){
            if(has[j])
                cntExtend[i]++;
        }
    }
}

//for every single factor in each number, find out how many numbers is not co-prime with it
LL solve(int len){
    LL re = 0;
    for(int i=0; i<len; i++){
        int n = num[i];
        if(n==1) continue;
        int facnum = factornum[n];
        LL sum=0;
        for(int k=(1<<facnum)-1; k>0; k--){
            int mul=1,b=0;
            for(int j=0; j<facnum; j++){
                if((1<<j) & k) {
                    mul*=factor[n][j];
                    b^=1;
                }
            }
            if(b){
                sum+=cntExtend[mul]-1;
            }else{
                sum-=cntExtend[mul]-1;
            }
        }
        re+=(sum)*(len-1-sum);
    }
    return re;
}

int main(){
//    freopen("data.in","r",stdin);
    int T,n,x;
    initprim();
    getfactor();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(has,0,sizeof has);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            has[x]++;
            num[i]=x;
        }
        factorExtend(n);
        LL ans = (LL)n*(n-1)*(n-2)/6 - solve(n)/2;
        printf("%I64d\n",ans);
    }

}
