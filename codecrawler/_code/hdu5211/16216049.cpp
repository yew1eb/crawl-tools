
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<stack>
#include<queue>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#define CLR(x) memset(x,0,sizeof(x))
#define SETMAX(x) memset(x,0x3f,sizeof(x))
#define SETNO(x) memset(x,-1,sizeof(x))
#define ll long long
#define eps 1e-6
#define pow2(x) ((x)*(x))
#define forto(i,n) for(int i=0;i<n;i++)
#define for1to(i,n) for(int i=1;i<=n;i++)
#define VI vector<int>
using namespace std;
const double PI=acos(-1.0);
#define INF 0x3f3f3f3f
#define NINF 0xbfffffff
using namespace std;

int A[11111][111];
int rem[11111];
int main()
{
    cin.sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
    #endif // ONLINE_JUDGE
    CLR(A);
    for(int i=1;i<=10000;i++)
    {
        for (int j=i;j<=10000;j+=i)
        {
            A[j][++A[j][0]]=i;
        }
    }
    int n;
    while (cin>>n)
    {
        CLR(rem);
        int result(0);
        for1to(i,n)
        {
            int tp;
            cin>>tp;
            for (int j=A[tp][0];j>0;j--)
            {
                result+=i*rem[A[tp][j]];
                rem[A[tp][j]]=0;
            }
            rem[tp]++;
        }
        cout<<result<<endl;
    }
    return 0;
}