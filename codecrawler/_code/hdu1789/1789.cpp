# include <stdio.h>
# include <stdlib.h>
# include <string.h>


typedef struct node{
    int dl, sc ;
}node ;
typedef node *pnode ;


node a[1010] ;
int flag[1010] ;

int min(int a, int b){return a<b?a:b ;}
int cmp(const void *a, const void *b)
{
    pnode p = (pnode)a, q = (pnode)b ;
    if (p->sc != q->sc) return q->sc - p->sc ;
    return p->dl - q->dl ;
}


int main ()
{
    int i, j, T ;
    int cur, ans, n ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d", &n) ;
        for (i = 0 ; i < n ; i++)
        {
            scanf ("%d", &a[i].dl) ;
            if (a[i].dl >1010)
                a[i].dl = 1010 ;
        }
        for (i = 0 ; i < n ; i++)
            scanf ("%d", &a[i].sc) ;
        qsort(a, n, sizeof(node),cmp) ;
        ans = 0 ;
        memset (flag, 0, sizeof(flag)) ;
        for (i = 0 ; i < n ;i++)
        {
            for (j = a[i].dl - 1 ; j >= 0 ; j--)
            {
                if (flag[j] == 0)
                {
                    flag[j] = 1 ;
                    break ;
                }
            }
            if (j == -1) ans += a[i].sc ;
        }
        printf ("%d\n", ans) ;
    }
    return 0 ;
}