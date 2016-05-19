#include "stdio.h"
#include "string.h"

#define MIN(a, b) ((a)<(b)?(a):(b))

int n, m;
int map[100][100];
int over[100][100];
int h;
int all;

int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void init(){
	int i, j;
	h = 0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]>h)
				h = map[i][j];
		}
}

int border(int* u, int* v, int l){
	int i, j;

	for(i=0; i<n; i++){
		if(!over[i][0] && l >= map[i][0]){
			*u = i;
			*v = 0;
			return 1;
		}
		if(!over[i][m-1] && l >= map[i][m-1]){
			*u = i;
			*v = m-1;
			return 1;
		}
	}

	for(j=0; j<m; j++){
		if(!over[0][j] && l >= map[0][j]){
			*u = 0;
			*v = j;
			return 1;
		}
		if(!over[n-1][j] && l >= map[n-1][j]){
			*u = n-1;
			*v = j;
			return 1;
		}
	}

	return 0;
}

void DFS(int u, int v, int l){
	int i;
	int nu, nv;
	over[u][v] = 1;
	all--;
	for(i=0; i<4; i++){
		nu = u + d[i][0];
		nv = v + d[i][1];
		if(nu>=0 && nv>=0 && nu<n && nv<m && map[nu][nv]<=l && !over[nu][nv])
			DFS(nu, nv, l);
	}
}

void DFS_N(int u, int v){
	int i;
	int nu, nv;
	over[u][v] = 1;
	all--;
	for(i=0; i<4; i++){
		nu = u + d[i][0];
		nv = v + d[i][1];
		if(nu>=0 && nv>=0 && nu<n && nv<m && !over[nu][nv])
			DFS_N(nu, nv);
	}
}

void main(){
	int c;
	int i, j;
	int u, v;
	int k;
	int mark;

	freopen("in.txt", "r", stdin);

	c = 0;
	while(scanf("%d %d", &n, &m), n+m){
		c++;
		init();
		all = 0;
		for(k=0; k<h; k++){
			memset(over, 0, sizeof(over));
			all = n*m;
			while(border(&u, &v, k))
				DFS(u, v, k);
			mark = 0;
			for(i=0; i<n; i++){
				for(j=0; j<m; j++)
					if(!over[i][j]){
						mark = 1;
						break;
					}
				if(mark)
					break;
			}
			if(mark)
				DFS_N(i, j);
			if(all)
				break;
		}
		
		if(all)
			printf("Case %d: Island splits when ocean rises %d feet.", c, k);
		else
			printf("Case %d: Island never splits.", c);
		printf("\n");
	}
}