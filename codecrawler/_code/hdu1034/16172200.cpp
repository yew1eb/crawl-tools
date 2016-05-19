#include<cstdio>
using namespace std;
int main()
{
    int a[100],n,k,p,t,i,j;
    while(scanf("%d",&n),n)
    {
        k=0;
        for(i=0;i<n;i++)  //æ¥åæ°æ®
        scanf("%d",&a[i]);
        while(1)
        {
            k++;
            t=a[n-1]/2;    //tä¸ºæ¬è½® a[i]è¦å å¤å°
            for(i=0;i<n;i++)  //å¾ªç¯
            {
                p=a[i]/2;    
                a[i]=a[i]/2+t;  
                t=p;
                if(a[i]&1)  //ä¸ºå¥æ°å 1
                ++a[i];
            }
            t=a[0];
            for(i=0;t==a[i]&&i<n;i++);  //å¤æ­æ¯å¦å¨é¨ç¸ç­
            if(i==n)
                break;
        }
        printf("%d %d\n",k,t);
    }
    return 0;
}
