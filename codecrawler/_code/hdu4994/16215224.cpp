#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1005];

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int flag=1,ss=0;
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        for(i=1;i<n;i++){
            if(a[i]==1) flag ^= 1;
            else{
                if(flag) puts("Yes");
                else puts("No");
                ss=1;
                break;
            }
        }
        if(ss) continue;
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
