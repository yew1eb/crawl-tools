/*
 * 1551_1.cpp
 *
 *  Created on: 2013年8月14日
 *      Author: Administrator
 */


#include <stdio.h>

int N,F;
double V[10001];
bool test(double x){
	int num = 0;
	int i = 0;
	for(i = 1 ; i <= N ;++i){
		num += int(V[i]/x);
	}

	if(num>=F){
		return true;
	}else{
		return false;
	}
}

int main(){

	while(scanf("%d%d",&N,&F),N||F){
		int i ;
		double sum = 0;
		for( i = 1 ; i <= N ; ++i){
			scanf("%lf",&V[i]);
			sum += V[i];
		}

		double max = sum/F;

		double l = 0;
		double r = max;
		while( r - l > 1e-10){
			double mid = (l+r)/2;
			if(test(mid)){
				l = mid + 1e-11;
			}else{
				r = mid - 1e-11;
			}
		}

		printf("%.2lf\n",(l+r)/2);


	}

}