#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1000010
#define max(a,b) (a)>(b)?(a):(b)


struct node {
    
    int x,in;
}r[MAX],qu[MAX];
__int64 sum[MAX],ans;
int head,tail;
int n,p,k,mmin[MAX];


int cmp(node a,node b) {
    
    if (a.x == b.x) return a.in < b.in;
    else return a.x < b.x;
}
void Solve_AC() {
	
	int i,j;
	head = 0,tail = 1;


	for (i = 1; i <= n; ++i) {
		
		if (tail > head) mmin[r[i].in] = -1;
		else mmin[r[i].in] = qu[tail].in;


		while (tail <= head 
			&& r[i].in < qu[head].in)  head--;


		qu[++head] = r[i];
		while (tail <= head && r[i + 1].x - qu[tail].x > k)
			tail++;
	}
	
	
	for (i = 1; i <= n; ++i) {
		
		if (sum[i] % p <= k) ans = max(ans,sum[i] / p);
		if (mmin[i] == -1 || mmin[i] >= i) continue;
		ans = max(ans,(sum[i] - sum[mmin[i]]) / p);
	}
}


int main()
{
    int i,j,t,cas = 0;
    
    
    scanf("%d",&t);
    while (t--) {
        
        scanf("%d%d%d",&n,&p,&k);
        for (i = 1; i <= n; ++i) {
            
            scanf("%d",&sum[i]);
            r[i].in = i;
            sum[i] +=  sum[i-1];
            r[i].x = sum[i] % p;
        }
        
        
        sort(r+1,r+1+n,cmp);
		ans = -1,Solve_AC();
        printf("Case %d: %I64d\n",++cas,ans);
    }
}