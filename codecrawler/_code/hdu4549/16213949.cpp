#include<stdio.h>
#include<string.h>
#define N 2
#define mod  1000000007
struct mat
{
    __int64 mar[N][N];
};
mat a,b,c,init,temp;
mat res=///åä½ç©éµ
      {
          1,0,
          0,1
      };
mat mul(mat a1,mat b1)
{
    int i,j,l;
    mat c1;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            c1.mar[i][j]=0;
            for (l=0;l<N;l++)
            {
                c1.mar[i][j]=c1.mar[i][j]+a1.mar[i][l]*b1.mar[l][j]%(mod-1); 
                c1.mar[i][j]%=(mod-1);
            }
        }
    }
    return c1;
}
mat er_fun(mat e,int x)
{
    mat tp;
    tp=e;
    e=res;
    while(x)
    {
        if(x&1)
            e=mul(e,tp); 
        tp=mul(tp,tp);
        x>>=1;
    }
    return e;
}
__int64 quick_mod(__int64 aa,__int64 bb)
{
    __int64 ans=1;
    aa%=mod;
    while(bb)
    {
        if(bb&1)
        {
            ans=ans*aa%mod;
        }
        bb>>=1;
        aa=aa*aa%mod;
    }
    return ans;
}
int main()
{
      int n,aa,bb,cnt=0;
      __int64 anum,bnum;
      while(scanf("%d %d %d",&aa,&bb,&n)!=EOF)
      { 
            init.mar[0][0]=1;init.mar[0][1]=1;init.mar[1][0]=1;init.mar[1][1]=0;
             a=init;
             if(n==0)
             {
                 printf("%d\n",aa);
                 continue;
             }
             b=er_fun(a,n-1);
             bnum=b.mar[0][0];  anum=b.mar[1][0];
            // printf("%I64d %I64d\n",anum,bnum);
             anum=quick_mod((__int64)aa,anum);bnum=quick_mod((__int64)bb,bnum);
             //printf("%I64d %I64d\n",anum,bnum);
             printf("%I64d\n",anum*bnum%mod);
      }
      return 0;
}
