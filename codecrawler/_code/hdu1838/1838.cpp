#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	int N;
	while(cin >> N && N!=0)
	{
		int level = floor(sqrt(double(N-1)))+1;
		int middle = (level-1)*(level-1)+level;
//		cout << "level: " << level << " middle: " << middle << endl;
		if(level%2) 
		{
			if(N<middle) cout << level << ' ' << level+N-middle << endl;
			else cout << level-N+middle << ' ' << level << endl;
		}
		else 
		{
			if(N<middle) cout << level+N-middle << ' ' << level << endl;
			else cout << level << ' ' << level-N+middle << endl;
		}
	}
	return 0;
}