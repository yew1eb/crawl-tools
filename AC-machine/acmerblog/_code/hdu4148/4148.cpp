#include"stdio.h"
#include"string.h"
int main()
{
	char str[31][5000];
	int len[31];
	int num[30],k_temp;
	int i,l;
	int count,k;
	int n;


	memset(str,0,sizeof(str));
	str[1][0]=1;
	len[1]=1;
	for(i=2;i<=30;i++)
	{
		count=1;
		k=0;
		for(l=1;str[i-1][l-1];l++)
		{
			if(str[i-1][l]!=str[i-1][l-1])
			{
				k_temp=0;
				while(count)
				{
					num[k_temp]=count%10;
					count/=10;
					k_temp++;
				}


				k_temp--;
				while(k_temp>=0)
				{
					str[i][k]=num[k_temp];
					k++;
					k_temp--;
				}
				str[i][k]=str[i-1][l-1];
				k++;


				count=1;
				continue;
			}
			count++;
		}
		len[i]=k;
	}


	while(scanf("%d",&n),n)
	{
		printf("%d\n",len[n]);
	}
	return 0;
}