#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
    int x,y,g;
}a[10000];
bool cmp(node a,node b)
{
    return a.g>b.g;
}
int main()
{
    int t,m,n,k;
    int dp[10000];
    cin>>t;
    while(t--){        
        cin>>m>>n>>k;
        int u=0;
        for(int i=0;i<10000;i++) dp[i]=k;
        for(int i=0;i<m;i++)
           for(int j=0;j<n;j++){
              cin>>a[u].g;
              a[u].x=i,a[u++].y=j;
           }
        sort(a,a+m*n,cmp);
        if(a[0].x*2+3>k) cout<<"0"<<endl;
        else{
        dp[0]=k-a[0].x-2;
        int ans=a[0].g;
        for(int i=1;i<m*n;i++){
            int tmp=dp[i-1]-abs(a[i].x-a[i-1].x)-abs(a[i].y-a[i-1].y)-1;
            if(tmp-a[i].x<1)
            break;
            else{
              dp[i]=tmp;
              ans+=a[i].g;
            }
        }
        cout<<ans<<endl;
        }
    }
}