#include<stdio.h>
#include<string.h>
int n,mark[150];
char str[10000010];
int main()
{
	int i,x,len,ss,llen;
	while(scanf("%d",&n)!=-1)
	{
		memset(mark,-1,sizeof(mark));//记录字符出现的位置
		scanf("%s",str);
		len=llen=0;x=ss=0;
		for(i=0;i<n;i++)
		{
			if(mark[str[i]]<ss)//如果字符上次出现的位置在区间外，区间+1
				llen++;
			else
			{				
				if(llen>len)//更新最大区间
				{	
					len=llen;
					x=ss;
				}
				ss=mark[str[i]]+1;//新起点
				llen=i-ss+1;//新区间长度
				
			}
			mark[str[i]]=i;
		}
		if(llen>len)
		{	
			len=llen;
			x=ss;
		}
		printf("%d %d %d\n",len,x,x+len-1);
	}
}