#include <stdio.h>
int main()
{
    int n,a,i;
    scanf("%d",&n);
    while(n--)
    {
        int cnt = 3;
        scanf("%d",&a);
        for(i=0; i<a; i++)
        {
            cnt = (cnt-1)*2;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
