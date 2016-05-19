#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,m;
int a[30][30];

int Count(int i,int j)
{
	int sum = 0;
	//上
	if(i>0)
	{
		if(a[i][j]*a[i-1][j]<0)
			sum+=abs(a[i-1][j]);
		else
			sum-=abs(a[i-1][j]);
	}
    //左
	if(j>0)
	{
		if(a[i][j]*a[i][j-1]<0)
			sum+=abs(a[i][j-1]);
		else
			sum-=abs(a[i][j-1]);
	}
    //右
	if(i<n-1)
	{
		if(a[i][j]*a[i+1][j]<0)
			sum+=abs(a[i+1][j]);
		else
			sum-=abs(a[i+1][j]);
	}
    //下
	if(j<m-1)
	{
		if(a[i][j]*a[i][j+1]<0)
			sum+=abs(a[i][j+1]);
        else
            sum-=abs(a[i][j+1]);
	}
	return sum;
}

void run()
{
	int i,j,r,c;
	int Max, tmp;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	Max = -99999;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{

			tmp = Count(i,j);
			if(tmp > Max)
			{
				Max = tmp;
				r = i+1;
				c = j+1;
			}
		}
	}
	printf("%d %d %d\n", r, c, Max);
}
int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		if(n==0 && m==0) break;
		run();
	}
	return 0;
}
