#include <math.h>
#include <stdio.h>
int main()
{
    unsigned int n,x;
    while(~scanf("%u",&n))
    {
        for(x=0;n>1;x++)
        {
            if(x&1)
                n = ceil(n*1.0/2);
            else
                n = ceil(n*1.0/9);
        }
        puts(x&1?"Stan wins.":"Ollie wins.");
    }
    return 0;
}
