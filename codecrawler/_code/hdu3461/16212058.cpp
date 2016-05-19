#include<cstdio>
#define N 10000005
#define MOD 1000000007
int f[N],n,m;
void init(){
    for(int i=0; i<=n; ++i)
        f[i]=i;
}
int find(int x){
    int i, j=x;
    while(j!=f[j])j=f[j];
    while(x!=j){i=f[x]; f[x]=j; x=i;}
    return j;
}
bool Union(int x,int y){
    int a=find(x),b=find(y);
    if(a==b)return false;
    f[a] = b;
    return true;
}
long long myPower(int n){
    long long sum=1, tmp=26;
    while(n){
        if(n&1){
            sum = sum*tmp;
            sum %= MOD;
        }
        tmp = (tmp*tmp)%MOD;
        n>>=1;
    }
    return sum;
}
int main(){
    int l,r;
    while(~scanf("%d%d",&n,&m)){
        int cnt=0;
        init();
        for(int i=0; i<m; ++i){
            scanf("%d%d",&l,&r);
            --l;
            if(Union(l,r)) ++cnt;
        }
        printf("%lld\n", myPower(n-cnt)%MOD);
    }
    return 0;
}