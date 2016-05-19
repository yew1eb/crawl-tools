#include <iostream>
#include <algorithm>
#include <string>
#define Max 1001
using namespace std;

char str[Max];
int Num[Max];

int main()
{
	int i,LenOfNum,value,len;
	while (scanf("%s",&str)!=EOF)
	{
		len = strlen(str);
		LenOfNum = 0;
		value = 0;
		for (i=0;i<len;i++)
		{
			if(str[i]=='5')
				continue;
			else
			{
				while(str[i]!='5')
				{
					if(i==len)
						break;
				    value=value*10+(str[i]-'0');
					i++;
				}
				Num[LenOfNum] = value;
				value=0;
				LenOfNum++;
			}	
		}
		sort(Num,Num+LenOfNum);
		for(i=0;i<LenOfNum-1;i++)
			printf("%d ",Num[i]);
		printf("%d/n",Num[LenOfNum-1]);
	}
	return 0;
}