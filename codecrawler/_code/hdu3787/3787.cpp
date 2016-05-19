#include<iostream>
#include<string>
using namespace std;
char a[20], b[20];

int main()
{
	while(cin >> a >> b)
	{
		int i, j, l;
		l = strlen(a);
		for( i=0; i < l; i++ )
		{
			if(a[i] == ',')
			{
				for( j=i; j < l; j++ )
					a[j] = a[j+1];
				l--;
				i--;
			}
		}
		l = strlen(b);
		for( i=0; i < l; i++ )
		{
			if(b[i] == ',')
			{
				for( j=i; j < l; j++ )
					b[j] = b[j+1];
				l--;
				i--;
			}
		}
		int aa, bb;
		aa = atoi(a); //将字符串转换成整形；
		bb = atoi(b);
		cout << aa+bb << endl;
	}
	return 0;
}