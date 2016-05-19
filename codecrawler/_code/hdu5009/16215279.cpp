#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cstdio>

using namespace std;

struct node{
    int val;
    int idx;
    int rnk;
};
node a[50010];
bool vis[50010];
int dp[50010];
int vec[50010];     //æ°ç»ä¼åï¼é¿åæ¯æ¬¡æ¸ç©ºå¨é¨visæ°ç»

bool cmp1(node n1,node n2){
    return n1.val<n2.val;
}

bool cmp2(node n1,node n2){
    return n1.idx<n2.idx;
}

int main(){
    int n;
    a[0].val=-1;
    while(~scanf("%d",&n)){
        int m=0;
        for(int i=1;i<=n;i++){
            int t;
            scanf("%d",&t);
            if(a[m].val!=t)m++;
            a[m].idx=m;
            a[m].val=t;
        }

        sort(a+1,a+m+1,cmp1);
        int k=0;
        for(int i=1;i<=m;i++){
            if(a[i].val!=a[i-1].val)k++;
            a[i].rnk=k;
        }
        sort(a+1,a+m+1,cmp2);
        for(int i=0;i<=m;i++)dp[i]=i;

        for(int i=0;i<m;i++){
            int cnt=0;
            int siz=0;
            for(int j=i+1;j<=m;j++){
                if(!vis[a[j].rnk]){
                    vec[siz++]=a[j].rnk;
                    vis[a[j].rnk]=1;
                    cnt++;
                }
                if(dp[i]+cnt*cnt>=dp[m])break;  //ä¸å¯è½åå¾æä¼è§£åæ¶è·³åº
                dp[j]=min(dp[j],dp[i]+cnt*cnt);
            }
            for(int j=0;j<siz;j++){
                vis[vec[j]]=0;
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
