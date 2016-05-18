#include 
#include 
#include 
using namespace std;

char str[100005],temp;
__int64 top,flag,i,len,sum,s1,s2;

__int64 fun(__int64 x,__int64 y)
{
	int k;
	__int64 sum1=1;
	for(k=1;k&lt;=y;k++)
		sum1*=x;
	return sum1;
}

int main()
{
	__int64 x;
	while(scanf("%I64d%s",&amp;x,str)!=EOF)
	{
		s1=s2=0;
		len=strlen(str);
		top=-1;
		sum=0;
		temp='+';
		i=0;
		while(i&lt;=len)
		{
			if(str[i]=='+' || str[i]=='-' || str[i]=='/0')
			{
				if(temp=='+')
					sum+=s1*fun(x,s2);
				else
					sum-=s1*fun(x,s2);
				s1=s2=0;
				flag=0;
				temp=str[i];
				i++;
			}
			else if(str[i]=='X') 
			{
				if(s1==0)
					s1=1;
				i++;
				if(str[i]!='^')
					s2=1;
			}
			else if(str[i]=='^')
			{
				i++;
				while(1)
				{
					if(str[i]=='+' ||str[i]=='-' || str[i]=='/0')
						break;
					else
						s2=s2*10+str[i]-'0';
					i++;
				}
			}
			else
			{
				s1=s1*10+str[i]-'0';
				i++;
			}
		}
		printf("%I64d/n",sum);
	}
	return 0;
}