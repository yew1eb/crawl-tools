//nim game
#include <stdio.h>

int main()
{
	int n, a;
	while(scanf("%d", &n)&&n){
		int res = 0;
		while(n--){
			scanf("%d", &a);
			res ^= a;
		}
		if(res == 0)printf("Grass Win!\n");
		else printf("Rabbit Win!\n");
	}
	return 0;
}