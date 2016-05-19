#include<stdio.h>
#include<string.h>
#include<map>
#include<iostream>
using namespace std;
#define N 100010
#define MOD 1000000007

int num[N];
map<int,int> mapex;//å»äºå§ï¼å¶å®ä¸ç»´çå°±å¤äºï¼æåé¢çä»¥ç¸åçæ°ä¸ºç»å°¾çé½å èµ·æ¥ï¼çæ¶é´åçç©ºé´ã

long long int km(long long int x,long long int y){
    long long int ans=1;

    while(y){
        if(y%2){
            ans=ans*x%MOD;
        }
        y=y/2;
        x=x*x%MOD;
    }

    return ans;
}

int main(){
    int t;
    int n;
    long long int ans;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }

        mapex.clear();//è®°ä½ï¼æ¯clearï¼ä¸æ¯erase
        ans=0;
        for(int i=0;i<n;i++){
            //printf("%d %lld %lld\n",mapex[num[i]],km(2,n-i-1),km(2,i));
            long long int tempfro=((km(2,i)-mapex[num[i]])%MOD+MOD)%MOD;
            ans=(ans+tempfro*km(2,n-1-i)%MOD*num[i]%MOD)%MOD;
            mapex[num[i]]=(mapex[num[i]]+km(2,i))%MOD;
        }

        printf("%lld\n",ans);
    }

    return 0;
}
