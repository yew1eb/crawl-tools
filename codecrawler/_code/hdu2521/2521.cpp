#include<cstdio>
 int judge1(int k) {
     int tot = 0;
     for(int i = 1;i<=k;++i)
     if(!(k%i))
     tot++;
     return tot;
 }
 int main( ) {
     int n,a,b;
     scanf("%d",&n);
     while(n--) {
         scanf("%d%d",&a,&b);
         int MIN = a;
         for(int i = a;i<=b;++i)
         if(judge1(i)>judge1(MIN))
         MIN = i;
         printf("%d\n",MIN);
     }
     return 0;
 }