#include<cstdio>
int x, y;
int gcd(int a,int b)
{// x,y用全局变量保存
    int t,d;
    if(b==0)
    {
        x=1;
        y=0;   
		return a;
    }
    d=gcd(b,a%b);
    t=x;
    x=y;
    y=t-(a/b)*y; 
	return d;
}


int main ()
{
	int a, b;
	while(~scanf("%d %d", &a, &b))
	{
		int d = gcd(a, b);
		if(d != 1)
		{
			printf("sorry\n");
			continue;
		}
		
		while(x <= 0)
		{
			x = x + b;
			y = y - a;
		}
		printf("%d %d\n",x, y);
	}
	return 0;
}