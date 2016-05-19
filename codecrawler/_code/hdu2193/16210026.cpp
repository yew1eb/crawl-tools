#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
#define LL long long
#define inf 1<<30
#define s(a) scanf("%d",&a)
#define CL(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=45;
int n,a[N],b;
int main()
{
    a[0]=1;a[1]=2;
    for(int i=2;i<=44;i++) a[i]=a[i-1]+a[i-2]+1;
    while(~scanf("%d",&n)&&n){
        int i=0;
        while(a[i]<=n) i++;
        printf("%d\n",--i);
    }
    return 0;
}

