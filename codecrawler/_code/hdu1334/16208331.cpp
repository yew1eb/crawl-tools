#include <stdio.h>

int main()
{
    int a,b,c,d;
    int A,B,C,D;
    for(a = 6; a<=200; a++)
    {
        for(b = 2; b<a-2; b++)
        {
            for(c = b+1; c<a-1; c++)
            {
                if(c<b)
                    continue;
                for(d = c+1; d<a; d++)
                {
                    if(d<c)
                        continue;
                    if(a*a*a == b*b*b + c*c*c + d*d*d)
                    {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                    }
                }
            }
        }
    }

    return 0;
}
