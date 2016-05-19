#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define mset(x) memset(x, 0, sizeof(x))
#define rep(i,x,y) for(int i=x; i<=y; i++)
typedef long long ll;

int a, b, c, t;
int main(){
//    freopen("a.txt", "r", stdin);
    cin>>t;
    while(cin>>a>>b>>c){
        int x=1, ans=0;
        while(a*x+b<=c){
            if( (c-a*x)%b==0 )
                ans++;
            x++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*DESCRIPTION:

*/