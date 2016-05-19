/*
5146 
å¤æ­åºåä¸æ¯åæ ä¸å¥æ°ä¸å¶æ°ä½çåä¸å 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int a[1001];
int main()
{
    int t,n,sum,i,j,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i&1==1)
                sum+=a[i];
            else
                sum-=a[i];
        }    
        f=0;
        for(i=0,j=n-1;i<=j;i++,j--)
        {
            if(a[i]!=a[j])
            {
                f=1;
                break;            
            }        
        }
        if(sum==0&&f==1)
            printf("Yes\n");
        else
            printf("No\n");    
    }
    return 0;
}