PS:题目很简单，找到规律然后用数组储存，本体笔下误错了一次！
#include<stdio.h>
#include<string.h>
	   int main()
   {
	   int t,n,a[10]={0,1,2,2,4,4,6,6,10,10};
	   scanf("%d",&t);
	   while(t--)
	   {
		   scanf("%d",&n);
		   while(n>9)n/=10;
		   printf("%d\n",a[n]);
	   }
	   return 0;
   }