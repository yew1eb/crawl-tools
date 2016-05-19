#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[505],b[505];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        for(int i = 0; i < n; i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int ans1 = 0,ans2 =  0;
        for(int i = 0; i < m; i++)
            ans1 += a[i];
        for(int i = n-1; i >= n-m; i--)
           ans2 += b[i];
        //cout<<ans2<<endl;
        if(ans1 > ans2)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}