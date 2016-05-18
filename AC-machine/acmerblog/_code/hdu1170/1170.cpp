/*
 * 1170_1.cpp
 *
 *  Created on: 2013年8月10日
 *      Author: Administrator
 */


#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int a , b;
		char c;
		//在这里%c前面的空白符一定要有。他表示忽略%c前面的所有空白符
		scanf(" %c%d%d",&c,&a,&b);

		if(c == '+'){
			printf("%d\n",a+b);
		}else if( c == '-'){
			printf("%d\n",a-b);
		}else if(c == '*'){
			printf("%d\n",a*b);
		}else{
			if(a%b == 0){
				printf("%d\n",a/b);
			}else{
				//.2lf表示显示2两位小数
				printf("%.2lf\n",(float)a/b);
			}
		}
	}
}