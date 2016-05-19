#include<stdio.h>
struct s
{
    int ran[2];
    int sum;
    int cold;
};
int main()
{
    struct s r[200], t;
    int n, j, i;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d", &r[i].ran[0], &r[i].ran[1]);
            r[i].sum=r[i].ran[0]-r[i].ran[1];
            r[i].cold=i;
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(r[i].sum<r[j].sum)
                {
                    t=r[i];
                    r[i]=r[j];
                    r[j]=t;
                }
                if(r[i].sum==r[j].sum)
                {
                    if(r[i].ran[1]>r[j].ran[1])
                    {
                        t=r[i];
                        r[i]=r[j];
                        r[j]=t;
                    }
                    if(r[i].ran[1]==r[j].ran[1]&&r[i].cold>r[j].cold)
                    {
                        t=r[i];
                        r[i]=r[j];
                        r[j]=t;
                    }
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d", r[i].cold);
            if(i!=n-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}