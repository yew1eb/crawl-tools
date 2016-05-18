#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 500001
__int64 p[5000];
int hash[N];
bool visited[N];

void GetPrime(int Max)
{
	int i,sqr,j,len = 0;
	memset(visited,0,sizeof(visited));
	sqr = (int)sqrt(N*1.0);
	for (i=2;i<=sqr;i++)
	{
		if(visited[i])
			continue;
		for (j=i*i;j<N;j+=i)
			if(!visited[j])
				visited[j] = 1;
	}
}

int main()
{
    __int64 i, ans, n, m, temp,k,len = 0;
	int test;
/*
	freopen("d://2.txt","r",stdin);
*/
	GetPrime(N);
	for(i=2;i<N;i++)
		if(!visited[i])
			hash[len++] = i;

	scanf("%d",&test);
   
    while (test--)
    {       
		scanf("%I64d", &n);
        m = n; 
		ans = 1;
        for (i=0;hash[i]<=m&&i<len;i++)
        {
			if(m==1)
				break;
			if(m%hash[i]==0)
			{
				temp = 1;
				k = 1;
				while (m%hash[i]==0)
				{
					m/=hash[i];
					temp = temp+k*hash[i];
					k = k*hash[i];
				}
				ans*=temp;
			}
        }
		printf("%I64d/n",ans-n);
    }
	return 0;
}