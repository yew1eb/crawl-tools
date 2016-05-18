#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")
#define STOP system("pause")

using namespace std;

const int MAX_N = 26;
const int MAX_NODE = 500010;

struct NODE{
	int cnt;
	NODE *next[MAX_N], *fail;
	NODE()
	{
		cnt = 0;
		fail = NULL;
		memset(next, 0, sizeof(next));
	}
}*head;

void Build_trie(char *s,NODE *head)
{
	int len = strlen(s);
	for(int i=0; i<len; i++)
	{
		int k = s[i] - 'a';
		if( head->next[k] == NULL )
			head->next[k] = new NODE();
		head = head->next[k];
	}
	head->cnt++;
}

queue<NODE*> q;
void Build_fail(NODE *head)
{
	head->fail = NULL;
	q.push(head);
	while( !q.empty() )
	{
		NODE *now = q.front(); q.pop();
		for(int i=0; i<MAX_N; i++)
			if( now->next[i] )
			{
				NODE *p = now->fail;
				while( p )
				{
					if( p->next[i] )
					{
						now->next[i]->fail = p->next[i];
						break;
					}
					p = p->fail;
				}
				if( p == NULL )
					now->next[i]->fail = head;
				q.push(now->next[i]);
			}
						
	}
}

int AC_find(NODE *head, char *s)
{
	int len = strlen(s), sum = 0;
	NODE* p = head;
	for(int i=0; i<len; i++)
	{
		int k = s[i] - 'a';
		while( p->next[k] == NULL && p != head )
			p = p->fail;
		p = p->next[k] == NULL ? head : p->next[k];
		
		NODE *tmp = p;
		while( tmp != head && tmp->cnt != -1 )
		{
			sum += tmp->cnt;
			tmp->cnt = -1;
			tmp = tmp->fail;
		}
	}
	return sum;
}

char s[1000005];
char ss[100];
int main()
{
	int n, ncases;

	scanf("%d", &ncases);
	
	while( ncases-- )
	{
		head = new NODE();
		scanf("%d", &n);		
		while( n-- )
		{
			scanf("%s", ss);
			Build_trie(ss, head);
		}
		
		Build_fail( head );
		
		scanf("%s", s);
		int sum = AC_find( head, s);
		printf("%d\n", sum);
	}

return 0;
}