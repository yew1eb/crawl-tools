#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXNODE 2
#define MAXSIZE 300000
#define INF (1<<29)
#define min(a,b) ((a)<(b)?(a):(b))


int n,m,issub[20],len;
string str[20],virus;


struct ACnode {
	
	int flag,in;
	ACnode *next[MAXNODE],*fail,*father;
};
struct Auto_AC {
	
	int Index[20],ans;
	int dist[100][100],spfaqu[MAXSIZE];
	int temp[MAXSIZE],in[MAXSIZE];
	int total,head,tail,dp[20][2000];
	ACnode *p,*q,*root;
	ACnode *qu[MAXSIZE],tree[MAXSIZE];
	
	
	ACnode *CreateNode() {
		
		tree[total].flag = 0;
		tree[total].in = total;
		tree[total].next[0] = NULL;
		tree[total].next[1] = NULL;
		return &tree[total++];
	}
	void Initial() {
		
		total = 0,ans = INF;
		root = CreateNode();
		root->fail = root;
		for (int i = 0; i < n; ++i) {
		
			for (int j = 0; j < (1<<n); ++j)
				dp[i][j] = INF;
			dp[i][1<<i] = str[i].size();
		}
	}
	int GetHash(char c) {
		
		return c - '0';
	}
	void Insert(string str,int in,int kind) {
		
		p = root;
		for (int i = 0; str[i]; ++i) {
			
			int k = GetHash(str[i]);
			if (p->next[k] == NULL)
				p->next[k] = CreateNode();
			p = p->next[k];
		}
		
		
		if (kind == 1) p->flag = 1;
		else Index[in] = p->in;
	}
	void Build_AC() {
		
		qu[head++] = root;
		while (tail < head) {
			
			p = qu[tail++];
			for (int k = 0; k < MAXNODE; ++k)
				if (p->next[k]) {
					
					if (p == root) p->next[k]->fail = root;
					else p->next[k]->fail = p->fail->next[k];
					qu[head++] = p->next[k];
					p->next[k]->flag |= p->next[k]->fail->flag;
				}
				else {
					
					if (p == root) p->next[k] = root;
					else p->next[k] = p->fail->next[k];
				}
		}
		
	}
	void Spfa_ForDist(int s) {

		int i,j,k,u,v,ndis;
		int head = 0,tail = 0;


		temp[s] = 0;
		spfaqu[head++] = s,in[s] = 1;


		while (tail < head) {

			u = spfaqu[tail++]; in[u] = 0;
			for ( k = 0; k < MAXNODE; ++k)
				if (!tree[u].next[k]->flag) {

					ndis = temp[u] + 1;
					v = tree[u].next[k]->in;
					if (ndis < temp[v]) {

						temp[v] = ndis;
						if (in[v] == 0) 
							spfaqu[head++] = v,in[v] = 1;
					}
				}
		}
	}
	void CountDist() {
			
		int i,j;
		for (i = 0; i < n; ++i) {
		
			for (j = 0; j <= total; ++j)
				in[j] = 0,temp[j] = INF;
			Spfa_ForDist(Index[i]);
			for (j = 0; j < n; ++j)
				dist[i][j] = temp[Index[j]];
		}
	}
	int Solve_DP() {

		int i,j,k,nst,ndis;
		

		for (i = 1; i < (1<<n); ++i)
			for (j = 0; j < n; ++j)
				if (i & (1<<j)) for (k = 0; k < n; ++k)
					if (!(i & (1<<k)) && dist[j][k] != INF) {

						nst = i | (1<<k);
						ndis = dp[j][i] + dist[j][k];
						dp[k][nst] = min(dp[k][nst],ndis);
					}


		for (i = 0; i < n; ++i)
			ans = min(ans,dp[i][(1<<n)-1]);
		return ans;
	}
}AC;
int cmp(string s1,string s2) {
	
	return s1.size() > s2.size();
}
void Solve_Sub() {
	
	int i,j,k = n;
	
	
	sort(str,str+n,cmp);
	memset(issub,0,sizeof(issub));
	for (i = 0; i < n; ++i)
		for (j = i + 1; j <= n; ++j)
			if (str[i].find(str[j]) != -1) 
				issub[j] = 1;
	for (n = 0,i = 0; i < k; ++i)
		if (issub[i] == 0) str[n++] = str[i];
}


int main()
{
	int i,j,k;
	
	
	while (cin>>n>>m,n + m) { 
		
		for (i = 0; i < n; ++i) 
			cin>>str[i];
		Solve_Sub(),AC.Initial();
		for (i = 0; i < n; ++i) 
			AC.Insert(str[i],i,0);
		for (i = 0; i < m; ++i)
			cin>>virus,AC.Insert(virus,i,1);
		
		
		AC.Build_AC();
		AC.CountDist();
		printf("%d\n",AC.Solve_DP());
	}
}