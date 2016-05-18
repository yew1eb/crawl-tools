# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int l, w ;
}node ;


node a[5010] ;
int dp[5010] ;


int cmp(const void *a, const void *b)
{
    node *p = (node*)a, *q = (node*)b ;
    if (p->l != q->l) return q->l - p->l ;
    return q->w - p->w ;
}


int main ()
{
    int T, n, i, j, ans ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d", &n) ;
        for (i = 0 ; i < n ; i++)
            scanf ("%d%d", &a[i].l, &a[i].w) ;
        qsort(a, n, sizeof(node), cmp) ;
        ans = -1, dp[0] = 1 ;
        for (i = 1 ; i < n ; i++)
        {
            dp[i] = 1 ;
            for (j = 0 ; j < i ; j++)
            {
                if (a[j].w < a[i].w && dp[j]+1 > dp[i])
                    dp[i] = dp[j] + 1 ;
            }
            if (dp[i] > ans) ans = dp[i] ;
        }
        printf ("%d\n", ans) ;
    }
    return 0 ;
}