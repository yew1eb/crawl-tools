#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define MAXN (3000)
int T;
int a[MAXN],n;
ll f[MAXN][MAXN];
int main() {

    int T; cin>>T;
    while(T--) {
        cin>>n;
        For(i,n-1) scanf("%d",&a[i]);
        ll ans=a[1]*n;
        Fork(i,2,n-1) a[i]-=a[1];
        For(i,n-2) a[i]=a[i+1];
        //For(i,n-2) cout<<a[i]<<endl;
        int m=n-2;

        For(i,m) {
            For(j,n-2) {
                if (j==1) 
                {
                    f[i][j]=a[1]*i;
                    continue;
                }
                if (j>1) f[i][j]=f[i][j-1];
                if (i==j) f[i][j]=max(f[i][j],(ll)a[j]);
                if (i-j>0) f[i][j]=max(f[i][j],f[i-j][j]+ a[j]);
            }
        }
        /*
        For(i,m) {
            For(j,n-2) {
                cout<<i<<':'<<j<<':'<<f[i][j]<<endl;
            }
        }*/
        cout<<ans+f[m][n-2]<<endl;
    }

    return 0;
}