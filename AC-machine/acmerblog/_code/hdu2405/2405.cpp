#include "stdio.h"

typedef struct _Bskt{
	int a, b, c;
	int pre;
}Bskt, *pBskt;

Bskt bskt[1000];
int st, ed;

int BFS(int a, int b, int c){
	Bskt k;
	if(a == b && b == c) return -1;
	if((a+b+c)%3) return -1;
	bskt[0].a = a;
	bskt[0].b = b;
	bskt[0].c = c;
	bskt[0].pre = -1;
	st = 0; ed = 1;

	while(st<ed){
		if(ed>990) return -1;
		k = bskt[st];
		//a
		if(k.b>=k.a && !(k.a+k.a==a && k.b-k.a==b && k.c==c)){
			bskt[ed].a = k.a + k.a;
			bskt[ed].b = k.b - k.a;
			bskt[ed].c = k.c;
			bskt[ed].pre = st;
			if(bskt[ed].a == bskt[ed].b && bskt[ed].b == bskt[ed].c) return ed;	
			ed++;
		}
		if(k.c>=k.a && !(k.a+k.a==a && k.b==b && k.c-k.a==c)){
			bskt[ed].a = k.a + k.a;
			bskt[ed].b = k.b;
			bskt[ed].c = k.c - k.a;
			bskt[ed].pre = st;
			if(bskt[ed].a == bskt[ed].b && bskt[ed].b == bskt[ed].c) return ed;
			ed++;
		}
		//b
		if(k.a>=k.b && !(k.a-k.b==a && k.b+k.b==b && k.c==c)){
			bskt[ed].a = k.a - k.b;
			bskt[ed].b = k.b + k.b;
			bskt[ed].c = k.c;
			bskt[ed].pre = st;
			if(bskt[ed].a == bskt[ed].b && bskt[ed].b == bskt[ed].c) return ed;
			ed++;
		}
		if(k.c>=k.b && !(k.a==a && k.b+k.b==b && k.c-k.b==c)){
			bskt[ed].a = k.a;
			bskt[ed].b = k.b + k.b;
			bskt[ed].c = k.c - k.b;
			bskt[ed].pre = st;
			if(bskt[ed].a == bskt[ed].b && bskt[ed].b == bskt[ed].c) return ed;
			ed++;
		}
		//c
		if(k.a>=k.c && !(k.a-k.c==a && k.b==b && k.c+k.c==c)){
			bskt[ed].a = k.a - k.c;
			bskt[ed].b = k.b;
			bskt[ed].c = k.c + k.c;
			bskt[ed].pre = st;
			if(bskt[ed].a == bskt[ed].b && bskt[ed].b == bskt[ed].c) return ed;
			ed++;
		}
		if(k.b>=k.c && !(k.a==a && k.b-k.c==b && k.c+k.c==c)){
			bskt[ed].a = k.a;
			bskt[ed].b = k.b - k.c;
			bskt[ed].c = k.c + k.c;
			bskt[ed].pre = st;
			if(bskt[ed].a == bskt[ed].b && bskt[ed].b == bskt[ed].c) return ed;
			ed++;
		}
		st++;
	}

	return -1;
}

void display(int pre){
	if(pre==-1)
		return;
	display(bskt[pre].pre);
	printf("%4d %3d %3d\n", bskt[pre].a, bskt[pre].b, bskt[pre].c);
}

void main(){
	int a, b, c, k;
	freopen("in.txt", "r", stdin);
	while(scanf("%d %d %d", &a, &b, &c)!=EOF){
		if((k=BFS(a, b, c))>=0)
			display(k);
		else
			printf("%4d %3d %3d\n", a, b, c);
		printf("============\n");
	}
}