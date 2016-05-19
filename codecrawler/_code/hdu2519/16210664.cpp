#include <iostream>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("2519in.txt","r",stdin);
#endif
    int i,n,m,t,r;
    scanf("%d",&t);
    while (t--){
        r=1;
        scanf("%d%d",&n,&m);
        if (n<m)
            r=0;
        else if (n==m||m==0)
            r=1;
        else {
            for (i=0;i<m;i++){
                r=r*(n-i);
                r=r/(i+1);
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
