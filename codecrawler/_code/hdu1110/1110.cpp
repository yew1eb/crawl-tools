#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool judge( double a, double b, double x, double y ){
	if( a > x && b > y ){
		return true;
	}
	if( a * b <= x * y ){
		return false;
	}
	if( y >= b ){
		return false;
	}

	double diagonal = sqrt( x * x + y * y );
	double angle = acos( y / diagonal ) - acos( b / diagonal );
//	double angle2 = asin( b / diagonal ) - asin( y / diagonal );
	double H = x * cos( angle ) + y * sin( angle );
	if( H > a ){
		return false;
	}else{
		return true;
	}
}

int main(){
	double a, b, x, y;
	int T;
	cin >> T;
	while( T-- ){
		cin >> a >> b >> x >> y;
		if( a < b ){
			swap( a, b );
		}
		if( x < y ){
			swap( x, y );
		}
		if( judge( a, b, x, y ) ){
			cout << "Escape is possible." << endl;
		}else{
			cout << "Box cannot be dropped." << endl;
		}
	}
	return 0;
}