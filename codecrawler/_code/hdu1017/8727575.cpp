#include <stdio.h>
#include <string.h>
int n, m;

int calc()
{
     int i, j, rec = 0;
     for(i=1; i<n; i++)
          for(j=1; j<i; j++)
               if( (i*i+j*j+m) %(i*j)==0)rec++;
     return rec;
}
int main()
{
     int T, cnt, i;
     scanf("%d",&T);
     for(i=0; i<T; i++) {
          cnt = 0;
          while(scanf("%d%d",&n,&m),n>0) {
               int rec = calc();
               printf("Case %d: %d\n",++cnt, rec);

          }
          if(i!=T-1) printf("\n");
     }
     return 0;
}
