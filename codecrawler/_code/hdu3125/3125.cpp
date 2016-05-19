#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main(){
	//freopen("1.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
	 char ss[60];
	 scanf("%s",ss);
	 int flag = 0;
	 if(ss[0] == '\\' || ss[0] == '/'){
	 printf("It's a path in Unix-like systems!\n");
		 for(int i = 0; i < strlen(ss); ++i){
		 if(ss[i] == '\\')
				 printf("/");
			 else
				 printf("%c",ss[i]);
		 }
		 printf("\n");
	 }
	 else{
		 flag = 0;
		 for(int i = 0; i < strlen(ss) - 1; ++i){
			 if((ss[i] == '\\' || ss[i] == '/') && (ss[i+1] == '\\' || ss[i + 1] == '/')){
				 // printf("i = %d\n",i);
			 flag = 1;
				 break;
			 }
		 }
		 if(flag == 1){
		 printf("It's a URL!\n");
			 for(int i = 0; i < strlen(ss); ++i){
			 if(ss[i] == '\\')
					 printf("/");
				 else
					 printf("%c",ss[i]);
			 }
			 printf("\n");
		 }
		 else{
		 printf("It's a path in Windows system!\n");
			 for(int i = 0; i < strlen(ss); ++i){
			 if(ss[i] == '/')
					printf("\\");
				else
					printf("%c",ss[i]);
			 }
			 printf("\n");
		 }
	 }
	}
	return 0;
}