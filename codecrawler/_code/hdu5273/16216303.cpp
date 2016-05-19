#include <stdio.h>
#include <algorithm>
using namespace std;
int c[1010][1010]={{0}};
int arr[1010]={9999999};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    int a,b;
    for(int i=999;i>=0;i--)  //è®¡ç®æ¯ä¸ªi-k æå¤å°ç»
    {
        int cnt=0;
        for(int k=i+1;k<=1000;k++)
        {
            if(arr[i]>arr[k])
                cnt++;    
            c[i][k]=c[i+1][k]+cnt; //c[i][k]=c[i+1][k]+cnt[k]   
        }
    }
    while(m--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",c[a][b]);
    }
    return 0;
}
