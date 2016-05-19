#include<stdio.h>
#include<stdlib.h>
#include<math.h>
bool is_prime(int n)
{
     int i;
     n=n*n+n+41;
     if(n<2) return false;
     if(n==2) return true;
     for(i=2;i<=sqrt(n);i++)
        if(n%i==0) return false;
     return true;
}

int main()
{
    int x, y, i;
    int t;
    scanf("%d%d",&x,&y);
    while(!(x==0 && y==0) )
    {      
        t=0;
        for(i=x;i<=y;i++)
        {   
            if( is_prime(i)==false) {printf("Sorry\n");t=1;break; }
        }
        if(t==0) printf("OK\n");
        scanf("%d%d",&x,&y);
    }
    //system("pause");
    return 0;
}
