#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T,r;
	cin>>T;
	for(int t=1;t<=T;t++) 
	{ 
		cin>>r; 
		cout<<"Case "<<t<<":"<<endl; 
		for(int i=0;i<2*r+1;i++)
		{
			for(int j=0;j<2*r+1;j++)
			{
				if(abs(r*r-((i-r)*(i-r)+(j-r)*(j-r)))<=3)
				cout<<"*";
				else cout<<" "; 
			} 
			cout<<endl; 
		} 
	} 
	return 0; 
}