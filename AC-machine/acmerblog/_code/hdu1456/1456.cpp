#include <stdio.h>
#include <string.h>

int n, m, t;
struct Q
{
    int star;
    int end;
    int p;
} ti[25];
int max;
int nb[8];
int judge(int num)
{
    for (int i = ti[num].star; i < ti[num].end; i ++)
    {
	nb[i] += ti[num].p;
	if (nb[i] > n)
	    return 0;
    }
    return 1;
}
void dfs(int num, int sum)
{
    if (num == t)
    {
	if (max < sum)
	{
	    max = sum;
	}	  
	return;	
    }
    int save[8];
    dfs(num + 1, sum);
    for (int i = 0; i < m; i++)
    {
	save[i] = nb[i];
    }
    if (judge(num))
    {	
	dfs(num + 1, sum + (ti[num].end - ti[num].star) * ti[num].p);
    }
    for (int i = 0; i < m ; i ++)
    {
	nb[i] = save[i];
    }
}
int main()
{
    while (scanf("%d%d%d", &n, &m, &t) != EOF && n || m || t)
    {
	max = 0;
	memset(nb, 0, sizeof(nb));
	memset(ti, 0, sizeof(ti));
	for (int i = 0; i < t; i ++)
	{
	    scanf("%d%d%d", &ti[i].star, &ti[i].end, &ti[i].p);

	}
	dfs(0, 0);
	printf("%d\n", max);
    }
    return 0;
}