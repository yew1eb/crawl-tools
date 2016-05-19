/*
 * 1076_1.cpp
 *
 *  Created on: 2013年8月10日
 *      Author: Administrator
 */

#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int year,num;
		scanf("%d%d",&year,&num);
		while(num){
			if((year%4 == 0 && year%100 !=0)||(year%400==0)){
				num--;
			}
			year++;
		}

		printf("%d\n",year-1);
	}
}