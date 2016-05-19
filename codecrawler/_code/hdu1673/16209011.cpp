#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[25];

int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        int i,t,sum=0;
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+m);
        sum=2*(arr[m-1]-arr[0]);
         printf("%d\n",sum);
    }    
    return 0;
}   