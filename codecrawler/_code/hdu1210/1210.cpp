#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int flat=1;int k=1;int s=0;   //flat为标记第一张牌的位置，flat=1表示在第一部分，flat=0表示在第二部分。s表示洗牌次数
		while(1)
		{
			s++;
			if(flat)               //第一张牌在第一部分
			{
				k=2*k;
				if(k>n)
				{
					k-=n;flat=0;
					if(k==1)break;   //处在第二部分，且k==1，则下次洗牌一定能达到初始状态
				}
			}
			else                      //第一张牌在第二部分
			{
				k=2*(k-1)+1;
				if(k<=n){flat=1;}
				else
				{
					 k-=n;if(k==1)break;   //处在第二部分，且k==1，则下次洗牌一定能达到初始状态
				}
			}
		}
		cout<<s+1<<endl;
	}

}