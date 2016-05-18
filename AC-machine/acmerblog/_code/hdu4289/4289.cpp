#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define NN 400

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

int n, m;
int s, e;

int main(void)
{
	while(scanf("%d %d %d %d", &n, &m, &s, &e) != -1)
	{
		s--, e--;
		memset(cap, 0, sizeof(cap));
		for(int i=0;i<n;i++)
		{
			int c;
			scanf("%d", &c);
			cap[i * 2][i * 2 + 1] = c;
		}

		for(int i=0;i<m;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--, v--;
			cap[u * 2 + 1][v * 2] = 2000000000;
			cap[v * 2 + 1][u * 2] = 2000000000;
		}

		memset( deg, 0, sizeof( deg ) );
    	for( int u = 0; u < n * 2; u++ )
       		for( int v = 0; v < n * 2; v++ ) if( cap[u][v] || cap[v][u] )
           		adj[u][deg[u]++] = v;

		printf("%d\n", dinic(n * 2, s * 2, e * 2 + 1));
	}	

	return 0;
}