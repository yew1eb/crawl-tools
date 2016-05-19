/*
 * 1197_1.cpp
 *
 *  Created on: 2013年8月10日
 *      Author: Administrator
 */

#include <stdio.h>


int mod(int n , int b){
	int sum = 0;
	while(n){
		sum += n%b;
		n /= b;
	}
	return sum;
}
int main(){
	int i ;
	for(i = 2992 ; i <= 9999 ; ++i){
		if(mod(i,10) == mod(i,12) &&mod(i,10) == mod(i,16)){
			printf("%d\n",i);
		}
	}
}