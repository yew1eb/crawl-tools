#include<stdio.h>
#include<math.h>
__int64 euler(__int64 x)// 就是公式   
{  
    __int64 i, res=x;  
    for (i = 2; i <(__int64)sqrt(x * 1.0) + 1; i++)  
        if(x%i==0)  
        {  
            res = res /(__int64)i*(i - 1);
			
            while (x % i == 0) x /= i; // 保证i一定是素数    
        }  
        if (x > 1) res = res / (__int64)x*(x - 1);//这里小心别溢出了   
        return res;  
}  

int main()
{
	__int64 n;
    while(scanf("%I64d",&n)!=EOF)
	{
		if(!n) break;
		printf("%I64d\n",n-euler(n)-1);
	}
	 return 0;
}