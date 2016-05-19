#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

#define CLR(arr,val) memset(arr,val,sizeof(arr))
int num[55],num2[55];
const int N = 52;
bool isok(int dit[55],int rp){
	bool flag = true;
	for(int i = 1; i <= rp; ++i){
		if(dit[i] != num[i]){
		  flag = false;
		  break;
		}
	}
	return flag;
}
__int64 fun(int lp,int rp){
	int num3[55];
	int k = 0;
	__int64 cnt = 0;
	while(1){
		k = 1;
	  for(int i = lp; i <= rp; ++i)
		 num3[k++] = num2[i];
	  for(int i = 1;i < lp; ++i)
		  num3[k++] = num2[i];
	  cnt++;
	  if(isok(num3,rp)){
	    break;
	  }
	  for(int i = 1; i <= rp; ++i)
		  num2[i] = num3[i];
	}
	return cnt;
}
void solve(__int64 x,int lp,int rp){
	int dit[55],dit2[55];
	for(int i = 1; i <= 52; ++i)
		dit[i] = num[i];
	while(x--){
	  int k = 1;
	  for(int i = lp; i <= rp; ++i)
		  dit2[k++] = dit[i];
	  for(int i = 1; i < lp ;++i)
		  dit2[k++] = dit[i];
	  for(int i = 1; i <= rp; ++i)
		  dit[i] = dit2[i];
	}
	printf("%d",dit[1]);
	for(int i = 2; i <= rp; ++i)
		printf(" %d",dit2[i]);
	for(int i = rp+1;i <= 52; ++i)
		printf(" %d",num[i]);
	printf("\n");
}
int main(){
	//freopen("1.txt","r",stdin);
	int numcase;
	scanf("%d",&numcase);
	for(int ca = 1; ca <= numcase; ++ca){
	  CLR(num,0);
	  CLR(num2,0);
	  for(int i = 1; i <= N; ++i)
		  scanf("%d",&num[i]);
	  int lp,rp;
	  __int64 cnt;
	  scanf("%I64d%d%d",&cnt,&lp,&rp);
	  for(int i = 1; i <= rp; ++i)
		  num2[i] = num[i];
	  __int64 x = fun(lp,rp);
	 // printf("x = %d\n",x);
	  __int64 y = cnt % x;
	  printf("Case #%d: ",ca);
	  if(y == 0){
		  printf("%d",num[1]);
	    for(int i = 2; i <= N; ++i)
			printf(" %d",num[i]);
		printf("\n");
		continue;
	  }
	  solve(y,lp,rp);
	}
	return 0;
}