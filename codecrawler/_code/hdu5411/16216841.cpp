#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=2015;
struct mat
{
    int s[55][55];
};
int n;
void operator*=( mat &a,const mat &b)
{
    static mat c;
    int i,j,k;
    memset(c.s,0,sizeof(c));
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                c.s[i][j]+=a.s[i][k]*b.s[k][j];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            a.s[i][j]=c.s[i][j]%mod;
}
void operator+=( mat &a,const mat &b)
{
    int i,j,k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            a.s[i][j]+=b.s[i][j];
            a.s[i][j]%=mod;
        }
}
mat ans,t;
mat quick(int m)
{
    mat x=t;
    memset(ans.s,0,sizeof(ans.s));
    for(int i=0;i<n;i++) ans.s[i][i]=1;

    for(int i=m;i;i>>=1,x*=x)
        if(i&1) ans*=x;
    return ans;
}
void print(mat x)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) printf("%d ",x.s[i][j]);
        puts("");
    }
}
int vis[100010];
mat solve(int m)
{
    if(m==1)
    {
        return t;
    }
    mat res,out=solve(m/2);
    if(m&1)
    {
        mat x=quick(m/2+1);
        res=x;
        res*=out;
        res+=out;
        res+=x;
    }
    else
    {
        mat x=quick(m/2);
        res=x;
        res*=out;
        res+=out;
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int w,k,x;
        scanf("%d%d",&n,&w);
        memset(t.s,0,sizeof(t.s));
        memset(ans.s,0,sizeof(ans.s));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&x);
                t.s[i][x-1]=1;
            }
        }
        int res=0;
        mat ans=solve(w-1);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                res=res+ans.s[i][j];
//        print(ans);
        if(w==1)
            printf("%d\n",n+1);
        else
            printf("%d\n",(res+1+n)%mod);
    }
    return 0;
}
/*
*/
