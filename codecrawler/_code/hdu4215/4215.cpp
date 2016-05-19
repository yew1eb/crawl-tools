//[hdu 4215]Number Theory? 数论+打表 by ahm001

#include<cstdio>
#include<cstring>
#define N 30
using namespace std;
int i,o,p,j,k,l,n,m,t,r; 
int e[40];
int f[40];
int ans[40];

int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}

int main()
{
    memset(ans,0,sizeof(ans));
    memset(e,0,sizeof(e));
    memset(f,0,sizeof(f));
    for (i=1;i<=N;i++)
        for (j=1;j<=i;j++)
        {
             if (gcd(i,j)==1) ++e[i];
             if (gcd(i,j)==j) ++f[i];
        }
    for (i=1;i<=N;i++)
        {
             e[i]+=e[i-1];
             f[i]+=f[i-1];
        }
    for (i=1;i<=N;i++)
        for (j=i;j<=N;j++)
        if(e[j]-e[i-1]==f[j]-f[i-1])
        {
            ans[j]+=1;
        }
    for (i=1;i<=N;i++) ans[i]+=ans[i-1];
    
    
	/*打表 更改N=1000
	for (i=1;i<=N;i++)
	printf("%d ",ans[i]); 
	*/
    scanf("%d",&t);
    p=0;
    for (;t;t--)
    {
        scanf("%d",&i);
        printf("Case %d: ",++p);
        if (i<=N) printf("%d\n",ans[i]);
        else printf("%d\n",ans[N]);
    }
    return 0;
}