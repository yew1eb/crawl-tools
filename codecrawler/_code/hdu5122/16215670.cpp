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

int a[1000010];

int main(){
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        cas++;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int ans=0;
        for(int i=n-1;i>=1;i--){
            if(a[i]>a[i+1]){
                ans++;
                swap(a[i],a[i+1]);
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
} 