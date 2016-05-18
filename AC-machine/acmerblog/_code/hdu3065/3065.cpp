#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
#define N 2000009
char a[N];
char str[1009][59];
struct node {
	int cnt;
	node *fail, *next[28];
	node () {
		cnt = 0;
		fail = NULL; memset (next, NULL, sizeof(next));
	}
};
node *root, *que[N];
void add (char a[], int k) {
	node *p = root;
	for (int i = 0; a[i]; ++i) {
		int v = a[i] - 'A';
		if(p->next[v] == NULL) 
			p->next[v] = new node();
		p = p->next[v];
	}
	p->cnt = k;
}

void build () {
	int tail = 0, head =0;
	que[tail++] = root;
	while (head < tail) {
		node *p = que[head++];
		for (int i = 0; i < 28; ++i) {
			if(p ->next[i] != NULL) {
				que[tail++] = p->next[i];
				if(p == root) {
					p->next[i]->fail =root;
				}else {
					node *temp = p->fail;
					p->next[i]->fail = root;
					while (temp != NULL) {
						if(temp->next[i] != NULL) {
							p->next[i]->fail = temp->next[i];
							break;
						}
						temp = temp->fail;
					}
				}
			}
		}
	}
}
struct no {
	char a[59];
	int num;
}pe[10009];
void query(char a[]) {
	node *p = root;
	for (int i = 0; a[i]; ++i) {
		int v = a[i] - 'A';
		if(v > 26 || v < 0) v = 26;
		while(p->next[v] ==NULL && p!= root) {
			p = p->fail;
		}
		p = p->next[v];
		if(p == NULL) p = root;
		node *temp = p;
		while (temp != root ) {
			if(temp->cnt) {
				pe[temp->cnt].num++;
			}
			temp = temp->fail;
		}
	}

}

void cal(node *p) {
	if(p == NULL) return;
	for (int i = 0; i < 27; ++i) 
		if(p->next[i] != NULL) 
			cal(p->next[i]);
	delete p;
}
int cmp(no a, no b) {
	return strcmp(a.a, b.a) < 0;
}
int main () {
	int n;
	while (scanf ("%d", &n) != EOF) {
		root = new node;
		for (int i = 1; i <= n; ++i) {
			scanf ("%s", pe[i].a);
			pe[i].num = 0;
			add(pe[i].a, i);
		}
		build();
		scanf ("%s", a);
		query(a);
		//sort(pe, pe + n, cmp);
		for (int i = 1; i <= n; ++i) {
			if(pe[i].num) 
				printf ("%s: %d\n", pe[i].a, pe[i].num);
		}
		cal(root);
	}
}