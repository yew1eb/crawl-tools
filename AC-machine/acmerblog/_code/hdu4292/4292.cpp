#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// the maximum number of vertices
#define NN 802

// adjacency matrix (fill this up)
// If you fill adj[][] yourself, make sure to include both u->v and v->u.
int cap[NN][NN], deg[NN], adj[NN][NN];

// BFS stuff
int q[NN], prev[NN];

int dinic( int n, int s, int t )
{
    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        int qf = 0, qb = 0;
        prev[q[qb++] = s] = -2;
        while( qb > qf && prev[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prev[v = adj[u][i]] == -1 && cap[u][v] )
                    prev[q[qb++] = v] = u;

        // see if we're done
        if( prev[t] == -1 ) break;

        // try finding more paths
        for( int z = 0; z < n; z++ ) if( cap[z][t] && prev[z] != -1 )
        {
            int bot = cap[z][t];
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
                bot = min(bot, cap[u][v]);
            if( !bot ) continue;

            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
            {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }

    return flow;
}

int n, f, d;

int main(void)
{
	while(scanf("%d %d %d", &n, &f, &d) != -1)
	{
		memset(cap, 0, sizeof(cap));
		int start = f + d + n * 2, end = f + d + 1 + n * 2;
		int foodBase = n * 2;
		int drinkBase = foodBase + f;

		for(int i=0;i<n;i++) cap[i][n + i] = 1;
		for(int i=0;i<f;i++)
		{
			int curFood;
			scanf("%d", &curFood);
			cap[start][foodBase + i] = curFood;
		}
		for(int i=0;i<d;i++)
		{
			int curDrink;
			scanf("%d", &curDrink);
			cap[drinkBase + i][end] = curDrink;
		}

		for(int i=0;i<n;i++)
		{
		 	char str[201];
			scanf("%s", str);
			for(int j=0;j<f;j++) if(str[j] == 'Y') cap[foodBase + j][i] = 1;
		}

		for(int i=0;i<n;i++)
		{
			char str[201];
			scanf("%s", str);
			for(int j=0;j<d;j++) if(str[j] == 'Y') cap[i + n][drinkBase + j] = 1;
		}

 		memset( deg, 0, sizeof( deg ) );
    	for( int u = 0; u <= end; u++ )
        	for( int v = 0; v <= end; v++ ) if( cap[u][v] || cap[v][u] )
            	adj[u][deg[u]++] = v;
		

		printf( "%d\n", dinic( end + 1, start, end ) );
	}

	return 0;
}