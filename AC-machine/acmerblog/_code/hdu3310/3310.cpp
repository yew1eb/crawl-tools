#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int N = 1000000;

double smallArea( double r1, double r2, double	x){
	return (sqrt(r1*r1 - x*x)*sqrt(r2*r2 - x*x));
}

double getArea( double r1, double r2){
	double area = 0;
	double dx = r1/(N*1.0);
	double x;
	for(int i=0; i<N; i++){
		x = i*dx*1.0+0.5*dx;
		area += smallArea( r1, r2, x );
	}
	return area*dx*8;
}

int main(){
	int t;
	double r1, r2, tmp;
	double area;
	
	 cin >> t;
		while( t--){
			cin >> r1 >> r2;
			if( r1 > r2 ){
				tmp = r1; 
				r1 = r2;
				r2 = tmp;
			}
			area = getArea( r1, r2 );
			printf("%.2lf\n", area);
		}
	
	return 0;
}