#include<stdio.h>
int main()
{
	int t, a, sum, n, i;
	scanf("%d",&t);
	while(t--)
	{
   		scanf("%d",&n);
   		sum = 1 - n;//要减去n-1个被占用的插孔 
   		for(i=0; i<n; i++)
	   	{
    		scanf("%d",&a);
   			sum += a;
   		}
   		printf("%d\n",sum);
	}
}