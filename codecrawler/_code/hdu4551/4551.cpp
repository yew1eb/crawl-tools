#include"stdio.h"
int fun(int y,int m,int d)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	{
		if(d>=1&&d<=31)return 1;
		return 0;
	}
	else if(m==2)
	{
		if(d>=1&&d<=28)return 1;
		else if(d==29)
		{
			if(y%400==0||y%100!=0&&y%4==0)return 1;
			else return 0;
		}
		return 0;
	}
	else 
	{
		if(d>=1&&d<=30)return 1;
		return 0;
	}
}
int gcd(int x,int y)
{
	while(x>y?x%=y:y%=x);
	return x+y;
}
int main()
{
	int T,t;
	int a,b,y,m,d;
	int i,j,cnt;;
	t=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&y);
		cnt=0;
		for(i=1;i<=12;i++)
		{
			for(j=1;j<=31;j++)
			{
				if(!fun(y,i,j))continue;
				if(gcd(i,j)==a&&a*b==i*j)
				{
					if(cnt==0){m=i;d=j;}
					if(cnt>=2)break;
					cnt++;
				}
			}
			if(cnt>=2)break;
		}
		printf("Case #%d: ",t++);
		if(cnt==0)printf("-1\n");
		else if(cnt==1)printf("%d/%02d/%02d\n",y,m,d);
		else printf("1\n");
	}
	return 0;
}
