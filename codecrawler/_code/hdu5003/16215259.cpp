#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--){


        int n,a[500 + 5];
        scanf("%d",&n);double sum=0;

        for(int i=1;i<=n;i++){ scanf("%d",&a[i]);


        }
        sort(a+1,a+n+1,cmp);
         for(int i=1;i<=n;i++) sum += ( pow( 0.95, (i-1) ) *a[i] );
        printf("%.10lf\n",sum);

    }
    return 0;
}
