#include<iostream>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cstdio>

using namespace std;

#define ll long long

int a[50];

bool vis[1050010];
ll dp[2][1050010];
vector<int> vec;

int main(){
    
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        cas++;
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        vec.clear();
        
        
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        
        vec.push_back(0);
        vis[0]=1;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            int siz=vec.size();
            int& cur=a[i];
            
            for(int j=0;j<siz;j++){
                dp[i&1][vec[j]]=0;
            }
            for(int j=0;j<siz;j++){
                dp[i&1][vec[j]^cur]+=dp[(i-1)&1][vec[j]];
                dp[i&1][vec[j]]+=dp[(i-1)&1][vec[j]];
                
                if(vis[vec[j]^cur]==0){
                    vis[vec[j]^cur]=1;
                    vec.push_back(vec[j]^cur);
                }
            }
        }
        ll ans=0;
        for(int i=m;i<1050010;i++){
            ans+=dp[n&1][i];
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
