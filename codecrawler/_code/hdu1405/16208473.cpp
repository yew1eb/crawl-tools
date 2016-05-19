#include<stdio.h>
#include<math.h>
#include<string.h>
int a[65536],b[65536];
int main()
{
    int n,i,m,d,j,t,k,c=0;
    while(scanf("%d",&t)!=EOF&&t>1)
    {
        if(c!=0)printf("\n");
        d=1;n=t;j=0;c++;
        memset(a,0,65536);
        memset(b,0,65536);
        if(t>0)
        {
            do
            {
                m=(int)sqrt(n);
                for(i=2;i<=m;i++)
                {
                    if(n%i==0)
                    {
                        if(i!=d){j=j+1;a[j]=1;b[j]=i;d=i;}
                        else a[j]++;
                        
                        break;
                    }
                    
                }     
                if(i>m)
                {
                    if(n==b[j])a[j]++;
                    else{j++;a[j]++;b[j]=n;}
                    break;
                }
                else
                    n=n/i;
            }while(n!=1);
            printf("Case %d.\n",c);     
            for(k=1;k<=j;k++)
                printf("%d %d ",b[k],a[k]);
            printf("\n");
        }
        
        
        
    }
    
    return 0;
}  