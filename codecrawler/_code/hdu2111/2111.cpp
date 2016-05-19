ps:动态规划 -装箱
#include<stdio.h>
#include<stdlib.h>
	   struct fun
   {
	   int p,m;
   }a[105];
   int cmp(const void*a,const void *b)
   {
	   struct fun *c=(struct fun*)a,*d=(struct fun*)b;
	   return d->p-c->p;
   }
   int main()
   {
	   int v,n,i,tol;
	   while(scanf("%d%d",&v,&n)!=EOF&&v!=0)
	   {
		   tol=0;
		   for(i=0;i<n;i++)
			   scanf("%d%d",&a[i].p,&a[i].m);
		   qsort(a,n,sizeof(a[0]),cmp);
		   for(i=0;i<n;i++)
		   {
			   if(a[i].m<=v)
			   {
				   tol+=a[i].p*a[i].m;
				   v-=a[i].m;
			   }
			   else
			   {
				   tol+=a[i].p*v;
				   v=0;
			   }
		   }
		   printf("%d\n",tol);
	   }
	   return 0;
   }