#include<stdio.h>

int getN(int n)
{
	int f=1;
	for(int i=1;i<=n;i++)
       f*=i;
	return f;
}

int get(int m)//返回值的阶乘为小于m的最大值
{
	int i,f;
	for(i=1;i<=m;i++)
	{
       f=getN(i);
	   if(f==m)
		   return i;
	   if(f>m)
		   	break;
	}
	return i-1;
}

int main()
{
	int n,m,i,j,min,t,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		min=0;
        scanf("%d",&m);
		while(m>0)
		{
		   k=get(m);
           for(j=k;j>=0;j--)
		   {
			   t=j*getN(k);
               if(t<=m)
			   {
				   min+=j;
				   m-=t;
				   break;
			   }
		   }
		}
		printf("%d/n",min);
	}
	return 0;
}