#include<iostream>
using namespace std; 
int main() 
{
     int a;
     while(scanf("%d",&a)!=EOF)
          printf("%d\n",a*a*a*(a*a*a-1)/2-3*a*a*(a-1));
     return 0;
}