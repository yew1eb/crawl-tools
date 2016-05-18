#include "stdio.h"
#include "string.h"

#define M 100

char source[M], target[M];
int len;
char seq[2*M];
int p;

int stack[M];
int top;

void DFS(int ls, int lt){
	int i;
	char c;
	if(lt == len){
		for(i=0; i<2*len; i++)
			printf("%c ", seq[i]);
		printf("\n");
		return;
	}
	if(ls < len){
		seq[p++] = 'i';
		stack[top++] = source[ls];
		DFS(ls+1, lt);
		top--;
		p--;
	}
	if(top && stack[top-1] == target[lt]){
		seq[p++] = 'o';
		c = stack[--top];
		DFS(ls, lt+1);
		p--;
		stack[top++] = c;
	}
}

void main(){
	freopen("in.txt", "r", stdin);
	while(gets(source)){
		gets(target);
		printf("[\n");
		if((len = strlen(source)) == (int)strlen(target)){
			p = 0;
			top = 0;
			DFS(0, 0);
		}
		printf("]\n");
	}
}