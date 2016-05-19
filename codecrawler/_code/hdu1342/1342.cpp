# include <stdio.h>


int k ;
int num[20] ;
int ans[6] ;


void dfs(int idx, int n)
{
    int i ;
    if (n == 6)
    {
        for(i = 0 ; i < n ; i++)
            if (i == 0) printf("%d",ans[i]) ;
            else printf (" %d", ans[i]) ;
        printf ("\n") ;
        return ;
    }
    for (i = idx ; i < k + n - 5; i++)
    {
        ans[n] = num[i] ;
        dfs(i+1,n+1) ;
    }
}


int main ()
{
    int i ;
    int flag = 0 ;
    while (~scanf ("%d", &k),k)
    {
        for(i=0;i<k;i++) scanf("%d", &num[i]) ;
        if (flag == 0) flag = 1;
        else printf ("\n") ;
        dfs (0,0) ;
    }
    return 0 ;
}