#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int T,n,m,k,cas=1;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&m,&k);
        double ans=0;
        for(double i=1;i<=n;i++) {
            for(double j=1;j<=m;j++) {
                double p=0;
                p+=(i-1)*(j-1)*(m-j+1)*(n-i+1);//1
                p+=(i-1)*(n-i+1)*m;//2
                p+=(i-1)*(m-j)*(n-i+1)*j;//3
                p+=(j-1)*(m-j+1)*n;//4
                p+=n*m;//5
                p+=(m-j)*n*j;//6
                p+=(n-i)*(j-1)*i*(m-j+1);//7
                p+=(n-i)*i*m;//8
                p+=(n-i)*(m-j)*i*j;//9
                p=p/n/m/n/m;
                ans+=1-pow(1-p,k);//kæ¬¡æè²æä½è¢«æè²çæ¦ç
            }
        }
        printf("Case #%d: %d\n",cas++,int(ans+0.5));
    }
    return 0;
}
