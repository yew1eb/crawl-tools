#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50000+10;
struct node
{
    int a,b;
}f[maxn];
int main()
{
    int _,vis[maxn],n,m,c;
    scanf("%d",&_);
    while(_--) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) {
            scanf("%d%d",&f[i].a,&f[i].b);
        }
        int MAX[maxn][3];
        memset(MAX,0,sizeof(MAX));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++) {
            scanf("%d",&c);
            vis[c-1]++;
        }
        int sum=0;
        for(int i=n-1;i>=0;i--) {
            sum+=vis[i];
            f[i].b+=sum;
        }
        int MAX0=-1,MAX1=-1;
        for(int i=n-1;i>=0;i--) {
            if(f[i].a) {
                MAX1=max(MAX1,f[i].b);
                MAX[i][1]=MAX1;
                MAX[i][0]=MAX0;
            }
            else {
                MAX0=max(MAX0,f[i].b);
                MAX[i][1]=MAX1;
                MAX[i][0]=MAX0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(f[i].a) {
                ans+=f[i].b<MAX[i+1][0];
            }
            else {
                ans+=f[i].b<MAX[i+1][1];
            }
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
