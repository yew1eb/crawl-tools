/*
 * 1203_4.cpp
 *
 *  Created on: 2013年8月13日
 *      Author: Administrator
 */


#include <iostream>

using namespace std;

double w[10005],f[10005];
int c[10005];
int n,V;

int main(){

	while(scanf("%d%d",&V,&n)!=EOF,n||V){
		int i;
		for(i = 1 ; i <= n ; ++i){
			scanf("%d%lf",&c[i],&w[i]);
		}

		memset(f,0,sizeof(f));

		int j;
		for( i = 1 ; i <= n ; ++i){
			for( j = V  ; j >= c[i] ; --j ){
				f[j] = max(f[j],1 - (1 - f[j - c[i]])* (1 - w[i]));
			}
		}

		
		printf("%.1lf%%\n",100*f[V]);
	}
}