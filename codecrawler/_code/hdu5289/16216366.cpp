#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define maxn 100007
int tree1[maxn];
int tree2[maxn];
int lowbit(int i){
    return i&(-i);
}
void addmax(int p,int num){
    while(p < maxn){
        tree1[p] = max(tree1[p],num);
        p += lowbit(p);
    }
}

int querymax(int p){
    int ans = 0;
    while(p > 0){
        ans = max(ans,tree1[p]);
        p -= lowbit(p);
    }
    return ans;
}

void addmin(int p,int num){
    while(p < maxn){
        tree2[p] = min(tree2[p],num);
        p += lowbit(p);

    }
}
int querymin(int p){
    int ans = 1000000007;
    while(p > 0){
        ans = min(ans,tree2[p]);
        p -= lowbit(p);
    }
    return ans;

}

int num[maxn];
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i = 1;i <= n; i++){
            scanf("%d",&num[i]);
        }
        memset(tree1,0,sizeof(tree1));
        memset(tree2,0x3f,sizeof(tree2));
        long long ans = 0;
        for(int i = n; i > 0 ; i--){
            addmax(i,num[i]);
            addmin(i,num[i]);
            int low = i,high = n;
            while(low <= high){
                int mid = (low+high)/2;
                int ma = querymax(mid);
                int mi = querymin(mid);
                if(ma - mi >= k)
                    high = mid-1;
                else
                    low = mid+1;
            }
            ans += low-i;
            //cout<<low<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}













