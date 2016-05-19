#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define INF 1000000000
#define maxn 100005
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define mset(x) memset(x,0,sizeof(x))
typedef __int64 ll;

int n;
int a[maxn];
bool h[maxn];
vector<int> v;

int main(){
//    freopen("a.txt","r",stdin);
//    freopen(".out","w",stdout);
    while(cin>>n){
        rep(i,1,n)
            cin>>a[i];
        mset(h);

        rep(i,1,n){
            if(h[i]) continue;
            v.clear();
            int s=i;
            while(!h[s]){
                v.push_back(s);
                h[s]=1;
                s=a[s];
            }

            printf("(%d",v[0]);
            for(int i=1; i<v.size(); i++){
                printf(" %d",v[i]);
            }
            printf(")");    
        }
        puts("");
    }
    return 0;
}

/*
DESCRIPTION:

*/