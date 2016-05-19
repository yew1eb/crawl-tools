#include<bits/stdc++.h>
using namespace std;
int flag=0;int main(){int t,n,kase=1;scanf("%d",&t);while(t--){flag=0;scanf("%d",&n);for(int i=0;i<n;i++){int r,e,l;scanf("%d%d%d",&r,&e,&l);if(e < r) flag=1;
}printf("Case #%d: ",kase++);if(flag) printf("NO\n"); else printf("YES\n");}return 0;}