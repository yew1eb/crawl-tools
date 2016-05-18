#include <cstdlib> 
#include <cctype> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <fstream> 
#include <numeric> 
#include <iomanip> 
#include <bitset> 
#include <list> 
#include <stdexcept> 
#include <functional> 
#include <utility> 
#include <ctime>
using namespace std;
ifstream fin("aa.txt");
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
#define BLANK(a) for(int i = 0; i < (a); i ++) printf(" ")


int main()
{
	int ncase;
	scanf("%d",&ncase);
	int k = 1;
	while(ncase--)
	{
		int n;
		scanf("%d",&n);
		long long a,b;
		a = b = 0;
		long long x,y;
		while(n--)
		{
			cin >> x >> y;
			while(x > 1 && y > 1)
			{
				x = x >> 1;
				y = y >> 1;
			}
			if(x == 1) b += y-1;
			else a += x-1;
		}
		printf("Case %d: ",k++);
		if(a > b) printf("Alice\n");
		else printf("Bob\n");
	}

 return 0;
}