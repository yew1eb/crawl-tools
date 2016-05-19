﻿#include<iostream>
using namespace std;

int main()
{
	int n,a,b;

	while(cin>>n)
	{
		a=n/2;
		b=n-a;

		cout<<a*(a-1)/2+b*(b-1)/2<<endl;
	}

	return 0;
}