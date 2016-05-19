#include <iostream>
#include <stdlib.h>
using namespace std;

int a[1000000];

int cmp(const void * x,const void* y)
{
    return (*(int*)x - *(int*)y);
}

int main(void)
{
    int n,i;
    while(cin >> n)
    {
        for(i = 0; i<n; i++)
        {
            cin >> a[i];
        }
        qsort(a,n,sizeof(int),cmp);
        cout << a[(n-1)/2] << endl;
    }

    return 0;
}
