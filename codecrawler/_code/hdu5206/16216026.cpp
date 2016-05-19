#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<cmath>

using namespace std;

int n;
long long x[4];
long long y[4];
long long z[4];
long long a[10];
int  main() {
    int t;
    cin>>t;
    int ca=1;
    while(t--) {
        for(int i=0; i<4; i++)
            scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
        int l=0;
        for(int i=0; i<4; i++) {
            for(int j=i+1; j<4; j++) {
                a[l++]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
            }
        }
        sort(a,a+l);
        if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[4]==a[5]&&(a[1]+a[2]==a[5])) {
            printf("Case #%d: Yes\n",ca++);
        } else
            printf("Case #%d: No\n",ca++);
    }
}
