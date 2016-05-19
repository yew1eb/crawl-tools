#include<iostream>
using namespace std;
int main()
{
    int n;
    int sum,t,k;
    while(cin>>n)
    {
         k=n*n*n;
        sum=(k-1)*(k)/2;                       //æ»å±æçä¸ªæ°

        t=(n-1)*(n*n)+n*2*n*(n-1);             //4ä¸ªç¸åé¡¶ç¹çä¸ªæ°

        printf("%d\n",sum-t);

    }
    return 0;
}