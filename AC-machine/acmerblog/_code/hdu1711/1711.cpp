/*
 * 1711_2.cpp
 *
 *  Created on: 2013年7月30日
 *      Author: Administrator
 */

#include <stdio.h>
#include <string.h>
#define N 50
//int max(int a , int b){
//	return (a>b)?a:b;
//}
//
//int min(int a ,int b){
//	return (a>b)?b:a;
//}
int max(int a ,int b){
	return (a > b)?a:b;
}

int min(int a ,int b){
	return (a > b)?b:a;
}

int f[N*N*N + 5],c[N+5],amount[N+5],V ;

void ZeroOnePack(int cost,int weight)
{
	int j;
	for(j=V;j>=cost;j--){
		f[j]=max(f[j],f[j-cost]+weight);
	}
}


void CompletePack(int cost , int weight){
	int v;
	for( v = cost ; v <=V  ; v++){//不要写成v--，否则会造成程序异常终止。而且很难调
		f[v] = max(f[v],f[v-cost] + weight);
	}

}
void MultiplePack(int cost ,int weight , int amount){
	if(cost*amount >= V){
		CompletePack(cost,weight);
		return ;
	}
	int k = 1;
	while( k < amount){
		ZeroOnePack(k*cost,k*weight);
		amount -= k;
		k=k*2;
	}
	ZeroOnePack(amount*cost,amount*weight);
}



int main(){

	int i,n,sum ;

	while(scanf("%d",&n),n >= 0){

		 sum = 0;
		for( i = 0 ; i < n ; ++i){
			scanf("%d%d",&c[i],&amount[i]);

			sum +=  c[i]*amount[i];
		}

		V = sum/2;
		memset(f,0,sizeof(f));

		for( i = 0 ; i < n ; ++i ){
			MultiplePack(c[i],c[i],amount[i]);

		}
		printf("%d %d\n",max(f[V],sum-f[V]),min(f[V],sum - f[V]));



	}
	return 0;
}