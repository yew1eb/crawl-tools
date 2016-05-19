/*
 * 1848_1.cpp
 *
 *  Created on: 2013年9月1日
 *      Author: Administrator
 */

#include <iostream>


using namespace std;

const int maxn = 1001;
int sg[maxn];
int f[maxn];
int hash[maxn];

void getSG(int n){

	int i,j;
	memset(sg,0,sizeof(sg));
	for(i = 1 ; i<= n ; ++i){
		memset(hash,0,sizeof(hash));
		for(j = 1 ; f[j] <= i ; ++j ){
			hash[sg[i-f[j]]] = 1;
		}

		for(j = 0 ; j <= n ; ++j){
			if(hash[j] == 0){
				sg[i] = j;
				break;
			}
		}
	}
}

int main(){
	int m,n,p;

	f[0] = 1;
	f[1] = 1;
	int i ;
	for(i = 2 ; i <= 16 ; ++i){//这里之所以取16是因为fib[16] 已经是 1597,已经大于n的最大值
		f[i] = f[i - 1] + f[i - 2];
	}
	getSG(1000);
	while(scanf("%d%d%d",&m,&n,&p)!=EOF,m||n||p){
		if((sg[m]^sg[n]^sg[p]) == 0){//sg[m]^sg[n]^sg[p]外面别忘了加括号(),否则会WA
			printf("Nacci\n");
		}else{
			printf("Fibo\n");
		}
	}
}