#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
 #define N 110
 #define M 5000
 int sum[M],ans[N];
 bool vis[M];
 int main(){
     int n,m;
     while(scanf("%d",&n),n){
        m=n*(n-1)/2;
        for(int i=1;i<=m;i++) scanf("%d",&sum[i]);
        for(int i=3;i<=m;i++){
            ans[2]=(sum[1]-sum[2]+sum[i])/2;
            ans[1]=sum[1]-ans[2];
            ans[3]=sum[2]-ans[1];
            if(ans[2]+ans[3]!=sum[i]) continue;
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            int k=3;//ä»ç¬¬ä¸ä¸ªå¼å§æé¤
            int flag=1;
            for(int j=4;j<=n&&flag;j++){
                while(vis[k]) k++;
                ans[j]=sum[k]-ans[1];
                vis[k]=1;
                /*æé¤ans[j]+ans[x](2<=x<j),è¿æ ·
                æå°sumå°±æäºans[j+1]+ans[1]çå¼*/
                for(int  x=2;x<j&&flag;x++)
                    for(int y=k+1;y<=m;y++){
                            flag=0;
                            if(!vis[y]&&ans[x]+ans[j]==sum[y]){
                                vis[y]=flag=1;
                                break;
                            }//if
                    }//for_y
            }//for
            if(flag) break;
        }//for
        for(int i=1;i<n;i++) printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
     }//while
    return 0;
 }
