#include<iostream>
#define INF 10000007
using namespace std;
int t,n,a,b,c;
int dp[20005];//å ä¸ºæ´ä½ç§»å¨äº10000ï¼ä¹å°±æ¯é¶ç¹ç§»å¨å°äº10000ï¼æä»¥æ°ç»å¤§å°ä¸º20000 
int max(int i,int j)
{
    return i>j?i:j;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<20006;i++) dp[i]=-INF;
        dp[10000]=0;
        int l=10000,r=10000;
        while(n--){
            cin>>a>>b>>c;
            b+=10000;
            if(a<0){
                for(int i=b;i<=r;i++)
                    dp[i+a]=max(dp[i+a],dp[i]+c);
                l+=a;
            }
            else{
                for(int i=b;i>=l;i--)
                    dp[i+a]=max(dp[i+a],dp[i]+c);
                r+=a;
            }
        }
        int ans=-INF;
        for(int i=l;i<=r;i++)  ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
}