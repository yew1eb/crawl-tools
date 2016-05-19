//hdu 5317
//é¢å¤ç+æ´å
#include<cstdio>
#include<algorithm>
using namespace::std;

typedef long long LL;
const int N = 1000005;

int F[N],num[N][10];
void init(){
    F[0]=F[1]=0;
    for(int i=2;i<N;i++){
        if(F[i])continue;
        for(int j=1;j*i<N;j++){
            F[i*j]++;
        }
    }
    for(int i=2;i<N;i++){
        for(int j=1;j<10;j++)
        {
            num[i][j]=num[i-1][j];
        }
        num[i][F[i]]++;
    }
}
//
int B[10];
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
int main(){
    int T,l,r;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&l,&r);
        int ans=0;
        for(int i=1;i<10;i++){
            B[i]=num[r][i]-num[l-1][i];
            if(num[r][i]-num[l-1][i]>1){
                ans=i;
            }
        }
        if(ans!=0)   printf("%d\n",ans);
        else if((B[2]>0&&B[4]>0)||(B[2]>0&&B[6]>0)||(B[6]>0&&B[4]>0))
            printf("2\n");
        else if(B[3]>0&&B[6]>0)printf("3\n");
        else printf("1\n");
    }
    return 0;
}