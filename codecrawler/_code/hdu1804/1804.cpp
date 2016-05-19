#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
bool fuyin(char c)
{
	return c-'a' && c-'e' && c-'i' && c-'o' && c-'u';
}
bool ES(char d,char c)
{
	return c=='o' || c=='s' || c=='x' || (c=='h'&&(d=='c'||d=='s'));
}
int main()
{
	int n,m,l;
	char a[25],b[25];
	string A,B;
	map<string,string> M;
	map<string,string>::iterator it;
	while(~scanf("%d%d",&m,&n))
	{
		while(m--)
		{
			scanf("%s%s",a,b);
			M[a] = b;
		}
		while(n--)
		{
			scanf("%s",a);
			it = M.find(a);
			if(it != M.end())
				cout<< (*it).second <<endl;
			else
			{
				l = strlen(a);
				if(fuyin(a[l-2]) && a[l-1]=='y')
				{
					a[l-1]='i';
					strcat(a,"es");
				}
				else if(ES(a[l-2],a[l-1]))
					strcat(a,"es");
				else
					strcat(a,"s");
				puts(a);
			}
		}
		M.clear();
	}
	return 0;
}