ps:输入16进制的方法
#include"stdio.h"
	   int main()
   {
	   int a,b;
	   while(scanf("%x%x",&a,&b)!=EOF)
		   printf("%d\n",a+b);
	   return 0;
   }