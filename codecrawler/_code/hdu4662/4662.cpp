#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int testcase;
	cin>>testcase;
	while(testcase--)
	{
		string p="MI";
		int counti=1,countu=0,counti2=0,countu2=0,cm=0,pos=0;
		string tar;
		cin>>tar;
		for(int i=0;i<tar.length();i++)
		{
			
			if(tar[i]=='M')
			{
				cm++;
			}
				
			if(tar[i]=='I')
			{
				counti2++;
			}
				
			if(tar[i]=='U')
			{
				countu2++;
			}
				
		}
		
		if( cm==1 && tar[0]=='M'&& (((countu2*3+counti2)%2==0 && (countu2*3+counti2)%3!=0)||(countu2*3+counti2)==1))
		{
			pos=1;
		}
		else
		{
			pos=0;
		}
		
	
		if(pos==0)
		{
			cout<<"No"<<endl;
		}
		else if(pos==1)
			cout<<"Yes"<<endl;
		
		
	}
	
	return 0;
}
