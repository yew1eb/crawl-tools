# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int a, b ;
}node ;


node pt[500] ;


int min(int a, int b){return a<b?a:b;}
int max(int a, int b){return a>b?a:b;}
int cmp(const void *a, const void *b)
{
    node *p = (node*)a, *q = (node*)b ;
    if (p->a != q->a) return p->a - q->a ;
    return q->b - p->b ;
}


int main ()
{
    int i, T ;
    int n, aa, bb, a, b ;
    int ans, cur ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d", &n);
        for (i = 0; i < n ; i++)
        {
            scanf ("%d%d", &aa, &bb) ;
            a = (min(aa,bb)+1) / 2 ;
            b = (max(aa,bb)+1) / 2 ;
            pt[i*2].a = a, pt[i*2].b = 1 ;
            pt[i*2+1].a = b, pt[i*2+1].b = -1 ;
        }
        qsort(pt, n*2, sizeof(node), cmp) ;
        ans = cur = 0 ;
        for (i = 0 ; i < 2*n ; i++)
        {
            cur += pt[i].b ;
            ans = max(ans, cur) ;
        }
        printf ("%d\n", ans*10) ;
    }
    return 0 ;
}