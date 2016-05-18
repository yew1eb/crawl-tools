#include<iostream>
using namespace std;
int main()
{
	int s,d,i,cnt,a[100];
	while(scanf("%d%d",&s,&d)!=EOF&&(s!=0||d!=0))
	{
		for(i=0;i<60;i++)a[i]=0;
		cnt=0;
		while(s!=0&&a[s]==0)
		{
			a[s]=1;
			s=(s+s*d)%60;
			cnt++;

		}
		if(s!=0)printf("Impossible\n");
		else printf("%d\n",cnt);

	}
	return 0;
}