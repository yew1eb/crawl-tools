//è¿ä¸é¢é¢ç®ä¸­ç»åºçæ¯éä¸­çæ¦çï¼æä»¬è¦å°å¶è½¬åä¸ºéä¸ä¸­çæ¦çï¼ç¶åç¨ï¼1-ææéä¸ä¸­æ¦çç¸ä¹ï¼å°±æ¯éä¸­çæ¦ç
//å°0,1èåè½¬åä¸ºäºdp[i]=min(dp[i],dp[i-value[i]]*weight[i]); 
#include<iostream>
#include<iomanip>
using namespace std;

double dp[10005];
int value[10005];
double weight[10005];
int n,m,i,j;

int main(){
    while(cin>>n>>m){
        if(n==0&&m==0)
            break;
        for(i=1;i<=m;i++){
            cin>>value[i]>>weight[i];
            weight[i]=1-weight[i];    
        }
        for(i=0;i<10005;i++)
            dp[i]=1;
        for(i=1;i<=m;i++)
            for(j=n;j>=0;j--){
                if(j-value[i]>=0)
                    dp[j]=min(dp[j],dp[j-value[i]]*weight[i]);
            }
        cout<<setiosflags(ios::fixed);
        cout<<setprecision(1)<<(1-dp[n])*100<<"%"<<endl;
    }    
    return 0;
} 
