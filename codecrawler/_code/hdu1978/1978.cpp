#include"stdio.h"
#include"string.h"
int main()
{
	int flag[111][111];    //方法数。
	int num[111][111];
	int T;
	int n,m;
	int i,l;
	int x,y;


	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(l=0;l<m;l++)
				scanf("%d",&num[i][l]);


		memset(flag,0,sizeof(flag));
		flag[0][0]=1;


		for(i=0;i<n;i++)
		{
			for(l=0;l<m;l++)
			{
				if(i==n-1&&l==m-1)	continue;
				flag[i][l]%=10000;
				for(x=i;x<=num[i][l]+i&&x<n;x++)
				{
					for(y=l;y<=num[i][l]+l&&y<m;y++)
					{
						if(x==i&&y==l)	continue;
						if(num[i][l]>=x-i+y-l)
						{
							flag[x][y]+=flag[i][l];
//优化，把这行换个地儿。	flag[x][y]%=10000;    优化前203MS，优化后187MS。
						}
					}
				}
			}
		}
		flag[n-1][m-1]%=10000;


		printf("%d\n",flag[n-1][m-1]);
	}
	return 0;
}