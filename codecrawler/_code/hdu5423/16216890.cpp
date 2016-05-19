#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int s[1005][1005],sum[1005],dis[1005];
int n;
void dfs(int x,int num){
    int i;
    dis[x]=num;
    for(i=1;i<=n;i++)
    if(s[x][i]&&!dis[i])
    dfs(i,num+1);
}                                       //dfsæ±åºæ¯ä¸ªèç¹çæ·±åº¦
int main(){
    int i,a,b,ans;
    while(scanf("%d",&n)!=EOF){
        memset(s,0,sizeof(s));
        memset(sum,0,sizeof(sum));
        memset(dis,0,sizeof(dis));
        for(i=1;i<=n-1;i++){
            scanf("%d%d",&a,&b);
            s[a][b]=s[b][a]=1;
        }
        dfs(1,1);
        for(i=1;i<=n;i++)
        sum[dis[i]]++;
        ans=0;
        for(i=1;i<=n;i++){
            if(sum[i]==1)
            ans++;
            else{
              if(sum[i+1]==0)
              ans=n;
              break;
            }                               //åªæå½æ¯ä¸ªæ·±åº¦é½åªæä¸ä¸ªèç¹æè
        }                                   //åªæææ·±çé£ä¸å±èç¹ä¸ä¸º1æ¶ææ¯
        if(ans==n)                          //ç¹æ®çæ°
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
