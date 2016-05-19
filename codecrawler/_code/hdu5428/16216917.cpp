#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100002];
const int inf=2e9;

int main(){
    memset(a,1,sizeof(a));
    int i=2;
    vector<int> su;
    int limit=sqrt(inf)+1;
    while(i<limit){
        if(a[i]){
            for(int j=2;j*i<limit;++j){
                a[i*j]=0;
            }
        }    
        ++i;
    }
    for(int i=2;i<limit;++i){
        if(a[i])
            su.push_back(i);
    }

    int t;
    cin>>t;
    
    // for(auto x:su) cout<<x<<"\t";
    while(t--){
        int n;
        cin>>n;
        priority_queue<int> q;
        q.push(inf);
        q.push(inf);
        for(int i=0;i<n;++i){
            int tem;
            cin>>tem;
            if(tem>1){
                // q.push(tem);
                // q.pop();
                int cnt=0,j=0;
                while(j<su.size() && su[j]<=tem){
                    if(tem%su[j]==0){
                        q.push(su[j]);
                        q.pop();
                        ++cnt;
                        if(cnt==2) break;
                        tem/=su[j];
                    }
                    else ++j;
                }
                if(cnt<2 && tem>1){
                    q.push(tem);
                    q.pop();
                }
            }
        }
        long long x=q.top();
        q.pop();
        long long y=q.top();
        q.pop();
        if(x==inf)
            puts("-1");
        else
            cout<<x*y<<endl;
    }    
    return 0;
}
