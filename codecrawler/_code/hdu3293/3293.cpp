#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct point
{
	string weapon;
	string origin;
	int harm;
};
point F[700];
bool cmp(const point& x,const point& y)
{
	if (x.origin != y.origin)
		return x.origin < y.origin;
	if (x.harm != y.harm)
		return x.harm > y.harm;
	return x.weapon < y.weapon;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("2.txt","r",stdin);
#endif
	int n,i,t=1;
	string str;
	while (cin >> n)
	{
		for (i=0; i < n; ++i)
		{
			cin >> F[i].weapon >> F[i].origin >> str;
			if (str[0]=='s')
				F[i].harm = 1;
			else if (str[0]=='g')
				F[i].harm = 2;
			else F[i].harm = 3;
		}
		sort(F,F+n,cmp);
		printf("Case %d\n",t++);
		for (i=0; i < n; )
		{
			str = F[i].origin;
			cout << str << ":" << endl;
			while (i < n && str==F[i].origin)	//debug:要加上i<n避免越界
			{
				cout << "          " << F[i].weapon << " ";
				if (F[i].harm==1)
					cout << "so-so" << endl;
				else if (F[i].harm==2)
					cout << "good" << endl;
				else
					cout << "wonderful" << endl;
				++i;
			}
		}
	}
	return 0;
}