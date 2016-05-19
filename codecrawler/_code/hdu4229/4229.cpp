/**
 * ID: ping128
 * LANG: C++
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>PII;
typedef pair<PII,int>PII2;

LL absL(LL x)
{
	if(x < 0) return -x;
	return x;
}

int main(){
	
	LL in[4];
	LL a[4];
	while(1)
	{
		cin >> in[0] >> in[1] >> in[2] >> in[3];
		if(!in[0] && !in[1] && !in[2] && !in[3]) break;
		int num = 0;
		while(in[0] != in[1] || in[1] != in[2] || in[2] != in[3])
		{
			num++;
			for(int i = 0; i < 4; i++ )
			{
				a[i] = absL(in[i] - in[(i + 1)%4]);
			}
			for(int i = 0; i < 4; i++ )
				in[i] = a[i];
		}
		
		cout << num << endl;
	}	
	
return 0;
}