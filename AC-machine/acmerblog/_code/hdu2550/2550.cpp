#include<iostream>
#include<algorithm>
using namespace std;
struct init
{
	int len,num;
}d[100];
int cmp(init a,init b)
{return (a.len==b.len? a.num<b.num:a.len<b.len);}
int main()
{
	int t,n,i,j,k;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--&&scanf("%d",&n))
		{
			for(i=0;i<n;i++)
			{scanf("%d%d",&d[i].len,&d[i].num);}
			sort(d,d+n,cmp);
			for(i=0;i<n;i++)
			{
               for(j=1;j<=d[i].num;j++)
			   {
				   printf(">+");
				   for(k=1;k<=d[i].len-2;k++)
					   printf("-");
				   printf("+>\n");
			   }
			   printf("\n");
			}

		}
	}
	return 0;
}