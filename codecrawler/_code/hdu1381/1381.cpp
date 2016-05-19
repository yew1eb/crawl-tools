#include <stdio.h>
#include <string.h>
#define N 16000007
int hash[8000000],assi[27];
char str[N];
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("acm.txt","r",stdin);
#endif
	int T,n,nc,len,k;
	int i,j,sum;
	scanf("%d",&T);
	while(T--)
	{
		memset(hash,0,sizeof(hash));
		scanf("%d %d",&n,&nc);
		getchar();
		scanf("%s",str);
		len=strlen(str);
		i=0;
		k=0;
		for(i = 0; i < len; i++)
		{
			a[i] = str[i] - 'a';
		}
		i = 0;
		while(str[i]!='\0')
		{
			if(assi[a[i]]==0)
				assi[a[i]]=k++;
			if(k==nc)
				break;
			i++;
		}
		int cnt=len-n+1;
		for(i=0;i<len-n+1;i++)
		{
			sum=0;
			for(j=i;j<i+n;j++)
			{
				sum=sum*nc+assi[a[j]];
			}
			sum%=N;
			if(hash[sum]==0)
				hash[sum]=1;
			else
				cnt--;
		}
		printf("%d\n",cnt);
		if(T>0)
			printf("\n");
	}
	return 0;
}