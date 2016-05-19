#include"stdio.h"
#include"iostream"
using namespace std;
#include"algorithm"
int main()
{
    int T,a,b;
//    unsigned long long ans[10010];
//    for(int i=0;i<10001;i++)
//        ans[i]=ans[i-1]+i*i*i;
    scanf("%d",&T);
    for(int k=1;k<=T;k++)
    {
        unsigned long long ans=0;
        scanf("%d%d",&a,&b);
        for(long long j=a;j<=b;j++)
            ans+=j*j*j;
        printf("Case #%d: ",k);
        cout<<ans<<endl;
    }
    return 0;
}