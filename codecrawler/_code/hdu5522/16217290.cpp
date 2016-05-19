#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#define scnaf scanf
#define cahr char
#define bug puts("bugbugbug");
using namespace std;
typedef long long ll;
const int mod=1000000007;
const int maxn=1000+5;
const int inf=1e9;
const int maxe=200000;
int a[maxn],visit[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            visit[a[i]]++;
        }
        sort(a,a+n);
        int flag=0;

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
            {
                if(a[i]+a[j]==a[k]) {
                    flag=1;
                    break;

                }
            }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}