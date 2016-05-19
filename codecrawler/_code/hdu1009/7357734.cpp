#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, m;
    int i;
    int f[1005];
    double dj[1005];
    int x[1005];
    int j, k;
    double tot;
    while(scanf("%d%d",&n,&m),n+m!=-2)
    {
         tot=0;
         if(m==0){printf("0.000\n");continue;}
         for(i=1;i<=m;i++)
         {
               scanf("%d%d",&x[i],&f[i]);
               dj[i]=x[i]*1.0/f[i];
         }
         for(i=1;i<m;i++)
         {
            k=i;
            for(j=i+1;j<=m;j++)
               if(dj[k]<dj[j])k=j;
            swap(dj[k],dj[i]);
            swap(f[k],f[i]);
            swap(x[i],x[k]);
         }
         i=1;
         while(n>=f[i]){tot+=x[i];n-=f[i];i++;}
         tot+=dj[i]*n;n=0;
         printf("%.3lf\n",tot);
    }
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
