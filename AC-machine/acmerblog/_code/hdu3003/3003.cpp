#include "stdio.h"
 #include "string.h"
 #include "stdlib.h"
 
 typedef struct _Node{
 	int price, value;
 	struct _Node *next;
 }Node, *pNode;
 
 pNode brand[11];
 int dp[11][10001];
 
 int n, m, k;
 
 int max(int a, int b){
 	return a>b?a:b;
 }
 
 int main(){
 	int i, j, b, p, v;
 	pNode t;
 	freopen("in.txt", "r", stdin);
 	while(scanf("%d %d %d", &n, &m, &k)!=EOF){
 		memset(brand, 0, sizeof(brand));
 		for(i=0; i<n; i++){
 			scanf("%d %d %d", &b, &p, &v);
 			t = (pNode)malloc(sizeof(Node));
 			t->price = p;
 			t->value = v;
 			t->next = brand[b];
 			brand[b] = t;
 		}
 		memset(dp, 0, sizeof(dp));
 		for(i=1; i<=k; i++){
 			t = brand[i];
 			while(t){
 				for(j=10000; j>=0; j--){  //注意这里，j是从大往小走，是为了避免同一商品多次放入
 					if(j>=t->price)
 						dp[i][j] = max(dp[i][j], max(dp[i-1][j-t->price], dp[i][j-t->price]) +t->value);
 					//else
 					//	dp[i][j] = max(dp[i][j], dp[i-1][j]);
 				}
 				t = t->next;
 			}
 		}
 		if(dp[k][10000])
 			printf("%d\n", dp[k][10000]);
 		else
 			printf("Impossible\n");
 	}
 	return 0;
 }