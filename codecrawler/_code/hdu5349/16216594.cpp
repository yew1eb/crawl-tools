# include <stdio.h>
  int main()
  {
      int i,n,num,t,x,max;
      while(scanf("%d",&n)!=EOF)
      {
          max=-1000000000;
          num=0;
          while(n--)
          {
              scanf("%d",&t);
              if(t==1)
              {
                  scanf("%d",&x);
                  num++;
                  max=x>max?x:max;
              }
              else if(t==2&&num>0)
              {
                  num--;
                  if(num==0)
                    max=-1000000000;
              }
              else if(t==3)
              {
                  if(num==0)
                    printf("0\n");
                  else
                    printf("%d\n",max);
              }
          }
      }
      return 0;
  }
