#include <stdio.h>
#include <string.h>
int hash[100005];
int main()
{
     int i, step, mod, seed;
     while(~scanf("%d%d",&step,&mod)) {
          memset(hash,0,sizeof(hash));
          seed = 0;
          hash[0] = 1;
          while(1) {
               seed = (seed+step) % mod;
               if(hash[seed]) break;
               hash[seed] = 1;
          }
          for(i=0; i<mod; i++)
               if(!hash[i]) break;
          printf("%10d%10d    ",step,mod);
          printf(i==mod?"Good Choice":"Bad Choice");
          printf("\n\n");
     }
     return 0;
}
