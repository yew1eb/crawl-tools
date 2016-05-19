# include <stdio.h>
  unsigned long long Gcd(unsigned long long a,unsigned long long b)
  {
      return b?Gcd(b,a%b):a;
  }
  int main()
  {
      int t,ans;
      unsigned long long n,m,d;
      scanf("%d",&t);
      while(t--)
      {
          scanf("%I64u%I64u",&n,&m);
          if(n==m)
          {
              printf("0\n");
              continue;
          }
          if(m%n!=0)
          {
              printf("-1\n");
              continue;
          }
          m=m/n; ans=0;
          while(m!=1)
          {
              d=Gcd(n,m);
              n=n*d;
              m=m/d;
              ans++;
              if(d==1)
                break;
          }
          if(m!=1)
            printf("-1\n");
          else
            printf("%d\n",ans);
      }
      return 0;
  }
