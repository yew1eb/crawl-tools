#include<cstring>
#include<complex>
#include<cmath>
#define pi acos(-1.0)
using namespace std;
typedef complex<double>Comp;
double x,y,A,k;
int main()
{
    int i,j;
    while(scanf("%lf%lf%lf%lf",&x,&y,&A,&k)!=EOF)
    {
        A=A*pi/180.0;
        Comp a(x,y);
        Comp b(1-k*cos(A),-k*sin(A));
        Comp c=a/b;
       
        printf("(%.3lf,%.3lf)\n",c.real(),c.imag());
    }
    return 0;
} 