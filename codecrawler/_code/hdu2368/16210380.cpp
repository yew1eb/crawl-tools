#include <cstdio>
int main()
{
    int cas = 0;
    int r, w, l;
    while(scanf("%d",&r) && r)
    {
        scanf("%d%d",&w,&l);
        printf("Pizza %d ",++cas);
        if(4*r*r-w*w < l*l)
        {
            printf("does not fit on the table.\n");
        }
        else
            printf("fits on the table.\n");
    }
    return 0;
}