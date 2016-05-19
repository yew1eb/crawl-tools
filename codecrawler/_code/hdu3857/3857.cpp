#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")

using namespace std;

const int MAX = 10010;
int a[MAX];
queue<int> q;
int main()
{
	int n,a;
	
	while( cin >> n )
	{
		while( !q.empty() ) q.pop();
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&a);
			if( a == i ) q.push(a);
		}
		if( q.empty() )
		{
			printf("No Mistake\n");
			continue;
		}
		while( !q.empty() )
		{
			cout << q.front();
			q.pop();
			if( q.empty() )
				cout << endl;
			else
				cout << ' ' ;
		}
	}

return 0;
}
