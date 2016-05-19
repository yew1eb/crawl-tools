#include<iostream>
using namespace std;

const int N=35;
int n, cn;
int a[N][N], b[N], c[N];

void cal(int k)
{
	
	int i, j;
	for(i=0, cn=0; k>0; i++, k/=2)
	{
		if(k%2==1)
		{
			b[i]++;
			c[cn++] = i;
		}
	}
	for(i=0; i<cn; i++)
		for(j=i+1; j<cn; j++)
		{
			a[c[i]][c[j]]++;
			a[c[j]][c[i]]++;
		}
}

int main()
{
	int i, j, k, cas, x, y, flag;
	scanf("%d", &cas);
	while(cas--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &k);
			cal(k);
		}
		for(i=0; i<32; i++)
			b[i] %= 3;
		for(i=0; i<32; i++)
			for(j=0; j<32; j++)
				a[i][j] %= 3;
		x = 0;
		flag = -1;
		for(i=32; i>=0; i--)
		{
			x *= 2;
			if(b[i]==2)
			{
				x += 1;
				b[i]--;
			}
			else if(b[i]==1)
			{
				if(flag==-1)
				{
					x += 1;
					b[i]--;
					flag = i;
				}
				else if(a[flag][i]==1)
				{
					x += 1;
					b[i]--;
				}
			}
		}
		y = 0;
		for(i=32; i>=0; i--)
		{
			y *= 2;
			y += b[i];
		}
		if(x>y)
			swap(x, y);
		printf("%d %d\n", x, y);
	}
	
	return 0;
}