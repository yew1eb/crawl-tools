#include <stdio.h>
#include <string.h>

int a[1000005],b[10005];
int next[10005],n,m;

void getnext()
{
    int i = 0,j = -1;
    next[0] = -1;
    while(i<m)
    {
        if(j == -1 || b[i] == b[j])
        {
            i++;
            j++;
            if(b[i] == b[j])
            next[i] = next[j];
            else
            next[i] = j;
        }
        else
        j = next[j];
    }
}

int kmp()
{
    int i = 0,j = 0;
    while(i<n)
    {
        if(a[i] == b[j])
        {
            if(j == m-1)
            return i-j+1;
            i++;
            j++;
        }
        else
        {
            j = next[j];
            if(j == -1)
            {
                i++;
                j = 0;
            }
        }
    }
    return -1;
}

int main()
{
    int t,i;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i = 0;i<n;i++)
        scanf("%d",&a[i]);
        for(i = 0;i<m;i++)
        scanf("%d",&b[i]);
        if(n<m)
        printf("-1\n");
        else
        {
            getnext();
            printf("%d\n",kmp());
        }
    }

    return 0;
}


