#include<stdio.h>
#define MAXN 10000
#include<string.h>
int a[MAXN], b[MAXN], c[MAXN];
int lena, lenc;

void work(int x)
{
     int y;
     memset(a,0,sizeof(a));
     memset(b,0,sizeof(b));
     a[1]=1;b[1]=1;
     y =0;
     lena=1;
     for(int j=3;j<=x;j++)
  
  { 
     for(int i=1;i<=lena;i++)
     {
         c[i]= a[i]+b[i]+y;
         y = c[i] /10;
         c[i] %=10;
     }
     lenc=lena;
     while(y>0){lenc++;c[lenc]=y%10;y/=10;}
     for(int i=1;i<=lena;i++)  b[i]= a[i];
     for(int i=1;i<=lenc;i++)  a[i]= c[i];
     lena=lenc;
  }
  
}
     
         
void print()
{
     for(int i=lenc;i>=1;i--)
       printf("%d",c[i]);
     printf("\n");
}

int main()
{
    int n, x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        if(x<=2) printf("1\n");
        else
        {
           work(x);
           print();
        }
    }
    return 0;
} 
