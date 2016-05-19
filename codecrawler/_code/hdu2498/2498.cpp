#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include <stdint.h>

using namespace std;

int main()
{
    FILE *f;
    char line[1000002];
    char *m;
    int n,n1=1,count=2,n2,v;
    while ((m = fgets(line, 1000002, stdin))!=NULL)
    {
		count=2;
		n2=0;
        n = strlen(m);
        //cout << "Input: " << line;
		if(m[0] != 'E')
  		{
			if( n==2 && m[0] == '1')
			{
				cout<<1<<"\n";
				continue;
			}
			if(n==2)
			{
				cout<<2<<"\n";
				continue;
   			}

			n=n-1;
            while(1)
			{
				n1=0;
            	while(n!=0)
				{
					n = n/10;
					n1 = n1 + 1;
				}
				if(n2==n1)
					break;
				else
				    n2=n1;
				n=n1;
				count++;
			}
			cout<<count<<"\n";
		}
		else
   			break;
    }
    
	return 0;
}