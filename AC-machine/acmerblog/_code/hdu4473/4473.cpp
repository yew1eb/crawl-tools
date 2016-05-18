#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    __int64 i,j,n,zs;
    int cas=0;
    while (scanf("%I64d",&n)!=EOF)
    {
          cas++;
          zs=0;
          for (i=1;i*i*i<=n;i++)
              for (j=i;i*j*j<=n;j++)
              {
                  __int64 k1,k2;
                  k1=j;
                  k2=n/(i*j);
                  if (i!=j)  
                  {
                             zs=zs+6*(k2-k1+1);
                             zs-=3;
                  }
                  else 
                  {
                       zs=zs+3*(k2-k1+1);
                       zs-=2;
                  }
              }
          printf("Case %d: %I64d\n",cas,zs);
    }
    return 0;
}
