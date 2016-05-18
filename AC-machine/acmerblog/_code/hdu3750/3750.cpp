#include<stdio.h>  
#define eps 1e-6  
double sum;  
void expect(int now,int n,double s)  
{  
    int d=n/2;  
    if(n==0) return;  
    sum+=s*now/n;  
    s=s*(1-1.0/n);  
    if(n%2)  
        expect(now+1,d,s);  
    else  
    {  
        expect(now+1,d,s*d/(n-1));  
        expect(now+1,d-1,s*(d-1)/(n-1));  
    }  
}  
int main()  
{  
    int n,s;  

    while(~scanf("%d",&n))  
    {  
        sum=0.0;  
        expect(1,n,1.0);  
        printf("%.2lf\n",sum+eps);  
    }  
    return 0;  
}