#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxx = 102;

char str[maxx];
int zn,on,jn;

int main(){ 
	int len,i;

	while(scanf("%s",str) && strcmp(str,"E")){
		zn = on = jn = 0;
		len = strlen(str);
		for(i=0;i<len;++i){
			if(str[i]=='Z'){
				++zn;
			}else if(str[i]=='O'){
				++on;
			}else{
				++jn;
			}
		}
		while(zn>0 || on>0 || jn>0){
			if(zn>0){
				printf("Z");
				--zn;
			}
			if(on>0){
				printf("O");
				--on;
			}
			if(jn>0){
				printf("J");
				--jn;
			}
		}
		printf("\n");
	}
	return 0;
}