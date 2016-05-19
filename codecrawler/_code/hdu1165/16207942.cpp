/*Ackermanå½æ°:

å½m=1æ¶ï¼
A(1,n)   = A(0,A(1,n-1)) = A(1,n-1)+1 
             = A(0,A(1,n-2))+1 = A(1,n-2)+2.....
             = A(1,n-n)+n = A(0,1)+n=n+2;
å½m=2æ¶ï¼
A(2,n) = A(1,A(2,n-1)) = A(2,n-1)+2
            = A(1,A(2,n-2))+2=A(2,n-2)+2*2...
            = A(2,n-n)+2*n = 2*n+3;
å½m=3æ¶ï¼
A(3,n) = A(2,A(3,n-1)) = 2*(A(3,n-1)+3;
*/
#include<iostream>
using namespace std;

long Ackermann(long m,long n)
{
    if(n==0)
        return Ackermann(m-1,1);
    else if(m==2)
        return 2*n+3;
    else
        return 2*Ackermann(m,n-1)+3;
}

int main()
{
    long n,m;
    while(scanf("%ld %ld",&m,&n)!=EOF)
    {
        if(m==1)
        {
            printf("%ld\n",n+2);
        }
        else if(m == 2)
        {
            printf("%ld\n",2*n+3);
        }
        else if(m == 3)
        {
            printf("%ld\n",Ackermann(m,n));
        }
    }
    return 0;
}


