#include <cstdio>

int main ()
{
	int n,p;
	while (~scanf("%d%d",&n,&p))
	{
		if (n==0 || p>n)        //这个剪枝是从网上学的
		{
			printf("Where is hero from?\n");
			continue;
		}
		int cnt=0,ans=0;
		for (int m=1;m<=n/2;m++)
		{
			int temp=n-m+1;
			while (temp%p==0)
				cnt++,temp/=p;   //分子中有几个p因子
			temp=m;
			while (temp%p==0)
				cnt--,temp/=p;   //分母中有几个p因子
			if (cnt<=0)        //只有分子p因子的个数多余分母时才能整除p
				continue;
			if (2*m == n)    //m为n(n为偶数)的一半
				ans++;
			else
				ans+=2;     //m和n-m的组合数一样
		}
		if (ans)
			printf("%d\n",ans);
		else
			printf("Where is hero from?\n");
	}
	return 0;
}