#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=1001;
int dp[MAX],s[MAX];//dpä¸ºè½å¤å°è¾¾å½åè¿ä¸ªä½ç½®æ¶å¯å¾çæå¤§å¼. 

int main(){
    int n;
    while(cin>>n,n){
        for(int i=0;i<n;++i){
            cin>>s[i];
        }
        dp[0]=s[0];
        int Max=dp[0];
        for(int i=1;i<n;++i){
            int sum=s[i];
            for(int j=0;j<i;++j){//æ±dp[i]çæå¤§å¼å°±æ¯æ±å¨iä»¥åçæ¯s[i]å°çæå¤§çdp[j]+s[i]; 
                if(s[i]>s[j])sum=max(sum,dp[j]+s[i]);
            }
            dp[i]=sum;
            Max=max(Max,dp[i]); 
        }
        cout<<Max<<endl;
    }
    return 0;
}