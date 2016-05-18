#include"stdio.h"
#include"string.h"
#include"ctype.h"
int main()
{
	int a[1001]={0,1,1};
	char str[1011];
	int i;
	int num;

	for(i=3;i<=1000;i++)	a[i]=(a[i-1]+a[i-2])%26;

	while(gets(str))
	{
		num=0;
		for(i=0;str[i];i++)
		{
			if(isupper(str[i]))
			{
				num++;
				printf("%c",isupper(str[i]+a[num])?str[i]+a[num]:str[i]+a[num]-26);
			}
			else	printf("%c",str[i]);
		}
		printf("\n");
	}
	return 0;
}