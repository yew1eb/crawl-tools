#include <cstdio>
#include <cstring>
const int MAX = 10240;
const int ELE[] = { 2, 4, 5, 8, 10 };
int main()
{
	bool visited[MAX];
	int i, a, b;
   while(scanf("%d %d", &a, &b) != EOF) {
	   bool quick = false;
	   for(i = 0; i < 5; i++)
		   if(b % ELE[i] == 0 && a % ELE[i] != 0)
			   { quick = true; break; }
      if(quick) { printf("0/n"); continue; }
		int n = 0;
		memset(visited, false, sizeof(visited));
		for(i = 1; true; i++) {
			n = (10*n+a) % b;
			if(n == 0) { printf("%d/n", i); break; }
			else if(visited[n] || i >= b) { printf("0/n"); break; }
			else visited[n] = true;
		}
	}
	return 0;
}