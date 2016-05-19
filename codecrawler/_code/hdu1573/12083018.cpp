#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int lcm(int x,int y){
    return x * y / gcd(x, y);
}

int a[11], b[11];

int main()
{
    int n, m;
    int cse;
    cin>>cse;
    while(cse--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);

        int ans = a[0];
        for(int i=1;i<m;i++) ans = lcm(ans, a[i]);
        //cout<<ans<<endl;

        int cnt = 0;
        for(int i=0;i<=n && i<=ans;i++){
            for(int j=0;j<m;j++){
                if(i % a[j] != b[j]) break;
                if(j == m-1) cnt = (n-i)/ans + 1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
