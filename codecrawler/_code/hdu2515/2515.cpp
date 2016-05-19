#include <iostream>
#include <algorithm>
using namespace std;

int Arr[100];						//Arr means the array
int Sum[2500];						//Sum means the Sum array
int sNum;							//Sum number
int aNum;							//Arr number
bool visited[2500];					//visited[i] means Sum[i] is visited

//to calc a1,a2,a3,before,of course sum1,sum2,sumk is certain,
//visited[1],visited[2],visited[k] is true(be visited)
//memset visited is false

bool isRebuild()
{
	int i, j = 3, v, p;
	for ( i = 4; i <= aNum; ++i )
	{
		while ( j <= sNum && visited[j] )
			++j;
		if( j > sNum )						//all visited
			return true;

		visited[j] = true;
		Arr[i] = Sum[j] - Arr[1];

		for( v = 2; v < i; ++v )
		{
			for ( p = j+1; p <= sNum; ++p )
			{
				if( !visited[p] && Arr[v] + Arr[i] == Sum[p] )
				{
					visited[p] = true;
					break;
				}
			}
			if( p > sNum )
				return false;
		}
	}
	return true;
}
int main()
{
	int i,j;
	while( cin >> aNum )
	{
		sNum = aNum * ( aNum - 1 ) >> 1;
		for( i = 1; i <= sNum; ++i )
			cin >> Sum[i];

		sort( Sum, Sum + sNum );

		for( i = 3; i <= sNum; ++i )
		{
			Arr[1] = ( Sum[1] + Sum[2] - Sum[i] ) >> 1;
			Arr[2] = Sum[1] - Arr[1];
			Arr[3] = Sum[2] - Arr[1];
			if( Arr[2] + Arr[3] != Sum[i] )
				continue;

			memset( visited, false,sizeof(visited) );
			visited[i] = true;

			if( isRebuild() )
			{
				for( j = 1; j <= aNum; ++j )
					cout << Arr[j] << endl;
				break;
			}
		}
	}
}