#include <stdio.h>
#include <string.h>
#define size 202

int main()
{
	char a[size],b[size];
	int c[size];//储存结果
	int alen,blen,i,j,k,len,up;
	int status;//逆序输出时碰到第一个不为A的数就标记下，从这里开始通通都要输出
	while (scanf("%s%s",a,b)!=EOF)
	{
		alen = strlen(a);
		blen = strlen(b);
		memset(c,0,sizeof(c));
		len = 0;
		up = 0;
		k = 0;
		i = alen-1;
		j = blen-1;
		status = 0;
		len = (alen>blen?alen:blen)+1;
		/************************************************************************/
		/*                                大数相加                              */
		/************************************************************************/
		while (len--)
		{
			if (i!=-1&&j!=-1)
			{
				c[k] = a[i]-'A'+b[j]-'A'+up;
				k++;i--;j--;up = 0;
			}
			else if (i!=-1&&j==-1)
			{
				c[k] = a[i]-'A'+up;
				k++;i--;up = 0;
			}
			else if(i==-1&&j!=-1)
			{
				c[k] = b[j]-'A'+up;
				k++;j--;up = 0;
			}
			if (c[k-1]>25)
			{
				c[k-1] = c[k-1]%26;
				up = 1;
			}
			else
				up = 0;
			if (i==-1&&j==-1&&up==1)
			{
				c[k] = 1;
				up = 0;
				k++;
				break;
			}
		}
		for (i=k-1;i>=0;i--)
		{
			if (!status&&c[i]!=0)
				status = 1;
			if (status)
			{
				printf("%c",c[i]+65);
			}
			if (!status&&i==0)//如果说结果是AAAAAAAAA？这种全部都是A的情况的，就要输出？的值
			{
				printf("%c",c[0]+65);
			}
		}
		printf("/n");
	}
	return 0;
}