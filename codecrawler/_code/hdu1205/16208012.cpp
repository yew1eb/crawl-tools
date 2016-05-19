/* 
hdu: eat suger
*/
#include<stdio.h>
#include<stdlib.h>

__int64 T=0,N=0,Num=0,Sum=0,Pre=0;

/*for test*/
int test()
{
    return(0);
}

/*initialize the var*/
int InitVar()
{
    Sum=0;
    Pre=0;
    return(0);
}


/*main process*/
int MainProc1()
{
    while(scanf("%I64d",&T)!=EOF)
    {
        while(T--)
        {
            InitVar();
            scanf("%I64d",&N);
            while(N--)
            {
                scanf("%I64d",&Num);
                Sum+=Num;
                if(Pre<Num)
                {
                    Pre=Num;
                }
            }
            Sum-=Pre;
            if(Pre-Sum>=2)
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
        }
    }
    return(0);
}

int main()
{
    MainProc1();
    return(0);
}


