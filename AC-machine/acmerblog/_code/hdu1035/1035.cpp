#include <stdio.h>
#include <string.h>

#define MAX_N 11

char map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int n, m;
int sx, sy;
int step, loopStep;

bool dfs(int x, int y, int* s) {
	
	if (x < 1 || x > n || y < 1 || y > m) {
		return false;
	}else if (visited[x][y] != -1) {
		loopStep = visited[x][y];
		return  true;
	}


	visited[x][y] = (*s)++;
	if (map[x][y] == 'N') {
		return dfs(x -1, y, s);
	} else if (map[x][y] == 'S') {
		return dfs(x + 1, y, s);
	} else if (map[x][y] == 'W') {
		return dfs(x, y - 1, s);
	} else if (map[x][y] == 'E') {
		return dfs(x, y + 1, s);
	}
	

	return false;
}

int main() {
	int i, j;

	while (scanf("%d%d", &n, &m) != EOF && n || m) {
		scanf("%d", &sy);
		
		for (i = 1; i <= n; i++) {
			scanf("%s", map[i] + 1);
		}

		sx = 1;
		loopStep = step = 0;
		memset(visited, -1, sizeof(visited));
		if (dfs(sx, sy, &step)) {
			printf("%d step(s) before a loop of %d step(s)\n", loopStep, step - loopStep); 
		} else {
			printf("%d step(s) to exit\n", step);
		}
	}

	return 0;
}