#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	char a[250],num[10];
	int i,j,len,k,temp,t=0;
	double x,y,dis;
	while(cin>>a)
	{
		t++;
		len=strlen(a);
		if(a[0]=='E'&&a[1]=='N'&&a[2]=='D')//输入END结束。
			break;
		k=0;
		x=y=0;
		for(i=0;i<len;i++)
		{
			if(a[i]>='0'&&a[i]<='9')//处理方向前的数字，先存入一个数组中。
			{
				num[k++]=a[i];
			}
			else if(a[i]==','||a[i]=='.')//若遇到分隔符，代表一个方向结束，此时开始计算这一步走了多远，并记录坐标。
			{
				temp=num[0]-48;
				for(j=1;j<k;j++)//将字符串形式的数字改变为整型。
				{
					temp=temp*10+num[j]-48;
				}
				double s=temp*sqrt(2.0)/2.0;//斜着移动时x,y增加的距离为长度乘以cos45.
				if(a[i-1]=='N'&&( a[i-2]<='9'&&a[i-2]>='0') )//对应各自方向进行计算移动后坐标。
					y+=temp;
				else if(a[i-1]=='E'&&( a[i-2]<='9'&&a[i-2]>='0') )
					x+=temp;
				else if(a[i-1]=='W'&&( a[i-2]<='9'&&a[i-2]>='0') )
					x-=temp;
				else if(a[i-1]=='S'&&( a[i-2]<='9'&&a[i-2]>='0') )
					y-=temp;
				else if(a[i-1]=='E'&&a[i-2]=='N' )
				{
					x+=s;
					y+=s;
				}
				else if(a[i-1]=='E'&&a[i-2]=='S' )
				{
					x+=s;
					y-=s;
				}
				else if(a[i-1]=='W'&&a[i-2]=='S' )
				{
					x-=s;
					y-=s;
				}
				else if(a[i-1]=='W'&&a[i-2]=='N' )
				{
					x-=s;
					y+=s;
				}
				k=0;
			}
		}
		dis=sqrt(x*x+y*y);//计算距离。
		printf("Map #%d\n",t);
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
		printf("The distance to the treasure is %.3lf.\n\n",dis);

	}
	return 0;
}