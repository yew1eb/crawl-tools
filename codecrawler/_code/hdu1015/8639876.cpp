#include <cstdio>
#include <cstring>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
int a[15];
int sum, n;

void solve() {
    int v, w, x, y, z;
    for(v=0; v<n; v++)
        for(w=0; w<n; w++)
            if(w!=v)
                for(x=0; x<n; x++)
                    if(x!=v&&x!=w)
                        for(y=0; y<n; y++)
                            if(y!=v&&y!=w&&y!=x)
                                for(z=0; z<n; z++)
                                    if(z!=v&&z!=w&&z!=x&&z!=y) {
if(sum == a[v]  -  a[w]*a[w]  +   a[x]*a[x]*a[x]   -   a[y]*a[y]*a[y]*a[y]  + a[z]*a[z]*a[z]*a[z]*a[z]) {
  printf("%c%c%c%c%c\n",a[v]+'A'-1,a[w]+'A'-1,a[x]+'A'-1,a[y]+'A'-1,a[z]+'A'-1);
                        return ;
                                        }
                                    }
     printf("no solution\n");
}
int main() {
    int i;
    char str[15];
    while(scanf("%d%s",&sum,str),sum) {
        n =strlen(str);
        for(i=0; i<n; i++)
            a[i] = str[i]-'A'+1;
        sort(a,a+n,greater<int>());
        solve();
    }
    return 0;
}
