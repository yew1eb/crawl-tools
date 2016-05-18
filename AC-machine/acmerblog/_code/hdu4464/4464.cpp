#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int main()
{
	int Case=1;
	int n;
	int i;
	char str[111];
	int ans;
	while(scanf("%d",&n)!=-1)
	{
		ans=0;
		int temp;
		while(n--)
		{
			temp=0;
			scanf("%s",str);
			for(i=0;str[i];i++)	temp+=str[i];
			if(temp>ans)	ans=temp;
		}
		printf("Case %d: %d\n",Case++,ans);
	}
	return 0;
}