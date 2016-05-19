#include <cstdio>
#include <cstring>
using namespace std;

int len,lim;
int num[20],mi[20],mii[20];
int dp[10][5000];

int dfs(int pos,int sta,int doing){
    if(pos==-1){
        if(sta<=lim) return 1;
        return 0;
    }
    if(!doing){
        if(dp[pos][sta]!=-1) return dp[pos][sta];
    }
    int sum=0;
    int l=0,r;
    if(doing) r=num[pos];
    else r=9;
    for(int i=l;i<=r;i++){
        int tem=sta+i*mi[pos];
        if(!doing && tem+9*(mi[pos]-1)<=lim) sum+=mii[pos];
        else if(tem>lim) ;
        else if(tem==lim){
            sum++;
        }
        else{
            if(doing && i==r)
                sum+=dfs(pos-1,tem,1);
            else sum+=dfs(pos-1,tem,0);
        }
    }
    if(!doing) dp[pos][sta]=sum;
    return sum;
}

int solve(int b){
    int i=0;
    while(b){
        num[i++]=b%10;
        b/=10;
    }
    len=i;
    memset(dp,-1,sizeof(dp));
    return dfs(len-1,0,1);
}

int main(){
    //freopen("a.txt","r",stdin);
    //freopen("c.txt","w",stdout);
    int t,T;
    int tem,a,b;
    mi[0]=1;mii[0]=1;
    for(int i=1;i<10;i++) mi[i]=mi[i-1]*2,mii[i]=mii[i-1]*10;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d",&a,&b);
        lim=0;tem=1;
        while(a){
            lim+=tem*(a%10);
            tem*=2;
            a/=10;
        }
        printf("Case #%d: %d\n",t,solve(b));
    }
    return 0;
}