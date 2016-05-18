#include <stdio.h>
#include <string.h>

int s,t,m;
bool vi[110];
int id[110];

int main()
{
//	freopen("1.txt", "r", stdin);
	int a,b;
	int ans;
	int i,j;
	int T=0;
	while (scanf("%d %d %d",&s,&t,&m)!=EOF && (s>0 || t>0 || m>0))
	{
		T++;
		memset(vi,false,sizeof(vi));
		ans=0;
		for (i=0;i<s;i++)
		{
			scanf("%d %d %d",&id[i],&a,&b);
			ans+=a+b;
		}
		for (i=0;i<t;i++)
		{
			scanf("%d %d",&a,&b);
			if (b>=m)
			{
				for (j=0;j<s;j++)
				{
					if (id[j]==a)
					{
						if (!vi[j])
						{
							vi[j]=true;
							ans++;
						}
						break;
					}
				}
			}
		}
		printf("Case %d: %d\n",T,ans);
	}
	
	return 0;
}