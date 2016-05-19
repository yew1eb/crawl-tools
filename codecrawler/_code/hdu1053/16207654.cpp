#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[30];
char s[1001];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    while(gets(s))
    {
        if(strcmp(s,"END")==0)
        break;
        int m,n,i,j,k;
        m=strlen(s);
        memset(a,0,sizeof(a));
        for(i=0;i<m;i++)
        if(s[i]=='_')
        a[0]++;
        else
        a[s[i]-'A'+1]++;
        sort(a,a+27,cmp);
        for(i=0;;i++)
        if(a[i]==0)
        break;
        n=i;
        int t=0;
        for(i=n-1;i>0;i--)
        {
            a[i-1]=a[i]+a[i-1];
            t+=a[i-1];
            sort(a,a+i,cmp);
        }
        if(n==1)
        t=a[0];
        printf("%d %d %.1f\n",8*m,t,8.0*m/t);
    }
    return 0;
}
