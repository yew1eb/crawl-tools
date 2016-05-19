#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<29
using namespace std;
int n,k,a[2005];
int b[2005][2005];   //å­æ¾iå°jçæå°å·®å¼
int dp[2005][26]={0};   //dp[i][j]è¡¨ç¤ºåiä¸ªæ°ï¼åä¸ºjæ®µçæä¼è§£
//ä»¥ä¸ä¸¤ä¸ªä¼åéåï¼è®°å½ä¸­ä½æ°
//å¦æä¸ºå¥æ°ä¸ªåç´ ï¼ä¸­ä½æ°ä¾¿æ¯å¤§çéé¢çæå°å¼
//å¦æä¸ºå¶æ°åä¸ºå°çæå¤§å¼ä¸å¤§çæå°å¼ä¹é´çä»»ææ°
priority_queue<int>lower;
priority_queue<int,vector<int>,greater<int> >upper;
int main(){
    while(scanf("%d%d",&n,&k)!=EOF&&n+k){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=inf;
        for(int i=1;i<=n;i++){
            while(!lower.empty()) lower.pop();
            while(!upper.empty()) upper.pop();
            int sum=0; //sumè¡¨ç¤ºå¤§å åä¸å°å åçå·®
            for(int j=i;j<=n;j++){
                //å¤æ­æ¯å å¥å°çï¼è¿æ¯å¤§ç
                if(lower.empty()||a[j]<=lower.top()){
                    lower.push(a[j]);
                    sum-=a[j];
                }
                else{
                    upper.push(a[j]);
                    sum+=a[j];
                }
                //è®¡ç®å°å éé¢çæ°éï¼å¤§å éé¢çæ°é
                int low=(j-i+1)/2,high=(j-i+1)-low;
                //ä½ä¸æ¬¡è°æ´ï¼ä½¿å¾æ°éä¿æä¸è´
                if(lower.size()>low){
                    upper.push(lower.top());
                    sum+=lower.top()*2;
                    lower.pop();
                }
                if(upper.size()>high){
                    lower.push(upper.top());
                    sum-=upper.top()*2;
                    upper.pop();
                }
                //åé¢çè°æ´å¯è½ä½¿é¡ºåºéä¹±ï¼å°å°çéé¢çæå¤§å¼åå¤§çéé¢çæå¤§å¼æ¯è¾
                //ä½äº¤æ¢è°æ´
                while(lower.size()&&upper.size()&&lower.top()>upper.top()){
                    int u=lower.top(),v=upper.top();
                    lower.pop();upper.pop();
                    sum=sum+2*u-2*v;
                    lower.push(v);upper.push(u);
                }
                int ans=sum;
                //å¦æä¸ªæ°ä¸ºå¥æ°ï¼è¯´æä¸­ä½æ°ä¸ºå¤§çéé¢çæå°å¼ï¼è¦åæ
                if(high>low) ans-=upper.top();
                b[i][j]=ans;
            }
        }
        //n^2*kçDP
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int r=0;r<i;r++)
                   dp[i][j]=(dp[r][j-1]+b[r+1][i])<dp[i][j]?(dp[r][j-1]+b[r+1][i]):dp[i][j];
            }
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
