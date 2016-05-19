#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int score[]={0,1000,1500,2000,2500};

int main(){
    int T,A,B,ansk=0;
    scanf("%d",&T);
    while(T--){

        int ans=0,now;
        for(int i=1;i<=4;i++){
            scanf("%d%d",&A,&B);
            now=score[i]/250*(250-A)-B*50;
            ans+=max(now,(int)(score[i]*0.4));
        }

        printf("Case #%d: %d\n",++ansk,ans);
    }
    return 0;
}