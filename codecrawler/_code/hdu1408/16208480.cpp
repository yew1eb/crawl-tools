#include<stdio.h>
double D=0,V=0;
int T=0;
int main()
{
    while(scanf("%lf%lf",&V,&D)!=EOF)
    {
        T=0;
        for(int cnt=1;V>0;cnt++)
        {
            if(V-(cnt*D) <= 0)
            {
                while(V>0.0000001) // V>0 is wrong answer
                {
                    V-=D;
                    T++;
                }
                break;
            }
            V-=cnt*D;
            T+=cnt;
            T++;
        }
        printf("%d\n",T);
    }
    return(0);
}
